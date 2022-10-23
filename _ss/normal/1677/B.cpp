#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 1e5 + 10;

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vi ps(n * m, 0);
        for (int i = 0; i < n * m; ++i)
        {
            if (i) ps[i] = ps[i - 1];
            if (s[i] == '1') ps[i]++;
        }
        vi dp(n * m, 0), mark(m, 0);
        int res = 0;
        for (int i = 0; i < n * m; ++i)
        {
            if (i < m)
            {
                if (ps[i] > 0) dp[i] = 1;
            }
            else
            {
                dp[i] = dp[i - m];
                if (ps[i] > ps[i - m]) dp[i]++;
            }
            int j = i % m;
            if (s[i] == '1')
            {
                if (!mark[j])
                {
                    mark[j] = 1;
                    res++;
                }
            }
            cout << dp[i] + res << " ";
        }
        cout << "\n";
    }
    return 0;
}