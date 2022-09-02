#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;


const int p = 1e9 + 7;


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

int n, m;

int make_cell(pair<int, int> cell)
{
    return (cell.first*m + cell.second);
}

struct DSU {
    vector<int> sz;
    vector<int> parent;

    int total;

    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
        total++;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(pair<int, int> A, pair<int, int> B) {
        int a = make_cell(A);
        int b = make_cell(B);
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            total--;
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    DSU() {
        sz.resize(n*m);
        parent.resize(n*m);
        total = 0;
    }
};

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
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}
*/


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);


    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];

    vector<int> deg(20);
    for (auto it: a)
    {
        for (int i = 0; i<20; i++) if (it&(1<<i)) deg[i]++;
    }

    vector<ll> b(n);
    for (int i = 0; i<20; i++)
    {
        for (int j = 0; j<deg[i]; j++) b[j]+=(1<<i);
    }

    ll res = 0;
    for (auto it: b) res+=it*it;
    cout<<res;

}