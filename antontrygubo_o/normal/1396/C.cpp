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

/*
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
*/

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

const ll INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, r1, r2, r3, d;
    cin>>n>>r1>>r2>>r3>>d;

    vector<ll> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];

    vector<ll> oneshot(n);
    vector<ll> twoshot(n);
    for (int i = 0; i<n; i++)
    {
        oneshot[i] = min(r1, r3)*a[i] + r3;
        twoshot[i] = min(min(r1, r3)*(a[i]+2), r2 + min({r1, r2, r3}));
        twoshot[i] = min(twoshot[i], oneshot[i]);
    }
    /*for (int i = 0; i<n; i++) cout<<oneshot[i]<<' ';
    cout<<endl;
    for (int i = 0; i<n; i++) cout<<twoshot[i]<<' ';
    cout<<endl;*/

    vector<ll> dp(n, INF);
    dp[n-1] = min(oneshot[n-1], twoshot[n-1] + 2*d);
    for (int i = n-2; i>=0; i--)
    {
        dp[i] = min(dp[i], oneshot[i] + d + dp[i+1]);
        if (i+2<n) dp[i] = min(dp[i], twoshot[i] + twoshot[i+1] + 4*d + dp[i+2]);
        else dp[i] = min({dp[i], twoshot[i] + oneshot[i+1] + 2*d, twoshot[i] + twoshot[i+1] + 3*d});
    }

    //for (auto it: dp) cout<<it<<' ';
    cout<<dp[0];
}