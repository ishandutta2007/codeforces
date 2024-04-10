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

int n, m;
int a[N], b[N];

int s[N];
int solvd()
{
    int u = n + 1;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] > 0)
        {
            u = i;
            break;
        }
    }
    s[n + 1] = 0;
    for (int i = n; i >= u; --i)
    {
        s[i] = s[i + 1];
        if (binary_search(b + 1, b + m + 1, a[i]))
            ++s[i];
    }

    int ans = s[u];
    int j = 0;
    for (int i = u; i <= n; ++i)
    {
        while (j <= m && b[j] < a[i])
            ++j;
        for (int k = j; k <= m; ++k)
        {
            if (i != n && b[k] >= a[i + 1])
                break;
            int l = 1, r = k;
            int yans = 0;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (b[mid] >= b[k] - (i - u + 1) + 1)
                {
                    yans = (k - mid + 1);
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            ans = max(ans, yans + s[i + 1]);
        }
    }
    return ans;
}

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &b[i]);

    int ans = solvd();
    for (int i = 1; i <= n; ++i)
        a[i] *= -1;
    for (int i = 1; i <= m; ++i)
        b[i] *= -1;
    reverse(a + 1, a + n + 1);
    reverse(b + 1, b + m + 1);
    ans += solvd();

    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}