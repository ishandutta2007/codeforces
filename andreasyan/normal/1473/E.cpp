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

struct ban
{
    int x;
    ll d;
    bool minu, maxu;
    ban(){}
    ban(int x, ll d, bool minu, bool maxu)
    {
        this->x = x;
        this->d = d;
        this->minu = minu;
        this->maxu = maxu;
    }
};
bool operator<(const ban& a, const ban& b)
{
    return a.d > b.d;
}

int n, m;
vector<pair<int, int> > g[N];

bool c[N][2][2];
ll d[N][2][2];

void solv()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back(m_p(y, z));
        g[y].push_back(m_p(x, z));
    }

    priority_queue<ban> q;
    q.push(ban(1, 0, false, false));
    while (1)
    {
        ban t;
        do
        {
            if (q.empty())
            {
                for (int x = 2; x <= n; ++x)
                    cout << d[x][1][1] << ' ';
                cout << "\n";
                return;
            }
            t = q.top();
            q.pop();
        } while (c[t.x][t.minu][t.maxu]);
        c[t.x][t.minu][t.maxu] = true;
        d[t.x][t.minu][t.maxu] = t.d;
        for (int i = 0; i < g[t.x].size(); ++i)
        {
            ban h;
            h.x = g[t.x][i].fi;
            h.d = t.d + g[t.x][i].se;
            h.minu = t.minu;
            h.maxu = t.maxu;

            if (!c[h.x][h.minu][h.maxu])
                q.push(h);

            if (!h.minu)
            {
                h.d += g[t.x][i].se;
                h.minu = true;

                if (!c[h.x][h.minu][h.maxu])
                    q.push(h);

                h.d -= g[t.x][i].se;
                h.minu = false;
            }

            if (!h.maxu)
            {
                h.d -= g[t.x][i].se;
                h.maxu = true;

                if (!c[h.x][h.minu][h.maxu])
                    q.push(h);

                h.d += g[t.x][i].se;
                h.maxu = false;
            }

            if (!h.minu && !h.maxu)
            {
                h.minu = h.maxu = true;

                if (!c[h.x][h.minu][h.maxu])
                    q.push(h);
            }
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
    //scanf("%d", &tt);
    //cin >> tt;
    while (tt--)
        solv();
    return 0;
}