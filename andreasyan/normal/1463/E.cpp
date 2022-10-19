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

int n, k;
int p[N];
vector<int> g[N];

int hl[N], hr[N];

int u[N];

bool c[N];
int q[N];

void solv()
{
    scanf("%d%d", &n, &k);
    for (int x = 1; x <= n; ++x)
    {
        scanf("%d", &p[x]);
        g[p[x]].push_back(x);
    }

    for (int i = 0; i < k; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);

        if (hr[x])
        {
            printf("0\n");
            return;
        }
        hr[x] = y;

        if (hl[y])
        {
            printf("0\n");
            return;
        }
        hl[y] = x;
    }

    for (int x = 1; x <= n; ++x)
    {
        if (hl[x])
            continue;

        int y = x;
        while (1)
        {
            u[y] = x;
            if (!hr[y])
                break;
            y = hr[y];
        }
    }

    c[0] = true;
    for (int x = 1; x <= n; ++x)
    {
        if (!c[p[x]] && u[p[x]] != u[x])
            q[u[x]]++;
    }

    set<pair<int, int> > s;
    for (int x = 1; x <= n; ++x)
    {
        if (hl[x])
            continue;
        s.insert(m_p(q[x], x));
    }

    vector<int> ans;
    while (!s.empty())
    {
        int x = s.begin()->se;
        s.erase(s.begin());

        if (q[x])
        {
            printf("0\n");
            return;
        }

        int y = x;
        while (1)
        {
            if (!c[p[y]])
            {
                printf("0\n");
                return;
            }
            ans.push_back(y);
            c[y] = true;
            for (int i = 0; i < g[y].size(); ++i)
            {
                int h = g[y][i];
                if (u[h] != u[y])
                {
                    s.erase(m_p(q[u[h]], u[h]));
                    --q[u[h]];
                    s.insert(m_p(q[u[h]], u[h]));
                }
            }
            if (!hr[y])
                break;
            y = hr[y];
        }
    }

    assert(sz(ans) == n);
    for (int i = 0; i < n; ++i)
        printf("%d ", ans[i]);
    printf("\n");
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