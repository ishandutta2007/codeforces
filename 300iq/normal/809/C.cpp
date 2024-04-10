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

const int N = 33;
const int M = 1e9 + 7;

int pw[N];
int dp[N][2][2][2];
int cnt[N][2][2][2];

inline int add(int a, int b)
{
    return (a + b >= M ? a + b - M : a + b < 0 ? a + b + M : a + b);
}

inline int mul(int a, int b)
{
    return (a * (ll) b) % M;
}

string str(int x)
{
    int it = 33;
    string s = "";
    while (it--)
    {
        s += (x % 2);
        x /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

int get(int n, int m, int k)
{
    if (n <= 0 || m <= 0 || k <= 0)
    {
        return 0;
    }
    for (int i = 0; i <=  N; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                for (int t = 0; t < 2; t++)
                {
                    dp[i][j][k][t] = cnt[i][j][k][t] = 0;
                }
            }
        }
    }
    cnt[0][0][0][0] = 1;
    string a = str(n), b = str(m), c = str(k);
    for (int i = 0; i < N; i++)
    {
        for (int bn = 0; bn < 2; bn++)
        {
            for (int bm = 0; bm < 2; bm++)
            {
                for (int bc = 0; bc < 2; bc++)
                {
                    for (int ca = 0; ca < 2; ca++)
                    {
                        for (int cb = 0; cb < 2; cb++)
                        {
                            int cc = (ca ^ cb);
                            if (!bn && ca > a[i])
                            {
                                continue;
                            }
                            if (!bm && cb > b[i])
                            {
                                continue;
                            }
                            if (!bc && cc > c[i])
                            {
                                continue;
                            }
                            int now_n = (bn | (ca < a[i]));
                            int now_m = (bm | (cb < b[i]));
                            int now_k = (bc | (cc < c[i]));
                            cnt[i + 1][now_n][now_m][now_k] = add(cnt[i + 1][now_n][now_m][now_k], cnt[i][bn][bm][bc]);
                            dp[i + 1][now_n][now_m][now_k] = add(dp[i + 1][now_n][now_m][now_k], add(mul(dp[i][bn][bm][bc], 2), mul(cnt[i][bn][bm][bc], cc)));
                        }
                    }
                }
            }
        }
    }
    return add(dp[N][1][1][1], cnt[N][1][1][1]);
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        int x = 0;
        x = add(x, get(x2, y2, k));
        x = add(x, -get(x1 - 1, y2, k));
        x = add(x, -get(x2, y1 - 1, k));
        x = add(x, get(x1 - 1, y1 - 1, k));
        cout << x << '\n';
    }
}