#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")


using ll = long long;
using ld = long double;



#define mp make_pair

const int p = 998244353;

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


mt19937 rnd(time(0));

/*
const int N = 1200000;

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
    if (n<k) return 0;
    if (n<0 || k<0) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}

*/


/*struct DSU
{
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

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];

    set<pair<int, int>> ans;

    vector<int> nxt(n, -1);
    stack<int> ones;
    stack<int> bigs;
    for (int i = n-1; i>=0; i--)
    {
        if (a[i]==3)
        {
            if (!bigs.empty())
            {
                nxt[i] = bigs.top();
                bigs.pop();
            }
            else if (!ones.empty())
            {
                nxt[i] = ones.top();
                ones.pop();
            }
            else {cout<<-1<<endl; return;}
            bigs.push(i);
        }
        if (a[i]==2)
        {
            if (!ones.empty())
            {
                nxt[i] = ones.top();
                ones.pop();
            }
            else {cout<<-1<<endl; return;}
            bigs.push(i);
        }
        if (a[i]==1)
        {
            ones.push(i);
        }
    }

    /*for (auto it: nxt) cout<<it<<' ';
    cout<<endl;*/

    vector<bool> done(n);
    int h = 0;
    for (int i = 0; i<n; i++) if (!done[i])
    {
        done[i] = true;
        if (a[i]==0) continue;
        h++;
        int cur = i;
        while (nxt[cur]!=-1)
        {
            done[nxt[cur]] = true;
            if (a[cur]==3)
            {
                ans.insert(mp(cur, h));
                ans.insert(mp(nxt[cur], h));
                ans.insert(mp(nxt[cur], h+1));
                h++;
                cur = nxt[cur];
            }
            else if (a[cur]==2)
            {
                ans.insert(mp(cur, h));
                ans.insert(mp(nxt[cur], h));
                cur = nxt[cur];
            }
        }
        ans.insert(mp(cur, h));
    }

    cout<<ans.size()<<endl;
    for (auto it: ans) cout<<it.second<<' '<<it.first+1<<endl;


}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();

}