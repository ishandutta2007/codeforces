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
const int N = 1000006;

int n;
vector<int> g[N];

int d[N];
int t[N];
void dfss(int x, int p)
{
    if (x == p)
        d[x] = 0;
    else
        d[x] = d[p] + 1;
    if (sz(g[x]) == 1)
        t[x] = 0;
    else
        t[x] = N;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfss(h, x);
        t[x] = min(t[x], t[h] + 1);
    }
}

void dfsf(int x, int p, int tp)
{
    t[x] = min(t[x], tp + 1);
    int min1 = tp;
    int h1 = p;
    int min2 = tp;
    int h2 = p;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (t[h] <= min1)
        {
            min2 = min1;
            h2 = h1;
            min1 = t[h];
            h1 = h;
        }
        else if (t[h] <= min2)
        {
            min2 = t[h];
            h2 = h;
        }
    }

    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (h != h1)
            dfsf(h, x, min1 + 1);
        else
            dfsf(h, x, min2 + 1);
    }
}

int X;
int ans;

vector<int> v[N];
int qd;
void dfs(int x, int p)
{
    v[x].clear();
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        if (sz(v[h]) > sz(v[x]))
        {
            swap(v[h], v[x]);
        }

        for (int i = 0; i < sz(v[h]); ++i)
        {
            ++qd;
            while (1)
            {
                int j = max(ans - i - X + 1, 0);
                if (j >= sz(v[x]))
                    break;
                if (v[h][i] + v[x][j] - 2 * d[x] > ans)
                    ++ans;
                else
                    break;
            }
        }
        for (int i = 0; i < sz(v[h]); ++i)
        {
            v[x][i] = max(v[x][i], v[h][i]);
        }
    }
    while (1)
    {
        int j = max(ans - t[x] - X + 1, 0);
        if (j >= sz(v[x]))
            break;
        if (d[x] + v[x][j] - 2 * d[x] > ans)
            ++ans;
        else
            break;
    }
    if (t[x] < sz(v[x]))
        v[x][t[x]] = max(v[x][t[x]], d[x]);
    else
        v[x].push_back(d[x]);
}

void solv()
{
    cin >> n;
    for (int x = 2; x <= n; ++x)
    {
        int p;
        p = rnf() % (x - 1) + 1;
        //p = x - min(x - 1, (int)rnf() % 4 + 1);
        cin >> p;
        g[p].push_back(x);
        g[x].push_back(p);
    }

    int r;
    for (r = 1; r <= n; ++r)
    {
        if (sz(g[r]) >= 2)
        {
            dfss(r, r);
            dfsf(r, r, N);
            break;
        }
    }

    int qq;
    cin >> qq;
    for (int i = 1; i <= qq; ++i)
    {
        X = rnf() % n + 1;
        cin >> X;

        ans = 0;
        qd = 0;
        dfs(r, r);
        assert(qd <= n);

        cout << ans << ' ';
    }
    cout << "\n";
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