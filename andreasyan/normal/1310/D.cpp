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
const int N = 88, K = 12, INF = 1000000009;

int n, k;
int a[N][N];

int ans = INF;

vector<pair<int, int> > u[N][N];

vector<int> v;
int c[N];
void rec(int i)
{
    if (i == k)
    {
        int yans = 0;
        for (int i = 0; i < v.size() - 1; ++i)
        {
            bool z = false;
            for (int j = 0; j < u[v[i]][v[i + 1]].size(); ++j)
            {
                if (!c[u[v[i]][v[i + 1]][j].se])
                {
                    yans += u[v[i]][v[i + 1]][j].fi;
                    z = true;
                    break;
                }
            }
            if (!z)
                return;
        }
        ans = min(ans, yans);
        return;
    }
    if (i == k - 2)
    {
        ++c[1];
        v.push_back(1);
        rec(i + 2);
        v.pop_back();
        --c[1];
        return;
    }
    for (int x = 1; x <= n; ++x)
    {
        ++c[x];
        v.push_back(x);
        rec(i + 2);
        v.pop_back();
        --c[x];
    }
}

void solv()
{
    scanf("%d%d", &n, &k);
    ++k;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int x = 1; x <= n; ++x)
    {
        for (int y = 1; y <= n; ++y)
        {
            for (int z = 1; z <= n; ++z)
            {
                if (z == x || z == y)
                    continue;
                u[x][y].push_back(m_p(a[x][z] + a[z][y], z));
            }
            sort(u[x][y].begin(), u[x][y].end());
        }
    }
    ++c[1];
    v.push_back(1);
    rec(1);
    v.pop_back();
    --c[1];
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}