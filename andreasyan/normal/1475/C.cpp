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
const int N = 200005;

int n, m, k;
int a[N], b[N];

int qa[N], qb[N];

void solv()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= k; ++i)
        scanf("%d", &b[i]);

    for (int i = 1; i <= n; ++i)
        qa[i] = 0;
    for (int i = 1; i <= m; ++i)
        qb[i] = 0;
    for (int i = 1; i <= k; ++i)
    {
        qa[a[i]]++;
        qb[b[i]]++;
    }

    ll ans = 0;
    for (int i = 1; i <= k; ++i)
    {
        ans += (k - qa[a[i]] - qb[b[i]] + 1);
    }

    ans /= 2;
    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}