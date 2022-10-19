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

int n;
int a[N];
int b[N];
int q[N];

vector<pair<int, int> > g[N];
vector<int> gi[N];

bool c[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);

    for (int i = 1; i <= n; ++i)
        q[i] = 0;
    for (int i = 1; i <= n; ++i)
    {
        ++q[a[i]];
        ++q[b[i]];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (q[i] != 2)
        {
            printf("-1\n");
            return;
        }
    }

    for (int x = 1; x <= n; ++x)
    {
        g[x].clear();
        gi[x].clear();
    }
    for (int i = 1; i <= n; ++i)
    {
        g[a[i]].push_back(m_p(b[i], 0));
        g[b[i]].push_back(m_p(a[i], 1));
        gi[a[i]].push_back(i);
        gi[b[i]].push_back(i);
    }

    for (int x = 1; x <= n; ++x)
        c[x] = false;

    vector<int> ans;
    for (int x = 1; x <= n; ++x)
    {
        if (c[x])
            continue;
        if (g[x][0].fi == g[x][1].fi)
        {
            c[x] = true;
            c[g[x][0].fi] = true;
            if (g[x][0].se == g[x][1].se)
            {
                ans.push_back(gi[x][0]);
            }
            continue;
        }

        int p = -1;
        int y = x;
        vector<int> vi;
        vector<int> vz;
        while (1)
        {
            c[y] = true;
            int hh = -1;
            int hi = -1;
            int hz = -1;
            for (int i = 0; i < g[y].size(); ++i)
            {
                int h = g[y][i].fi;
                if (h != p)
                {
                    hh = h;
                    hz = g[y][i].se;
                    hi = gi[y][i];
                }
            }
            assert(hh != -1);
            vi.push_back(hi);
            vz.push_back(hz);
            p = y;
            y = hh;
            if (y == x)
                break;
        }
        int q[2] = {};
        for (int i = 0; i < vz.size(); ++i)
        {
            q[vz[i]]++;
        }
        if (q[0] < q[1])
        {
            for (int i = 0; i < vz.size(); ++i)
            {
                if (vz[i] == 0)
                    ans.push_back(vi[i]);
            }
        }
        else
        {
            for (int i = 0; i < vz.size(); ++i)
            {
                if (vz[i] == 1)
                    ans.push_back(vi[i]);
            }
        }
    }

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i]);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}