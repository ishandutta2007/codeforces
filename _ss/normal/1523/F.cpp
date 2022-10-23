#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 1 << 14, inf = 1e9;

struct quest
{
    pii cord;
    int t;
};

pii towers[N];
quest quests[N];
int n, m;

bool cmp(const quest &obj1, const quest &obj2) { return obj1.t < obj2.t; }

int dist(pii c1, pii c2) { return abs(c1.fi - c2.fi) + abs(c1.se - c2.se);}

int dmt[N][20], dmq[N][110], dqt[110][20], dqq[110][110], f[110][N], g[110][N], T[N];
vi states[2][110];

bool minimize(int &x, int y)
{
    if (y >= x) return false;
    x = y;
    return true;
}

bool maximize(int &x, int y)
{
    if (y <= x) return false;
    x = y;
    return true;
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> towers[i].fi >> towers[i].se;
    for (int i = 1; i <= m; ++i) cin >> quests[i].cord.fi >> quests[i].cord.se >> quests[i].t;
    sort(quests + 1, quests + m + 1, cmp);
    for (int i = 1; i <= m; ++i) T[i] = quests[i].t;
    for (int mask = 0; mask < (1 << n); ++mask)
    {
        for (int i = 1; i <= n; ++i)
        {
            dmt[mask][i] = inf;
            for (int j = 0; j < n; ++j)
                if ((mask >> j) & 1) dmt[mask][i] = min(dmt[mask][i], dist(towers[j + 1], towers[i]));
        }
        for (int i = 1; i <= m; ++i)
        {
            dmq[mask][i] = inf;
            for (int j = 0; j < n; ++j)
                if ((mask >> j) & 1) dmq[mask][i] = min(dmq[mask][i], dist(towers[j + 1], quests[i].cord));
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j) dqt[i][j] = dist(quests[i].cord, towers[j]);
        for (int j = 1; j <= m; ++j) dqq[i][j] = dist(quests[i].cord, quests[j].cord);
    }
    for (int i = 0; i <= m; ++i)
        for (int mask = 0; mask < (1 << n); ++mask) g[i][mask] = inf, f[i][mask] = -inf;
    for (int i = 0; i < n; ++i) g[0][1 << i] = 0;
    for (int i = 1; i <= m; ++i) f[i][0] = 1, states[1][i].eb(0);
    for (int i = 0; i <= m; ++i)
    {
        int flag = 0, nw = i & 1, nxt = nw ^ 1;
        for (int id = 1; id <= m; ++id)
            if (!states[nw][id].empty()) flag = 1;
        if (i > 0 && !flag)
        {
            cout << i - 1;
            return 0;
        }
        for (int id = 1; id <= m; ++id)
        {
            for (int mask : states[nw][id])
            {
                if (f[id][mask] > i) continue;
                for (int j = 0; j < n; ++j)
                    if (((mask >> j) & 1) == 0)
                        minimize(g[i][mask | (1 << j)], T[id] + min(dmt[mask][j + 1], dqt[id][j + 1]));
                for (int j = id + 1; j <= m; ++j)
                    if (T[id] + min(dmq[mask][j], dqq[id][j]) <= T[j])
                    {
                        if (maximize(f[j][mask], i + 1)) states[nxt][j].eb(mask);
                    }
            }
            states[nw][id].clear();
        }
        for (int mask = 0; mask < (1 << n); ++mask)
        {
            for (int j = 0; j < n; ++j)
                if (((mask >> j) & 1) == 0)
                    minimize(g[i][mask | (1 << j)], g[i][mask] + dmt[mask][j + 1]);
            for (int j = 1; j <= m; ++j)
                if (g[i][mask] + dmq[mask][j] <= T[j])
                {
                    if (maximize(f[j][mask], i + 1)) states[nxt][j].eb(mask);
                }
        }
    }
    cout << m;
    return 0;
}