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
const int N = 500005, INF = 1000000009;

int n, m;
vector<pair<int, int> > g[N], rg[N];

struct ban
{
    int x, d;
    ban(){}
    ban(int x, int d)
    {
        this->x = x;
        this->d = d;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.d > b.d;
}

bool c[N];
int d[N][2];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g[x].push_back(m_p(y, z));
        rg[y].push_back(m_p(x, z));
    }

    for (int x = 1; x <= n; ++x)
    {
        d[x][0] = d[x][1] = INF;
    }
    d[n][0] = d[n][1] = 0;
    priority_queue<ban> q;
    q.push(ban(n, 0));
    while (1)
    {
        ban t;
        bool f = true;
        do
        {
            if (q.empty())
            {
                f = false;
                break;
            }
            t = q.top();
            q.pop();
        } while (c[t.x]);
        if (!f)
            break;
        c[t.x] = true;
        for (int i = 0; i < sz(rg[t.x]); ++i)
        {
            int h = rg[t.x][i].fi;
            int gg = rg[t.x][i].se;
            d[h][gg] = min(d[h][gg], t.d + 1);
            if (!c[h])
            {
                q.push(ban(h, max(d[h][0], d[h][1])));
            }
        }
    }
    if (max(d[1][0], d[1][1]) >= INF)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", max(d[1][0], d[1][1]));
    }
    for (int x = 1; x <= n; ++x)
    {
        if (d[x][1] > d[x][0])
            printf("1");
        else
            printf("0");
    }
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

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}