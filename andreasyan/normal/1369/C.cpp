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

int n, k;
int a[N], w[N];

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= k; ++i)
        scanf("%d", &w[i]);
    sort(w + 1, w + k + 1);
    reverse(w + 1, w + k + 1);
    ll ans = 0;
    int l = 1, r = n;
    for (int i = k; i >= 1; --i)
    {
        if (w[i] > 1)
            break;
        ans += 2 * a[r];
        --r;
    }
    for (int i = 1; i <= k; ++i)
    {
        if (w[i] == 1)
            break;
        ans += a[r];
        --r;
        if (w[i] == 1)
        {
            ans += a[r + 1];
            continue;
        }
        ans += a[l];
        l += (w[i] - 1);
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
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}