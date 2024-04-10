#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb emplace_back
#define mp make_pair
#define ld long double
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 1e4 + 9;
int n;
int a[maxn];
int b[maxn];
int cnt1, cnt2;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r",stdin);
        //freopen("output.txt", "w",stdout);
    #endif
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt1 += a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        cnt2 += b[i];
    }
    if (cnt1 > cnt2)
    {
        cout << 1;
        return 0;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] && !b[i])
            cnt++;
    }
    if (!cnt)
    {
        cout << -1;
        return 0;
    }
    int ans = cnt2 - cnt1 + 1;
    ans = 1 + (ans + cnt - 1) / cnt;
    cout << ans;
}