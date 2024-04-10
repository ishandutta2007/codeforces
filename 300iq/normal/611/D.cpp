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

using namespace std;

mt19937 Rand(16092002);
mt19937_64 BigRand(16092002);

typedef long long ll;

const int N = 5000 + 1;
const int M = 1e9 + 7;

int lcp[N][N];
int dp[N][N];

inline int add(int a, int b)
{
    return (a + b >= M ? a + b - M : a + b);
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (s[i] == s[j])
            {
                lcp[i][j] = lcp[i + 1][j + 1] + 1;
            }
            else
            {
                lcp[i][j] = 0;
            }
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            continue;
        }
        int sum = dp[i][0];
        for (int j = i; j < n; j++)
        {
            int len = j - i + 1;
            dp[j + 1][len] = add(dp[j + 1][len], sum);
            int l = i, r = j;
            int vl = i - len, vr = i - 1;
            if (vl >= 0)
            {
                int pos = lcp[l][vl];
                if (pos < len && s[l + pos] > s[vl + pos])
                {
                    dp[j + 1][len] = add(dp[j + 1][len], dp[i][len]);
                }
            }
            sum = add(sum, dp[i][len]);
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans = add(ans, dp[n][i]);
    }
    cout << ans << '\n';
}