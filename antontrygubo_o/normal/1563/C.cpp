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

int MOD =  1e9 + 7;

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
const int LIM = 3000005;

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

vector<int> ops;

void mv(vector<int> &p, int pos)
{
    for (int i = 0; i<pos/2; i++) swap(p[i], p[pos-1-i]);
}

void process(vector<int> p)
{
    int n = p.size();
    if (n==1) return;

    if (p[0]!=n-1)
    {
        int pos = 0;
        while (p[pos]!=n-1) pos++;
        ops.push_back(pos+1);
        mv(p, pos+1);
    }

    if (p[1]!=n-2)
    {
        int pos = 0;
        while (p[pos]!=n-2) pos++;
        ops.push_back(pos);
        mv(p, pos);

        ops.push_back(n);
        mv(p, n);

        pos = 0;
        while (p[pos]!=n-1) pos++;
        ops.push_back(pos+1);
        mv(p, pos+1);
    }

    ops.push_back(n);
    mv(p, n);

    /*for (auto it: p) cout<<it<<' ';
    cout<<endl;*/

    vector<int> p1;
    for (int i = 0; i<n-2; i++) p1.push_back(p[i]);
    process(p1);
}

void solve()
{
    int n; cin>>n;
    ops.clear();
    vector<int> p(n);
    for (int i = 0; i<n; i++) {cin>>p[i]; p[i]--;}

    set<int> even;
    for (int i = 0; i<n; i+=2) even.insert(p[i]);
    for (int i = 1; i<n; i+=2) if (even.count(i)) {cout<<-1<<endl; return;}

    process(p);

    cout<<ops.size()<<endl;
    for (auto it: ops) cout<<it<<' ';
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t; while (t--) solve();

}
/*
1
9
1 4 5 2 3 8 9 6 7
 */