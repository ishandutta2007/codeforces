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
int a[N];
pair<int, int> b[N];
vector<int> g[N];
vector<int> gi[N];

int q[N];

bool c[N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
        gi[x].push_back(i);
        gi[y].push_back(i);
        b[i] = m_p(x, y);
    }

    vector<int> ans;
    set<pair<int, int> > s;
    for (int x = 1; x <= n; ++x)
    {
        q[x] = a[x] - sz(g[x]);
        s.insert(m_p(q[x], x));
    }

    while (!s.empty())
    {
        int x = (--s.end())->se;
        s.erase((--s.end()));
        if (q[x] < 0)
        {
            printf("DEAD\n");
            return;
        }
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            int hi = gi[x][i];
            if (c[hi])
                continue;
            c[hi] = true;
            ans.push_back(hi);
            s.erase(m_p(q[h], h));
            ++q[h];
            s.insert(m_p(q[h], h));
        }
    }
    reverse(all(ans));

    printf("ALIVE\n");
    for (int i = 0; i < m; ++i)
        printf("%d ", ans[i] + 1);
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