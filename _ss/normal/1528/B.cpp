#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 1e6 + 10;
const ll mod = 998244353;
ll dp[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; j += i) dp[j]++;
    ll sum = dp[1];
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = (dp[i] + sum) % mod;
        sum = (sum + dp[i]) % mod;
    }
    cout << dp[n];
    return 0;
}