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
const int N = 500005;

int n, k;
int a[N];

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    ++k;

    int j = n + 1;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] >= 0)
        {
            j = i;
            break;
        }
    }
    ll pp = 0;
    ll ps = 0;
    for (int i = j; i <= n; ++i)
    {
        pp += (a[i] * 1LL * (i - j));
        ps += a[i];
    }

    ll mm = 0;
    for (int i = 1; i <= j - 1; ++i)
    {
        mm += (a[i] * 1LL * ((i - 1) / k));
    }

    ll yans = mm + pp + ((j - 1) / k + !!((j - 1) % k)) * 1LL * ps;
    ll ans = yans;

    ll ms = 0;
    int u = j - 1;
    if ((u - 1) % k == 0)
        ms += a[u--];
    for (int i = 1; i <= j - 1 - ((j - 1) / k + !!((j - 1) % k)); ++i)
    {
        ms += a[u--];
        yans += ms;
        if ((u - 1) % k == 0)
            ms += a[u--];
        yans += ps;
        ans = max(ans, yans);
    }

    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}