#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map <ll, ll> used;
map <ll, ll> cnt;

void dfs(ll x)
{
    if (used.count(x))
    {
        return;
    }
    if (x > 1)
    {
        dfs(x / 2);
        dfs(x % 2);
        dfs(x / 2);
        used[x] += used[x / 2];
        used[x] += used[x % 2];
        used[x] += used[x / 2];
        cnt[x] += cnt[x / 2];
        cnt[x] += cnt[x % 2];
        cnt[x] += cnt[x / 2];
    }
    else
    {
        used[x] = x;
        cnt[x] = 1;
    }
}

int kek(ll x, ll l, ll r, ll tl, ll tr)
{
    if (tl >= r || tr <= l)
    {
        return 0; 
    }
    if (tl >= l && tr <= r)
    {
        return used[x];
    }
    else
    {
        ll vl = tl + cnt[x / 2];
        int ans = kek(x / 2, l, r, tl, vl);
        ll vr = tl + cnt[x / 2] + cnt[x % 2];
        ans += kek(x % 2, l, r, vl, vr);
        ans += kek(x / 2, l, r, vr, tr);
        return ans;
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    ll n;
    ll l, r;
    cin >> n >> l >> r;
    dfs(n);
    cout << kek(n, l - 1, r, 0, cnt[n]) << '\n';
}