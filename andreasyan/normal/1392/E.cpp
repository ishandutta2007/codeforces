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
const int N = 30;

int n;
ll a[N][N];

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i % 2 == 0)
                a[i][j] = (1LL << (i + j));
            else
                a[i][j] = 0;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            printf("%lld ", a[i][j]);
        printf("\n");
    }
    fflush(stdout);

    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        ll s;
        scanf("%lld", &s);

        vector<pair<int, int> > ans;
        int x = 0, y = 0;
        ans.push_back(m_p(x, y));
        for (int i = 1; ; ++i)
        {
            if (x == n - 1 && y == n - 1)
                break;
            if (x == n - 1)
                ++y;
            else if (y == n - 1)
                ++x;
            else
            {
                if (a[x][y + 1])
                {
                    if ((s & a[x][y + 1]))
                        ++y;
                    else
                        ++x;
                }
                else
                {
                    if ((s & a[x + 1][y]))
                        ++x;
                    else
                        ++y;
                }
            }
            ans.push_back(m_p(x, y));
        }
        for (int i = 0; i < sz(ans); ++i)
            printf("%d %d\n", ans[i].fi + 1, ans[i].se + 1);
        fflush(stdout);
    }
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}