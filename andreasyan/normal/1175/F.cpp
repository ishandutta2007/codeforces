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
const int N = 300005;

int n;
int a[N];

int ans;
bool c[N];
int maxu[N];
int t[N];
void rec(int l, int r)
{
    if (l == r)
    {
        if (a[l] == 1)
            ++ans;
        return;
    }
    int m = (l + r) / 2;
    rec(l, m);
    rec(m + 1, r);

    int ur = r;
    for (int i = m + 1; i <= r; ++i)
    {
        if (c[a[i]])
        {
            ur = i - 1;
            break;
        }
        c[a[i]] = true;
    }
    for (int i = l; i <= r; ++i)
        c[a[i]] = false;

    int ul = l;
    for (int i = m; i >= l; --i)
    {
        if (c[a[i]])
        {
            ul = i + 1;
            break;
        }
        c[a[i]] = true;
    }
    for (int i = l; i <= r; ++i)
        c[a[i]] = false;

    maxu[m + 1] = a[m + 1];
    for (int i = m + 2; i <= r; ++i)
        maxu[i] = max(maxu[i - 1], a[i]);

    maxu[m] = a[m];
    for (int i = m - 1; i >= l; --i)
        maxu[i] = max(maxu[i + 1], a[i]);

    for (int i = l; i <= m; ++i)
        t[a[i]] = i;
    int g = l;
    for (int i = m + 1; i <= ur; ++i)
    {
        if (t[a[i]])
            g = max(g, t[a[i]] + 1);
        int j = i - maxu[i] + 1;
        if (j >= max(ul, g) && j <= m)
        {
            if (maxu[j] <= maxu[i])
                ++ans;
        }
    }
    for (int i = l; i <= r; ++i)
        t[a[i]] = 0;

    for (int i = r; i >= m + 1; --i)
        t[a[i]] = i;
    g = r;
    for (int i = m; i >= ul; --i)
    {
        if (t[a[i]])
            g = min(g, t[a[i]] - 1);
        int j = maxu[i] + i - 1;
        if (j <= min(ur, g) && j >= m + 1)
        {
            if (maxu[j] < maxu[i])
                ++ans;
        }
    }
    for (int i = l; i <= r; ++i)
        t[a[i]] = 0;
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    rec(1, n);
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