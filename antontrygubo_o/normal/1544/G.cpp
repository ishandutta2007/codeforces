#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = long double;

typedef tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

#define mp make_pair

const int MOD =  31607;

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=MOD) s-=MOD;
    return s;
}

int sub(int a, int b) {
    int s = (a+MOD-b);
    if (s>=MOD) s-=MOD;
    return s;
}

int po(int a, ll deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, MOD-2);
}


mt19937 rnd(time(0));

/*
const int LIM = 300000;

vector<int> facs(LIM), invfacs(LIM);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<LIM; i++) facs[i] = mul(facs[i-1], i);
    invfacs[LIM-1] = inv(facs[LIM-1]);
    for (int i = LIM-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C(int n, int k)
{
    if (n<k) return 0;
    if (n<0 || k<0) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}*/

/*
struct DSU
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
        return find_set(parent[v]);
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

int n, k;

int ones(string s)
{
    int cnt = 0;
    for (auto c: s) if (c=='1') cnt++;
    return cnt;
}

pair<int, int> firstlast(string s)
{
    int first = 0; int last = n-1;
    while (s[first]=='0') first++;
    while (s[last]=='0') last--;
    return mp(first, last);
}

int alternating(string s)
{
    bool neg = false;
    int ans = 0;
    for (int i = 0; i<n; i++) if (s[i]=='1')
    {
        if (neg) ans+=i; else ans-=i;
        neg = !neg;
    }
    return ans;
}

void apply(vector<char> &s, int l, int r)
{
    for (int i = l; i<=(l+r)/2; i++) swap(s[i], s[l+r-i]);
}

vector<int> where(vector<char> s)
{
    vector<int> ans;
    for (int i = 0; i<n; i++) if (s[i]=='1') ans.push_back(i);
    return ans;
}

vector<pair<int, int>> ops(string s1)
{
    vector<char> s(n);
    for (int i = 0; i<n; i++) s[i] = s1[i];

    vector<pair<int, int>> ans;


    int cnt = ones(s1);

    for (int i = 0; i<=cnt-k; i++)
    {
        if (s[i]=='1') continue;
        else
        {
            auto positions = where(s);
            ans.push_back(mp(i, positions[i+k-1]));
            apply(s, i, positions[i+k-1]);
        }
    }

    //Now we care only about k ones in the end, from k to n-1
    if (k%2==1)
    {
        for (int iter = 0; iter<k; iter++)
        {
            auto positions = where(s);
            ans.push_back(mp(positions[cnt-k-1]+1, positions[cnt-1]));
            apply(s, positions[cnt-k-1]+1, positions[cnt-1]);
            positions = where(s);
            ans.push_back(mp(positions[cnt-k-1], positions[cnt-2]));
            apply(s, positions[cnt-k-1], positions[cnt-2]);
        }

        /*for (auto c: s) cout<<c;
        cout<<endl;*/

        return ans;

    }
    else
    {
        for (int iter = 0; iter<k/2; iter++)
        {
            auto positions = where(s);
            ans.push_back(mp(positions[cnt-k-1]+1, positions[cnt-1]));
            apply(s, positions[cnt-k-1]+1, positions[cnt-1]);
            positions = where(s);
            ans.push_back(mp(positions[cnt-k-1], positions[cnt-1]-1));
            apply(s, positions[cnt-k-1], positions[cnt-1]-1);
        }
        auto positions = where(s);
        int st = 0; if (cnt>=k+2) st = positions[cnt-k-2]+1;
        ans.push_back(mp(st, positions[cnt-2]));
        apply(s, st, positions[cnt-2]);

        /*for (auto c: s) cout<<c;
        cout<<endl;*/

        return ans;
    }

}

//We want all but last k guys in the end at this point

void solve()
{
    cin>>n>>k;
    string a, b; cin>>a>>b;

    if (a==b) {cout<<0<<endl; return;}

    if (k==0)
    {
        if (a!=b) {cout<<-1<<endl; return;}
        else {cout<<0<<endl; return;}
    }

    int cnta = ones(a); int cntb = ones(b);

    if (cnta!=cntb) {cout<<-1<<endl; return;}
    if (cnta<k && a!=b) {cout<<-1<<endl; return;}


    if (cnta==k)
    {
        auto fla = firstlast(a);
        auto flb = firstlast(b);
        string a1, b1;
        for (int i = fla.first; i<=fla.second; i++) a1+=a[i];
        for (int i = flb.first; i<=flb.second; i++) b1+=b[i];

        if (a1==b1)
        {
            cout<<2<<endl;
            cout<<1<<' '<<fla.second+1<<endl;
            cout<<1<<' '<<flb.second+1<<endl;
            return;
        }
        reverse(a1.begin(), a1.end());
        if (a1==b1)
        {
            cout<<3<<endl;
            cout<<1<<' '<<n<<endl;
            swap(fla.first, fla.second);
            fla.first = n-1-fla.first;
            fla.second = n-1-fla.second;
            cout<<1<<' '<<fla.second+1<<endl;
            cout<<1<<' '<<flb.second+1<<endl;
            return;
        }
        cout<<-1<<endl;
        return;
    }


    //DEALT WITH THIS SHIT HURRRAAAAAY

    if (k%2==0)
    {
        if (alternating(a)!=alternating(b)) {cout<<-1<<endl; return;}
    }

    auto opsa = ops(a);
    auto opsb = ops(b);
    reverse(opsb.begin(), opsb.end());
    for (auto it: opsb) opsa.push_back(it);

    cout<<opsa.size()<<endl;
    for (auto it: opsa) cout<<it.first+1<<' '<<it.second+1<<endl;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t; while(t--) solve();

}