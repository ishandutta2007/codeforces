#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
/*#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2")  //Enable AVX*/

using namespace std;

using ll = long long;

#define mp make_pair

const int p = 1000000007;


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

/*const int N = 1000000;

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


void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    bool same = true;
    for (int i = 1; i<n; i++) if (a[i]!=a[0]) same = false;
    if (same)
    {
        cout<<1<<endl;
        for (int i = 0; i<n; i++) cout<<1<<' ';
        cout<<endl;
        return;
    }
    bool check_bad = true;
    for (int i = 0; i<n; i++) if (a[i]==a[(i+1)%n]) check_bad = false;
    if (n%2 == 0) check_bad = false;

    if (check_bad)
    {
        cout<<3<<endl;
        for (int i = 0; i<n-1; i++) cout<<i%2 + 1<<' ';
        cout<<3;
        cout<<endl;
        return;
    }

    if (n%2 == 0)
    {
        cout<<2<<endl;
        for (int i = 0; i<n; i++) cout<<i%2 + 1<<' ';
        cout<<endl;
        return;
    }
    int c = 0;
    while (a[c]!=a[(c+1)%n]) c++;
    cout<<2<<endl;
    vector<int> ans(n);
    for (int i = 0; i<n; i++) ans[(c+1+i)%n] = i%2 + 1;
    for (int i = 0; i<n; i++) cout<<ans[i]<<' ';
    cout<<endl;


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) solve();



}