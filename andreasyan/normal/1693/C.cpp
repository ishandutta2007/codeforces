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
vector<int> g[N], rg[N];

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
int yans[N];
int q0[N];

void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        g[i].clear();
        rg[i].clear();
        c[i] = false;
    }
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        rg[y].push_back(x);
    }

    for (int x = 1; x <= n; ++x)
    {
        yans[x] = N * 4;
        q0[x] = sz(g[x]);
    }

    priority_queue<ban> q;
    q.push(ban(n, 0));
    while (1)
    {
        ban t;
        do
        {
            t = q.top();
            q.pop();
        } while (c[t.x]);
        c[t.x] = true;
        if (t.x == 1)
        {
            cout << t.d << "\n";
            return;
        }

        for (int i = 0; i < rg[t.x].size(); ++i)
        {
            int h = rg[t.x][i];
            if (c[h])
                continue;
            --q0[h];
            yans[h] = min(yans[h], t.d + q0[h] + 1);
            q.push(ban(h, yans[h]));
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}