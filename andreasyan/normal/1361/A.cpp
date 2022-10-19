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

int n, m;
vector<int> g[N];
int a[N];
pair<int, int> b[N];

bool c[N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        b[i].fi = a[i];
        b[i].se = i;
    }
    sort(b + 1, b + n + 1);
    for (int ii = 1; ii <= n; ++ii)
    {
        int x = b[ii].se;
        for (int j = 0; j < g[x].size(); ++j)
        {
            int h = g[x][j];
            if (a[h] == a[x])
            {
                printf("-1\n");
                return;
            }
            if (a[h] < a[x])
            {
                c[a[h]] = true;
            }
        }
        bool z = true;
        for (int j = 1; j < a[x]; ++j)
        {
            if (!c[j])
            {
                z = false;
                break;
            }
            c[j] = false;
        }
        if (!z)
        {
            printf("-1\n");
            return;
        }
    }
    for (int ii = 1; ii <= n; ++ii)
    {
        int x = b[ii].se;
        printf("%d ", x);
    }
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}