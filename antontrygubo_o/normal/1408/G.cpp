#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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
}*/


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
       sz.resize(n);
       parent.resize(n);
       for (int i = 0; i<n; i++) make_set(i);
    }
};


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++) cin>>a[i][j];

    vector<pair<int, pair<int, int>>> bruh;
    for (int i = 0; i<n; i++)
        for (int j = i+1; j<n; j++) bruh.push_back(mp(a[i][j], mp(i, j)));

    sort(bruh.begin(), bruh.end());

    DSU dsu(n);

    vector<int> root(n);
    vector<vector<int>> cnt(2*n);
    vector<int> edges(2*n);
    for (int i = 0; i<n; i++)
    {
        root[i] = i;
        cnt[i] = {1};
    }

    int cur = n-1;

    for (auto it: bruh)
    {
        int r1 = dsu.find_set(it.second.first);
        int r2 = dsu.find_set(it.second.second);
        if (r1==r2)
        {
            int R1 = root[r1];
            edges[R1]++;
            int sz = cnt[R1].size();
            if (edges[R1] == sz*(sz-1)/2) cnt[R1][0] = 1;
        }
        if (r1 != r2)
        {
            //cout<<r1<<' '<<r2<<endl;
            dsu.union_sets(r1, r2);
            cur++;
            int R1 = root[r1]; int R2 = root[r2];
            int sz1 = cnt[R1].size(); int sz2 = cnt[R2].size();

            edges[cur] = edges[R1] + edges[R2] + 1;
            int sz = sz1+sz2;

            cnt[cur].resize(sz1+sz2);

            if (edges[cur] == sz*(sz-1)/2) cnt[cur][0] = 1;

            for (int i = 0; i<sz1; i++)
                for (int j = 0; j<sz2; j++)
                {
                    cnt[cur][i+j+1] = add(cnt[cur][i+j+1], mul(cnt[R1][i], cnt[R2][j]));
                }

            root[r1] = cur; root[r2] = cur;
        }
    }

    for (int i = 0; i<n; i++) cout<<cnt[cur][i]<<' ';

}
/*
1
 5 3
1 2 3 4 5
 */