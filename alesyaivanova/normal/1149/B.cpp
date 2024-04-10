#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define pb emplace_back

const int MAXN = 100009;
const int T = 256;
int dp[T][T][T];
int ne[MAXN][30];
int n, q;
int pt[3];
vector<char> a[3];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> n >> q >> s;
    s = "#" + s;
    n++;
    for (int e = 0; e < 26; e++)
    {
        ne[n][e] = n;
        ne[n - 1][e] = n;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int e = 0; e < 26; e++)
            ne[i][e] = ne[i + 1][e];
        ne[i][s[i + 1] - 'a'] = i + 1;
    }
    for (int j = 0; j < q; j++)
    {
        char c;
        cin >> c;
        if (c == '+')
        {
            int i;
            cin >> i >> c;
            i--;
            a[i].pb(c);
            pt[i]++;
            int ee0 = 0, ee1 = 0, ee2 = 0;
            if (i == 0)
                ee0 = pt[0];
            else if (i == 1)
                ee1 = pt[1];
            else
                ee2 = pt[2];
            for (int e0 = ee0; e0 <= pt[0]; e0++)
            {
                for (int e1 = ee1; e1 <= pt[1]; e1++)
                {
                    for (int e2 = ee2; e2 <= pt[2]; e2++)
                    {
                        dp[e0][e1][e2] = n;
                        if (e0 > 0)
                            dp[e0][e1][e2] = min(dp[e0][e1][e2], ne[dp[e0 - 1][e1][e2]][a[0][e0 - 1] - 'a']);
                        if (e1 > 0)
                            dp[e0][e1][e2] = min(dp[e0][e1][e2], ne[dp[e0][e1 - 1][e2]][a[1][e1 - 1] - 'a']);
                        if (e2 > 0)
                            dp[e0][e1][e2] = min(dp[e0][e1][e2], ne[dp[e0][e1][e2 - 1]][a[2][e2 - 1] - 'a']);
                        //cout << e0 << " " << e1 << " " << e2 << " " << dp[e0][e1][e2] << "\n";
                    }
                }
            }
        }
        else
        {
            int i;
            cin >> i;
            i--;
            pt[i]--;
            a[i].pop_back();
        }
        if (dp[pt[0]][pt[1]][pt[2]] < n)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}