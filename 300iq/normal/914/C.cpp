#include <cmath>
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
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 1000 + 7;
const int M = 1e9 + 7;

inline int add(int a, int b)
{
    a += b;
    if (a >= M) a -= M;
    return a;
}

inline int mul(int a, int b)
{
    return (a * (ll) b) % M;
}

int dp[N][N][2];
int cnt[N];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    cnt[1] = 0;
    for (int i = 2; i < N; i++)
    {
        cnt[i] = cnt[__builtin_popcount(i)] + 1;
    }
    string s;
    cin >> s;
    int k;
    cin >> k;
    if (k == 0)
    {
        cout << 1 << '\n';
        return 0;
    }
    int n = (int) s.size();
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int cnt = 0; cnt <= n; cnt++)
        {
            for (int t = 0; t < 2; t++)
            {
                for (int cur = 0; cur < 2; cur++)
                {
                    if (!t && cur > s[i] - '0') continue;
                    int new_t = (t | (cur < s[i] - '0'));
                    int new_cnt = cnt + (cur == 1);
                    dp[i + 1][new_cnt][new_t] = add(dp[i + 1][new_cnt][new_t], dp[i][cnt][t]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] + 1 == k)
        {
            for (int t = 0; t < 2; t++) ans = add(ans, dp[n][i][t]); 
            if (i == 1) ans = add(ans, M - 1);
        }
    }
    printf("%d\n", ans);
}