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
const int N = 500005, M = 998244353;

int n, k, m;
int l[N], r[N], x[N];

int p[N];

int maxu[N];

int t[N];

void solv()
{
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &l[i], &r[i], &x[i]);
    }
    int ans = 1;
    for (int b = 0; b < k; ++b)
    {
        memset(p, 0, sizeof p);
        memset(maxu, 0, sizeof maxu);
        for (int i = 1; i <= m; ++i)
        {
            if ((x[i] & (1 << b)))
            {
                ++p[l[i]];
                --p[r[i] + 1];
            }
            else
            {
                maxu[r[i]] = max(maxu[r[i]], l[i]);
            }
        }
        for (int i = 1; i <= n; ++i)
            p[i] += p[i - 1];
        memset(t, 0, sizeof t);
        //ubd(0, n, 0, 0, 1, 1);
        t[0] = 1;
        int s = 1;
        int j = 0;
        for (int i = 1; i <= n; ++i)
        {
            //ubd(0, n, 0, maxu[i] - 1, 0, 1);
            int u = s;
            while (j <= maxu[i] - 1)
            {
                s = (s - t[j] + M) % M;
                ++j;
            }
            if (!p[i])
            {
                //ubd(0, n, i, i, u, 1);
                t[i] = u;
                s = (s + u) % M;
            }
        }
        ans = (ans * 1LL * s) % M;
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}