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
        find_set(a);
        find_set(b);

        a = find_set(a);
        b = find_set(b);

        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        };
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
    int n, l, r; cin>>n>>l>>r;
    vector<int> c(n); for (int i = 0; i<n; i++) {cin>>c[i]; c[i]--;}

    vector<int> L(n), R(n);
    for (int i = 0; i<l; i++) L[c[i]]++;
    for (int i = l; i<n; i++) R[c[i]]++;

    for (int i = 0; i<n; i++)
    {
        int tmp = min(L[i], R[i]);
        L[i]-=tmp; R[i]-=tmp;
    }

    vector<int> a, b;
    for (auto it: L) if (it) a.push_back(it);
    for (auto it: R) if (it) b.push_back(it);

    int A = 0; int B = 0;
    for (auto it: a) A+=it;
    for (auto it: b) B+=it;

    int oddA = 0; int oddB = 0;
    for (auto it: a) oddA+=(it%2); for (auto it: b) oddB+=(it%2);

    int adder = 0;
    if (oddB>A) adder=(oddB-A)/2;
    if (oddA>B) adder=(oddA-B)/2;

    cout<<adder + (A+B)/2<<endl;

}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t;
    while (t--) solve();



}