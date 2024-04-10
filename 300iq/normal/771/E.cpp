#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5 + 7;
const int K = 20;

int dp[N];
int t[2][N];
ll hoh[N];
int pop[N];
int pep[N];
int go[2][N];
int up[2][N][K];
ll pref[2][N];

int main()
{
    ios::sync_with_stdio(0);
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> t[i][j];
        }
        ll sum = 0;
        for (int j = 0; j < n; j++)
        {
            hoh[j] += t[i][j];
            sum += t[i][j];
            pref[i][j] = sum;
        }
        map <ll, int> kek;
        for (int j = n - 1; j >= 0; j--)
        {
            kek[pref[i][j]] = j;
            if (kek.count((j ? pref[i][j - 1] : 0)))
            {
                go[i][j] = kek[(j ? pref[i][j - 1] : 0)];
            }
            else
            {
                go[i][j] = n;
            }
        }
        int cur = 1e9;
        up[i][n][0] = n + 1;
        for (int j = n - 1; j >= 0; j--)
        {
            cur = min(cur, go[i][j]);
            up[i][j][0] = cur + 1;
        }
        for (int k = 1; k < K; k++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (up[i][j][k - 1] == n + 1)
                {
                    up[i][j][k] = n + 1;
                }
                else
                {
                    up[i][j][k] = up[i][up[i][j][k - 1]][k - 1];
                }
            }
        }
    }
    map <ll, int> kek;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += hoh[i];
        hoh[i] = sum;
    }
    int cur = 1e9;
    for (int i = n - 1; i >= 0; i--)
    {
        kek[hoh[i]] = i;
        if (kek.count((i ? hoh[i - 1] : 0)))
        {
            pep[i] = kek[(i ? hoh[i - 1] : 0)];
        }
        else
        {
            pep[i] = n;
        }
        cur = min(cur, pep[i]);
        pop[i] = cur;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int p = 0; p < 2; p++)
        {
            int kek = up[p][i][0] - 1;
            if (kek != n)
            {
                int cnt = 1;
                int kok = 0;
                int x = i;
                for (int k = K - 1; k >= 0; k--)
                {
                    if (x >= n)
                    {
                        break;
                    }
                    if (up[p ^ 1][x][k] <= kek + 1)
                    {
                        cnt += (1 << k);
                        x = up[p ^ 1][x][k];
                    }
                }
                int cot = cnt;
                int cur = kek + 1;
                for (int it = 0; it < 100; it++)
                {
                    if (x >= n)
                    {
                        break;
                    }
                    if (up[p ^ 1][x][0] != n + 1)
                    {
                        int last = up[p ^ 1][x][0];
                        {
                            int x = cur;
                            for (int k = K - 1; k >= 0; k--)
                            {
                                if (x >= n)
                                {
                                    break;
                                }
                                if (up[p][x][k] <= last)
                                {
                                    cot += (1 << k);
                                    x = up[p][x][k];
                                }
                            }
                            cur = x;
                        }
                        cot++;
                        dp[i] = max(dp[i], dp[up[p ^ 1][x][0]] + cot);
                        x = up[p ^ 1][x][0];
                    }
                }
                dp[i] = max(dp[i], dp[kek + 1] + cnt);
            }
        }
        if (pop[i] != n)
        {
            dp[i] = max(dp[i], dp[pop[i] + 1] + 1);
        }
        dp[i] = max(dp[i], dp[i + 1]);
    }
    cout << dp[0] << '\n';
}