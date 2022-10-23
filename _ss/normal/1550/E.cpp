#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 2e5 + 10;
char a[N];
int n, k, mx_len[N][20], best[N][20], dp[N];

void opt(int &x, int y) { x = min(x, y);}

bool check(int len)
{
    for (int i = 1; i <= k; ++i) best[n + 1][i] = n + 1;
    for (int i = n; i; --i)
        for (int j = 1; j <= k; ++j)
            if (mx_len[i][j] >= len) best[i][j] = i + len - 1;
            else best[i][j] = best[i + 1][j];
    int m = (1 << k) - 1;
    for (int i = 1; i <= m; ++i) dp[i] = n + 1;
    for (int i = 0; i < m; ++i)
        if (dp[i] < n)
        for (int j = 0; j < k; ++j)
            if (((i >> j) & 1) == 0)
                opt(dp[i | (1 << j)], best[dp[i] + 1][j + 1]);
    return dp[m] <= n;
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> (a + 1);
    for (int i = n; i; --i)
    {
        if (a[i] == '?')
            {for (int j = 1; j <= k; ++j) mx_len[i][j] = 1;}
        else mx_len[i][a[i] - 'a' + 1] = 1;
        for (int j = 1; j <= k; ++j)
            if (mx_len[i][j]) mx_len[i][j] += mx_len[i + 1][j];
    }
    int l = 1, r = n, ans = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}