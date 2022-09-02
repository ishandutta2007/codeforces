#include <bits/stdc++.h>


using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair

int p = 1000000007;


int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=p) s-=p;
    return s;
}

int sub(int a, int b) {
    int s = (a+p-b);
    if (s>=p) s-=p;
    return s;
}

int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, p-2);
}

/*struct DSU {
    vector<int> sz;
    vector<int> parent;

    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    DSU(int n) {
        sz.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) make_set(i);
    }
};*/

/*const int N = 1200000;

vector<int> facs(N), invfacs(N);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<N; i++) facs[i] = mul(facs[i-1], i);
    invfacs[N-1] = inv(facs[N-1]);
    for (int i = N-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C(int n, int k)
{
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}*/

struct SegTree
{

    vector<int> t;
    int n;

    void build(vector<int> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, int add) {
        if (l > r)
            return;
        if (l == tl && r == tr) {
            t[v] += add;
        } else {
            int tm = (tl + tr) / 2;
            update(v*2, tl, tm, l, min(r, tm), add);
            update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
        }
    }

    int get(int v, int tl, int tr, int pos) {
        if (tl == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return t[v] + get(v*2, tl, tm, pos);
        else
            return t[v] + get(v*2+1, tm+1, tr, pos);
    }

    SegTree(vector<int> a)
    {
        t.resize(4*a.size());
        n = a.size();
        build(a, 1, 0, n-1);
    }

    int get_pos(int pos)
    {
        return get(1, 0, n-1, pos);
    }

    void add_on(int l, int r, int x)
    {
        /*cout<<"Adding "<<x<<" On "<<l<<' '<<r<<endl;
        for (int i = 0; i<n; i++) cout<<get_pos(i)<<' ';
        cout<<endl;*/

        if (l>r) return;

        update(1, 0, n-1, l, r, x);

        /*for (int i = 0; i<n; i++) cout<<get_pos(i)<<' ';
        cout<<endl;*/
    }

};


void solve()
{
    //cout<<"NEXT TEST"<<endl;
    string s;
    cin>>s;
    int n = s.size();
    vector<pair<int, char>> a;
    char pr = s[0];
    int cur = 0;
    int st = 0;
    vector<int> A;

    for (int i = 1; i<n; i++)
    {
        if (s[i]==pr)
        {
            cur++;
        }
        else
        {
            if (cur>0) {a.push_back(mp(cur, pr)); A.push_back(st);}
            cur = 0; pr = s[i]; st = i;
        }
    }
    if (cur>0) {a.push_back(mp(cur, pr)); A.push_back(st);};



    //for (auto it: a) cout<<it.first<<' '<<it.second<<endl;

    vector<int> len;
    for (auto it: a) len.push_back(it.first);

    /*cout<<"len: ";
    for (auto it: len) cout<<it<<' ';
    cout<<endl;*/

    if (a.size()==0)
    {
        cout<<1<<endl;
        cout<<1<<' '<<n<<endl;
        return;
    }

    int m = a.size();
    vector<int> nxt(m);
    vector<int> prv(m);
    for (int i = 0; i<m; i++) nxt[i] = i+1;
    for (int i = 0; i<m; i++) prv[i] = i-1;
    nxt[m-1] = -1;
    prv[0] = -1;


    vector<int> cnt(26);
    for (auto it: a) cnt[it.second-'a']+=it.first;



    set<pair<int, int>> bruh;
    for (int i = 0; i<26; i++) if (cnt[i]!=0) bruh.insert(mp(cnt[i], i));

    vector<set<pair<int, int>>> where_del(26);
    for (int i = 0; i<m-1; i++) if (a[i].second!=a[i+1].second)
    {
        where_del[a[i].second-'a'].insert(mp(i, i+1));
        where_del[a[i+1].second-'a'].insert(mp(i, i+1));
    }


    vector<pair<int, int>> deletes;

    while (bruh.size()>1)
    {

        auto it = *prev(bruh.end());
        int del = it.second;


        while (true)
        {
            it = *where_del[del].begin();
            where_del[del].erase(where_del[del].begin());
            if (a[it.first].first!=0 && a[it.second].first!=0) break;
        }



        int x = it.first; int y = it.second;

        bruh.erase(mp(cnt[a[x].second-'a'], a[x].second-'a'));
        bruh.erase(mp(cnt[a[y].second-'a'], a[y].second-'a'));

        cnt[a[x].second-'a']--; cnt[a[y].second-'a']--;
        a[x].first--; a[y].first--;
        if (cnt[a[x].second-'a']>0) bruh.insert(mp(cnt[a[x].second-'a'], a[x].second-'a'));
        if (cnt[a[y].second-'a']>0) bruh.insert(mp(cnt[a[y].second-'a'], a[y].second-'a'));
        deletes.push_back(mp(x, y));



        while (x!=-1 && a[x].first==0) x = prv[x];
        while (y!=-1 && a[y].first==0) y = nxt[y];
        if (y!=-1) prv[y] = x;
        if (x!=-1) nxt[x] = y;
        if (x!=-1 && y!=-1 && a[x].second!=a[y].second)
        {
            where_del[a[x].second-'a'].insert(mp(x, y));
            where_del[a[y].second-'a'].insert(mp(x, y));
        }
    }

    //for (auto it: deletes) cout<<it.first<<' '<<it.second<<endl;

    //cout<<"BRICKS"<<endl;

    for (int i = m-1; i>=0; i--) if (a[i].first!=0)
    {
        for (int j = 0; j<a[i].first; j++) deletes.push_back(mp(i, -1));
    }


    //for (auto it: deletes) cout<<it.first<<' '<<it.second<<endl;


    SegTree tree(A);

    /*cout<<"A: ";
    for (auto it: A) cout<<it<<' ';
    cout<<endl;*/

    int cur_len = n;

    cout<<deletes.size() + 1<<endl;



    for (auto it: deletes)
    {
        int l, r;

        //cout<<"handling "<<it.first<<' '<<it.second<<endl;


        //cout<<"first: "<<tree.get_pos(it.first)<<endl;
        l = tree.get_pos(it.first) + len[it.first];



        if (it.second!=-1) r = tree.get_pos(it.second);
        else r = cur_len-1;
        //cout<<"Cur len: "<<cur_len<<endl;
        cout<<l+1<<' '<<r+1<<endl;

        if (it.first!=-1) len[it.first]--; if (it.second!=-1) len[it.second]--;

        //cout<<"Hallucination "<<it.first<<' '<<it.second<<endl;

        //cout<<"update: "<<it.first+1<<' '<<m-1<<' '<<-(r-l+1)<<endl;
        cur_len-=(r-l+1);
        tree.add_on(it.first+1, m-1, -(r-l+1));

        //cout<<"Hallucination "<<it.first<<' '<<it.second<<endl;

        if (it.second!=-1) tree.add_on(it.second, it.second, 1);


    }
    cout<<1<<' '<<cur_len<<endl;





}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) solve();

}

/*
1
aabbcc
 */