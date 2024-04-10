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
namespace myrand
{
    mt19937 mt(chrono::system_clock::now().time_since_epoch() / chrono::microseconds(1));
    ll Int(ll l,ll r) {return uniform_int_distribution<ll> (l,r)(mt);}
}

using namespace myrand;
const int N = 2e5 + 10;
ll a[N];
int n, m, p, cnt[N];

void trans(int dp[], int nbit)
{
    int mx = (1 << nbit) - 1;
    for (int i = 0; i < nbit; ++i)
    {
        int val = (1 << i);
        int mx_mask = mx ^ val;
        for (int mask = mx_mask; mask; mask = (mask - 1) & mx_mask)
            dp[mask] += dp[mask | val];
        dp[0] += dp[val];
    }
}

ll cnt_res = 0, mask_res = 0;
void solve(ll base)
{
    vi bit;
    for (int i = 0; i < m; ++i)
        if ((base >> i) & 1) bit.eb(i);
    int len = bit.size();
    for (int j = 0; j < (1 << len); ++j) cnt[j] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x = 0, d = 0;
        for (int b : bit)
        {
            if ((a[i] >> b) & 1) x |= (1 << d);
            d++;
        }
        cnt[x]++;
    }
    trans(cnt, len);
    for (int mask = 0; mask < (1 << len); ++mask)
        if (cnt[mask] >= (n + 1) >> 1 && __builtin_popcount(mask) > cnt_res)
        {
            ll val = 0;
            for (int j = 0; j < len; ++j)
                if ((mask >> j) & 1) val |= 1ll << bit[j];
            mask_res = val;
            cnt_res = __builtin_popcount(mask);
        }
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> p;
    for (int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        for (char c : s) a[i] = (a[i] << 1) + c - '0';
    }
    for (int i = 1; i <= 40; ++i) solve(a[Int(1, n)]);
    vi ans;
    for (int i = 1; i <= m; ++i)
    {
        ans.eb(mask_res & 1);
        mask_res >>= 1;
    }
    reverse(all(ans));
    for (int x : ans) cout << x;
    return 0;
}