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
vector<pair<int, int> > g[N];
vector<int> v[10];

bool r[10][10];
bitset<N> u[10][10];

bool c[10][10][10][10];

int h[10][10];
ll a[10][10];

int ans = 0;
void rec(int s, ll aa)
{
    if (s == k + 1)
    {
        ++ans;
        return;
    }
    for (int i = 0; i < s; ++i)
    {
        if (!r[s][i])
            continue;
        if (!(aa & (1LL << h[s][i])))
        {
            rec(s + 1, (aa | a[s][i]));
        }
    }
}

void solv()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g[x].push_back(m_p(z, y));
    }
    for (int x = 1; x <= n; ++x)
    {
        sort(all(g[x]));
        v[sz(g[x])].push_back(x);
    }
    for (int s = 1; s <= k; ++s)
    {
        for (int i = 0; i < s; ++i)
        {
            bool z = true;
            for (int j = 0; j < v[s].size(); ++j)
            {
                int x = v[s][j];
                if (u[s][i][g[x][i].se] == 1)
                {
                    z = false;
                    break;
                }
                u[s][i][g[x][i].se] = 1;
            }
            r[s][i] = z;
        }
    }

    int z = 0;
    for (int s = 1; s <= k; ++s)
    {
        for (int i = 0; i < s; ++i)
        {
            h[s][i] = z++;
        }
    }

    for (int s1 = 1; s1 <= k; ++s1)
    {
        for (int i1 = 0; i1 < s1; ++i1)
        {
            for (int s2 = s1 + 1; s2 <= k; ++s2)
            {
                for (int i2 = 0; i2 < s2; ++i2)
                {
                    if ((u[s1][i1] & u[s2][i2]).count() == 0)
                        c[s1][i1][s2][i2] = true;
                    if (c[s1][i1][s2][i2] == false)
                        a[s1][i1] |= (1LL << h[s2][i2]);
                }
            }
        }
    }

    /*for (int x = 1; x <= n; ++x)
    {
        for (int i = 0; i < g[x].size(); ++i)
            printf("%d ", g[x][i].se);
        printf("\n");
    }*/

    rec(1, 0);
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