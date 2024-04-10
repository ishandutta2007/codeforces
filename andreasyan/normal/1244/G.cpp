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
ll k;
int a[N];

void por()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        a[i] = a[i - 1] + rnd() % 10;
    set<int> s;
    do
    {
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            ans += max(i, a[i]);
        }
        s.insert(ans);
    } while (next_permutation(a + 1, a + n + 1));
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
        printf("%d\n", *it);
}

ll s[N];
ll t[N * 4];

void ubd(int tl, int tr, int x, ll y, int pos)
{
    if (tl == tr)
    {
        t[pos] = y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
}

int qry(int tl, int tr, int i, int pos)
{
    if (k - max(i * 1LL, t[pos]) - s[i + 1] < 0)
        return -1;
    if (tl == tr)
        return tl;
    int m = (tl + tr) / 2;
    int u = qry(m + 1, tr, i, pos * 2 + 1);
    if (u != -1)
        return u;
    return qry(tl, m, i, pos * 2);
}

void solv()
{
    scanf("%d%lld", &n, &k);
    for (int i = n; i >= 1; --i)
        s[i] = s[i + 1] + i;
    if (k < s[1])
    {
        printf("-1\n");
        return;
    }
    for (int i = 1; i <= n; ++i)
        ubd(1, n, i, i, 1);
    for (int i = 1; i <= n; ++i)
    {
        int l = 1, r = n;
        int ans = qry(1, n, i, 1);
        k -= max(i, ans);
        a[i] = ans;
        ubd(1, n, ans, INF, 1);
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += max(i, a[i]);
    printf("%lld\n", ans);
    for (int i = 1; i <= n; ++i)
        printf("%d ", i);
    printf("\n");
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //por();
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}