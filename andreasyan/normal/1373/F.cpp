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
const int N = 1000006;
const ll INF = 1000000009000000009;

int n;
int a[N * 2];
int b[N * 2];

ll pa[N * 2];
ll pb[N * 2];

bool solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &b[i]);
    }
    for (int i = n + 1; i <= n * 2; ++i)
    {
        a[i] = a[i - n];
        b[i] = b[i - n];
    }
    for (int i = 1; i <= n * 2; ++i)
    {
        pa[i] = pa[i - 1] + a[i];
        pb[i] = pb[i - 1] + b[i];
    }
    if (pa[n] > pb[n])
        return false;
    ll minu = INF;
    for (int i = 2; i <= n * 2; ++i)
    {
        if (pa[i] - pb[i] > minu)
            return false;
        minu = min(minu, pa[i] - pb[i - 1]);
    }
    return true;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        if (solv())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}