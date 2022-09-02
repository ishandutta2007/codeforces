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

/*const int p = 998244353;


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
}*/

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


const int N = 200005;

vector<vector<int>> divs(N);

void init()
{
    for (int i = 1; i<N; i++)
    {
        for (int j = i; j<N; j+=i) divs[j].push_back(i);
    }
}

int res(vector<int> &a)
{
    int n = a.size();
    for (auto x: divs[n])
    {
        for (int i = 0; i<x; i++)
        {
            bool check = true;
            for (int j = i; j<n; j+=x) if (a[j]!=a[i]) check = false;
            if (check) return x;
        }
    }
}

void solve()
{
    int n;
    cin>>n;
    vector<int> p(n);
    vector<int> c(n);

    for (int i = 0; i<n; i++)
    {
        cin>>p[i]; p[i]--;
    }
    for (int i = 0; i<n; i++) cin>>c[i];

    int answer = 1e6;

    vector<bool> visited(n);
    for (int i = 0; i<n; i++) if (!visited[i])
    {
        int cur = p[i];
        vector<int> colors = {c[i]};
        visited[i] = true;
        while (cur!=i)
        {
            colors.push_back(c[cur]);
            visited[cur] = true;
            cur = p[cur];
        }
        //cout<<i<<": "<<res(colors)<<endl;
        answer = min(answer, res(colors));
    }
    cout<<answer<<'\n';

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    init();


    int t;
    cin>>t;
    while(t--) solve();

}