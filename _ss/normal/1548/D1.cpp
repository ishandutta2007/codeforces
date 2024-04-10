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
const int N = 1e5 + 10;
ll cnt[2][2];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1, x, y; i <= n; ++i)
    {
        cin >> x >> y;
        cnt[(x >> 1) & 1][(y >> 1) & 1]++;
    }
    ll res = 0;
    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j <= 1; ++j)
        {
            res += cnt[i][j] * (cnt[i][j] - 1) * (cnt[i][j] - 2) / 6;
            res += cnt[i][j] * (cnt[i][j] - 1) / 2 * (n - cnt[i][j]);
        }
    cout << res;
    return 0;
}