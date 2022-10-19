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
const int N = 600005;

int n;
int t[N][26];

int q[N];
vector<int> vv[N];
void dfs0(int x, int d)
{
    vv[d].push_back(x);
    q[x] = 1;
    for (int i = 0; i < 26; ++i)
    {
        int h = t[x][i];
        if (!h)
            continue;
        dfs0(h, d + 1);
        q[x] += q[h];
    }
}

int ans;
vector<pair<pair<int, int>, int> > v;
int ave(int pos1, int pos2)
{
    if (!pos1 && !pos2)
        return 0;
    if (!pos2)
        return pos1;
    if (!pos1)
    {
        ans += q[pos2];
        return pos2;
    }
    for (int i = 0; i < 26; ++i)
    {
        v.push_back(m_p(m_p(pos1, i), t[pos1][i]));
        t[pos1][i] = ave(t[pos1][i], t[pos2][i]);
    }
    return pos1;
}

void solvv(int x)
{
    int maxu = -1, maxh = -1;
    for (int i = 0; i < 26; ++i)
    {
        int h = t[x][i];
        if (!h)
            continue;
        if (q[h] > maxu)
        {
            maxu = q[h];
            maxh = h;
        }
    }
    if (maxu == -1)
    {
        ++ans;
        return;
    }
    ans += maxu;
    for (int i = 0; i < 26; ++i)
    {
        int h = t[x][i];
        if (!h)
            continue;
        if (h == maxh)
            continue;
        assert(maxh == ave(maxh, h));
    }
    reverse(all(v));
    for (int i = 0; i < sz(v); ++i)
    {
        t[v[i].fi.fi][v[i].fi.se] = v[i].se;
    }
    v.clear();
}

void solv()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        char z;
        scanf("%d%d %c", &x, &y, &z);
        t[x][z - 'a'] = y;
    }
    dfs0(1, 0);
    int yans = N, yansi = -1;
    int p = 0;
    for (int i = 0; ; ++i)
    {
        if (vv[i + 1].empty())
            break;
        ans = 0;
        for (int j = 0; j < vv[i].size(); ++j)
        {
            int x = vv[i][j];
            solvv(x);
        }
        ans += p;
        if (ans < yans)
        {
            yans = ans;
            yansi = i + 1;
        }
        p += sz(vv[i]);
    }
    printf("%d\n%d\n", yans, yansi);
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