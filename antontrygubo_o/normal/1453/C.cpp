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
const int N = 1000005;

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
    vector<string> s(n);
    for (int i = 0; i<n; i++) cin>>s[i];

    for (int dig = 0; dig<=9; dig++)
    {
        int minx = n; int maxx = -1; int miny = n; int maxy = -1;
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<n; j++) if (s[i][j]-'0'==dig)
            {
                minx = min(minx, i); maxx = max(maxx, i); miny = min(miny, j); maxy = max(maxy, j);
            }
        }
        int best = 0;


        //cout<<minx<<' '<<maxx<<endl;

        for (int i = 0; i<n; i++)
        {
            int MIN = n; int MAX = -1;
            for (int j = 0; j<n; j++) if (s[i][j]-'0'==dig)
                {
                    MIN = min(MIN, j); MAX = max(MAX, j);
                }
            if (MAX>=MIN)
            {
                best = max(best, (MAX-MIN)*max(n-1-i, i));
                best = max(best, max(MAX, n-1-MIN) * (i-minx));
                best = max(best, max(MAX, n-1-MIN) * (maxx-i));
            }
        }

        for (int i = 0; i<n; i++)
        {
            int MIN = n; int MAX = -1;
            for (int j = 0; j<n; j++) if (s[j][i]-'0'==dig)
                {
                    MIN = min(MIN, j); MAX = max(MAX, j);
                }
            if (MAX>=MIN)
            {
                best = max(best, (MAX-MIN)*max(n-1-i, i));
                best = max(best, max(MAX, n-1-MIN) * (i-miny));
                best = max(best, max(MAX, n-1-MIN) * (maxy-i));
            }
        }
        cout<<best<<' ';
        //cout<<endl;
    }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) solve();



}
/*
1
3
000
122
001
 */