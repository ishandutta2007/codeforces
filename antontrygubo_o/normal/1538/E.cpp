#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

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


int MOD =  998244353;



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
const int LIM = 1000;

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

struct str
{
    bool toolong;
    string s;
    string suf;
    string pref;
    ll cnt = 0;
};

str produce(string s)
{
    str kek;
    if (s.size()<3)
    {
        kek.toolong = false;
        kek.s = s;
    }
    else
    {
        int n = s.size();
        kek.toolong = true;
        kek.pref = s.substr(0, 3);
        kek.suf = s.substr(n-3, 3);
        kek.cnt = 0;
        for (int i = 0; i+4<=n; i++) if (s.substr(i, 4)=="haha") kek.cnt++;
    }
    return kek;
}

str merge(str a, str b)
{
    if (!a.toolong && !b.toolong) return produce(a.s + b.s);

    if (a.toolong && !b.toolong)
    {
        string ending = a.suf + b.s;
        int n = ending.size();
        for (int i = 0; i+4<=n; i++) if (ending.substr(i, 4)=="haha") a.cnt++;
        a.suf = ending.substr(n-3, 3);
        return a;
    }

    if (!a.toolong && b.toolong)
    {
        string prefix = a.s + b.pref;
        int n = prefix.size();
        for (int i = 0; i+4<=n; i++) if (prefix.substr(i, 4)=="haha") b.cnt++;
        b.pref = prefix.substr(0, 3);
        return b;
    }

    str kek;
    kek.toolong = true;
    kek.suf = b.suf;
    kek.pref = a.pref;
    kek.cnt = a.cnt + b.cnt;
    string mid = a.suf + b.pref;
    int n = mid.size();
    for (int i = 0; i+4<=n; i++) if (mid.substr(i, 4)=="haha") kek.cnt++;
    return kek;
}

void solve()
{
    map<string, str> mapka;
    int q; cin>>q;
    string name;
    while (q--)
    {
        cin>>name;
        string op; cin>>op;
        if (op==":=")
        {
            string val; cin>>val;
            mapka[name] = produce(val);
        }
        else
        {
            string add1, eq, add2; cin>>add1>>eq>>add2;
            mapka[name] = merge(mapka[add1], mapka[add2]);
        }
    }
    cout<<mapka[name].cnt<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);


    int t; cin>>t; while (t--) solve();

}