#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <iomanip>

using namespace std;

mt19937 Rand(16092002);
mt19937_64 BigRand(16092002);

typedef long long ll;

const int N = 1e5 + 7;

int go[N][26];
int dp[2][N];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    string s, t;
    cin >> s >> t;
    int m = (int) t.size();
    int n = (int) s.size();
    vector <int> pi(m);
    int j = 0;
    for (int i = 1; i < m; i++)
    {
        while (j > 0 && t[i] != t[j])
        {
            j = pi[j - 1];
        }
        j += (t[i] == t[j]);
        pi[i] = j;
    }
    for (int i = 0; i <= m; i++)
    {
        for (int c = 0; c < 26; c++)
        {
            if ((i > 0 && c != t[i] - 'a') || i == m)
            {
                go[i][c] = go[pi[i - 1]][c];
            }
            else
            {
                go[i][c] = i + (c == t[i] - 'a');
            }
        }
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = dp[1][j] = (int) -1e9;
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        int it = i % 2;
        for (int j = 0; j <= m; j++)
        {
            if (dp[it][j] == -1e9)
            {
                continue;
            }
            if (s[i] == '?')
            {
                for (int c = 0; c < 26; c++)
                {
                    dp[it ^ 1][go[j][c]] = max(dp[it ^ 1][go[j][c]], dp[it][j] + (go[j][c] == m));
                }
            }
            else
            {
                dp[it ^ 1][go[j][s[i] - 'a']] = max(dp[it ^ 1][go[j][s[i] - 'a']], dp[it][j] + (go[j][s[i] - 'a'] == m));
            }
            dp[it][j] = -1e9;
        }
    }
    int ans = 0;
    for (int j = 0; j <= m; j++)
    {
        ans = max(ans, dp[n % 2][j]);
    }
    cout << ans << '\n';
}