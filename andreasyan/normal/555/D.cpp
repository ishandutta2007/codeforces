#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2100);
const int N = 200005;

int n;
int a[N];
pair<int, int> b[N];
int u[N];

void solv()
{
    int qq;
    scanf("%d%d", &n, &qq);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        b[i] = m_p(a[i], i);
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i)
        u[b[i].se] = i;

    while (qq--)
    {
        int x, d;
        scanf("%d%d", &x, &d);
        x = u[x];
        bool z = false;

        if (n == 1)
        {
            printf("1\n");
            continue;
        }

        int qq = 0;

        while (1)
        {
            if (!z)
            {
                if (!(x < n && a[x] + d >= a[x + 1]))
                    z ^= true;
            }
            else
            {
                if (!(x > 1 && a[x] - d <= a[x - 1]))
                    z ^= true;
            }
            if (!z)
            {
                int y;
                y = upper_bound(a + 1, a + n + 1, a[x] + d) - a - 1;

                if (x == y)
                    break;

                if (!(y < n && a[y] + d >= a[y + 1]))
                {
                    if (a[y] - (d - abs(a[x] - a[y])) <= a[x])
                    {
                        if (x == 1 || a[y] - (d - abs(a[x] - a[y])) > a[x - 1])
                        {
                            int q = (d / abs(a[x] - a[y]));
                            d %= abs(a[x] - a[y]);

                            if (q % 2 == 1)
                            {
                                x = y;
                            }
                            continue;
                        }
                    }
                }
                d -= abs(a[x] - a[y]);
                x = y;
            }
            else
            {
                int y;
                y = lower_bound(a + 1, a + n + 1, a[x] - d) - a;

                if (x == y)
                    break;

                d -= abs(a[x] - a[y]);
                x = y;
            }
            assert(1 <= x && x <= n);
        }
        printf("%d\n", b[x].se);
    }
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