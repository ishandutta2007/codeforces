#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 300005, INF = 1000000009;

int n;
int x[N];
char c[N];

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d %c", &x[i], &c[i]);
    for (int i = 1; i <= n; ++i)
    {
        if (c[i] == 'P')
        {
            c[i] = 'G';
        }
    }
    long long ans = 0;
    int lR = INF, lB = INF, lG = INF;
    for (int i = 1; i <= n; ++i)
    {
        if (c[i] == 'R')
        {
            if (lR == INF)
            {
                lR = x[i];
            }
        }
        else if (c[i] == 'B')
        {
            if (lB == INF)
            {
                lB = x[i];
            }
        }
        else
        {
            lG = x[i];
            break;
        }
    }
    int rR = -INF, rB = -INF, rG = -INF;
    for (int i = n; i >= 1; --i)
    {
        if (c[i] == 'R')
        {
            if (rR == -INF)
                rR = x[i];
        }
        else if (c[i] == 'B')
        {
            if (rB == -INF)
                rB = x[i];
        }
        else
        {
            rG = x[i];
            break;
        }
    }
    if (rG == -INF)
    {
        if (rB != -INF)
            ans += (rB - lB);
        if (rR != -INF)
            ans += (rR - lR);
        printf("%I64d\n", ans);
        return 0;
    }
    if (lR != INF)
        ans += (lG - lR);
    if (lB != INF)
        ans += (lG - lB);
    if (rR != -INF)
        ans += (rR - rG);
    if (rB != -INF)
        ans += (rB - rG);
    for (int i = 1; i <= n; ++i)
    {
        if (c[i] == 'G')
        {
            if (x[i] == rG)
                break;
            int vR = x[i], vB = x[i];
            int maxR = -INF, maxB = -INF;
            for (int j = i + 1; j <= n; ++j)
            {
                if (c[j] == 'R')
                {
                    maxR = max(maxR, x[j] - vR);
                    vR = x[j];
                }
                else if (c[j] == 'B')
                {
                    maxB = max(maxB, x[j] - vB);
                    vB = x[j];
                }
                else
                {
                    maxR = max(maxR, x[j] - vR);
                    maxB = max(maxB, x[j] - vB);
                    if (vR == vB)
                    {
                        ans += (x[j] - x[i]);
                    }
                    else
                    {
                        ans += min((x[j] - x[i]) * 2LL, (x[j] - x[i]) * 3LL - maxR - maxB);
                    }
                    break;
                }
            }
        }
    }
    printf("%I64d\n", ans);
    return 0;
}