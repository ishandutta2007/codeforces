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
const int N = 502;

bool solvv(int x, int y)
{
    if (x > y)
        return false;
    vector<int> vx;
    vector<int> vy;
    for (int i = 0; i < 30; ++i)
    {
        if ((x & (1 << i)))
            vx.push_back(i);
    }
    for (int i = 0; i < 30; ++i)
    {
        if ((y & (1 << i)))
            vy.push_back(i);
    }
    if (sz(vy) > sz(vx))
        return false;

    for (int i = 0; i < sz(vy); ++i)
    {
        if (vx[i] > vy[i])
            return false;
    }
    return true;
}

vector<int> g[N];
bool c[N];
void dfs(int x)
{
    if (c[x])
        return;
    c[x] = true;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        dfs(h);
    }
}

bool solvv0(int x, int y)
{
    memset(c, false, sizeof c);
    dfs(x);
    return c[y];
}

void solv()
{
    /*for (int x = 1; x < N; ++x)
    {
        for (int y = 1; x + y < N; ++y)
        {
            if ((x & y) == y)
                g[x].push_back(x + y);
        }
    }

    for (int x = 1; x < N; ++x)
    {
        for (int y = 1; y < N; ++y)
        {
            assert(solvv(x, y) == solvv0(x, y));
        }
    }

    memset(c, false, sizeof c);
    int x = 35;
    for (int i = 9; i >= 0; --i)
    {
        if ((x & (1 << i)))
            printf("1");
        else
            printf("0");
    }
    printf("\n");
    printf("\n");
    dfs(x);
    for (int x = 1; x < N; ++x)
    {
        if (c[x])
        {
            for (int i = 9; i >= 0; --i)
            {
                if ((x & (1 << i)))
                    printf("1");
                else
                    printf("0");
            }
            printf("\n");
        }
    }
    return;*/

    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (solvv(x, y))
            printf("YES\n");
        else
            printf("NO\n");
        //assert(solvv(x, y) == solvv0(x, y));
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}