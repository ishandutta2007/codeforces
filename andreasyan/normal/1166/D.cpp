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
const int N = 55;

ll ast[N];

ll yans[N];

void solv()
{
    ast[0] = 1;
    ast[1] = 1;
    for (int i = 2; i < N; ++i)
        ast[i] = ast[i - 1] * 2;

    ll a, b, m;
    scanf("%lld%lld%lld", &a, &b, &m);

    yans[0] = a;
    for (int i = 1; i < N; ++i)
    {
        yans[i] = 0;
        for (int j = 0; j < i; ++j)
            yans[i] += yans[j];
        ++yans[i];

        int n = i;
        ll ans[N] = {};
        for (int i = 0; i < n; ++i)
            ans[i] = yans[i];
        for (int i = 1; i < n; ++i)
        {
            ll q = 0;
            q = (b - ans[n - 1]) / (ast[n - 1 - i]);
            q = min(q, m - 1);
            for (int j = i; j < n; ++j)
                ans[j] += (q * ast[j - i]);
        }
        if (ans[n - 1] == b)
        {
            printf("%d ", n);
            for (int i = 0; i < n; ++i)
                printf("%lld ", ans[i]);
            printf("\n");
            return;
        }

        if (yans[i] > b)
        {
            break;
        }
    }
    printf("-1\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}