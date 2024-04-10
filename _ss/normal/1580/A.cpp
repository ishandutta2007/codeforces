#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 1e3 + 10;
int a[N][N], m, n, ps[N][N], ps2[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
        {
            string s;
            cin >> s;
            for (int j = 1; j <= m; ++j) a[i][j] = s[j - 1] - '0', ps[i][j] = ps[i - 1][j] + a[i][j];
        }
        int res = n * m;
        for (int i = 1; i <= n; ++i)
            for (int j = i + 4; j <= n; ++j)
            {
                for (int r = 1; r <= m; ++r) ps2[r] = ps2[r - 1] + ps[j - 1][r] - ps[i][r] + (1 - a[i][r]) + (1 - a[j][r]);
                int mx = -1e9;
                for (int r = 4; r <= m; ++r)
                {
                    int l = r - 3;
                    mx = max(mx, ps2[l] - (j - i - 1) + (ps[j - 1][l] - ps[i][l]));
                    res = min(res, ps2[r - 1] + (j - i - 1) - (ps[j - 1][r] - ps[i][r]) - mx);
                }
            }
        cout << res << "\n";
    }
    return 0;
}