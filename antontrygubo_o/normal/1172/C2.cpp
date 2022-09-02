#include <bits/stdc++.h>


using namespace std;

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

/*const int N = 1200000;

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

const int N = 3030;

vector<vector<int>> dp(N, vector<int>(N));

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;

    vector<int> like(n);
    for (int i = 0; i<n; i++) cin>>like[i];

    vector<int> w(n);
    for (int i = 0; i<n; i++) cin>>w[i];

    int good = 0;
    int bad = 0;
    for (int i = 0; i<n; i++) if (like[i]) good+=w[i]; else bad+=w[i];


    //cout<<good<<' '<<bad<<endl;


    vector<int> keks(2*m+1);

    for (int i = 0; i<=2*m; i++) keks[i] = inv(good + bad - m + i);

    //good + bad - m ... good + bad + m

    dp[0][0] = 1;
    for (int i = 0; i<=m; i++)
        for (int j = 0; j<=min(bad, m-i); j++) if (i+j)
        {
            if (i>0) dp[i][j] = add(dp[i][j], mul(dp[i-1][j], mul((good + i-1), keks[m + i - j - 1])));
            if (j>0) dp[i][j] = add(dp[i][j], mul(dp[i][j-1], mul((bad - (j-1)), keks[m + i - j + 1])));
        }

    /*cout<<"DP: ";
    cout<<dp[0][1]<<' '<<dp[1][0]<<endl;*/

    int expgood = 0; int expbad = 0;

    for (int i = 0; i<=m; i++)
    {
        expgood = add(expgood, mul(i, dp[i][m-i]));
        expbad = add(expbad, mul(m-i, dp[i][m-i]));
    }

    //cout<<expgood<<' '<<expbad<<endl;

    int mulgood = mul(add(good, expgood), inv(good));
    int mulbad = mul(sub(bad, expbad), inv(bad));

    for (int i = 0; i<n; i++)
    {
        if (like[i]) cout<<mul(w[i], mulgood)<<endl; else cout<<mul(w[i], mulbad)<<endl;
    }

}