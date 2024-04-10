#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 5003;
const ll INF = 1000000009000000009;

int n, s, e;
int x[N], tl[N], tr[N], vl[N], vr[N];

ll dp[N][2][2];
ll ndp[N][2][2];

void ubd(ll& x, ll y)
{
    x = min(x, y);
}

void solv()
{
    scanf("%d", &n);
    scanf("%d%d", &s, &e);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &x[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &vl[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &vr[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &tl[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &tr[i]);
    for (int q = 0; q < N; ++q)
    {
        for (int ss = 0; ss < 2; ++ss)
        {
            for (int ee = 0; ee < 2; ++ee)
            {
                dp[q][ss][ee] = INF;
            }
        }
    }
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int q = 0; q < N; ++q)
        {
            for (int ss = 0; ss < 2; ++ss)
            {
                for (int ee = 0; ee < 2; ++ee)
                {
                    ndp[q][ss][ee] = INF;
                }
            }
        }
        for (int q = 0; q <= n; ++q)
        {
            for (int ss = 0; ss < 2; ++ss)
            {
                for (int ee = 0; ee < 2; ++ee)
                {
                    if (dp[q][ss][ee] == INF)
                        continue;
                    if (i + 1 == s)
                    {
                        // . ->
                        ubd(ndp[q][1][ee], dp[q][ss][ee] + tr[i + 1] - x[i + 1]);
                        // . <-
                        if (q)
                            ubd(ndp[q - 1][1][ee], dp[q][ss][ee] + tl[i + 1] + x[i + 1]);
                        if (ee)
                            ubd(ndp[q][0][0], dp[q][ss][ee] + tl[i + 1] + x[i + 1]);
                    }
                    else if (i + 1 == e)
                    {
                        // <- .
                        ubd(ndp[q][ss][1], dp[q][ss][ee] + vr[i + 1] - x[i + 1]);
                        // -> .
                        if (q)
                            ubd(ndp[q - 1][ss][1], dp[q][ss][ee] + vl[i + 1] + x[i + 1]);
                        if (ss)
                            ubd(ndp[q][0][0], dp[q][ss][ee] + vl[i + 1] + x[i + 1]);
                    }
                    else
                    {
                        // -> ->
                        if (q || ss)
                            ubd(ndp[q][ss][ee], dp[q][ss][ee] + vl[i + 1] + tr[i + 1]);
                        // -> <-
                        if (q >= 2 || (ss && q) || (ee && q))
                            ubd(ndp[q - 1][ss][ee], dp[q][ss][ee] + vl[i + 1] + tl[i + 1] + 2 * x[i + 1]);
                        if (ss && ee)
                            ubd(ndp[q][0][0], dp[q][ss][ee] + vl[i + 1] + tl[i + 1] + 2 * x[i + 1]);
                        // <- <-
                        if (q || ee)
                            ubd(ndp[q][ss][ee], dp[q][ss][ee] + vr[i + 1] + tl[i + 1]);
                        // <- ->
                        ubd(ndp[q + 1][ss][ee], dp[q][ss][ee] + vr[i + 1] + tr[i + 1] - 2 * x[i + 1]);
                    }
                }
            }
        }
        for (int q = 0; q <= n; ++q)
        {
            for (int ss = 0; ss < 2; ++ss)
            {
                for (int ee = 0; ee < 2; ++ee)
                {
                    dp[q][ss][ee] = ndp[q][ss][ee];
                }
            }
        }
    }
    printf("%lld\n", dp[0][0][0]);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}