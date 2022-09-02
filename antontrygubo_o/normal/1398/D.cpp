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
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}
*/


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int r, g, b;
    cin>>r>>g>>b;
    vector<ll> A(r), B(g), C(b);

    for (int i = 0; i<r; i++) cin>>A[i];
    for (int i = 0; i<g; i++) cin>>B[i];
    for (int i = 0; i<b; i++) cin>>C[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    vector<vector<vector<ll>>> dp(r+1, vector<vector<ll>>(g+1, vector<ll>(b+1)));



    for (int i = 0; i<=r; i++)
        for (int j = 0; j<=g; j++)
            for (int k = 0; k<=b; k++)
            {
                if (i>0 && j>0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + A[i-1]*B[j-1]);
                if (i>0 && k>0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + A[i-1]*C[k-1]);
                if (j>0 && k>0) dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1] + B[j-1]*C[k-1]);
            }

    cout<<dp[r][g][b];

}