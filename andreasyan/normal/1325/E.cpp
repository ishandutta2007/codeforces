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
const int N = 100005, M = 1000006;

int u[M];
void pre()
{
    for (int i = 2; i < M; ++i)
    {
        if (u[i])
            continue;
        for (int j = i; j < M; j += i)
        {
            if (!u[j])
                u[j] = i;
        }
    }
}

int n;
int a[N];
pair<int, int> b[N];

int qq[M];

vector<int> g[M];
vector<int> gi[M];

int c[M];
int d[M];
int ans1()
{
    memset(c, 0, sizeof c);
    memset(d, 0, sizeof d);
    queue<int> q;
    for (int i = 0; i < M; ++i)
    {
        if (qq[i])
        {
            c[i] = i;
            d[i] = 0;
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (!c[h])
            {
                c[h] = c[x];
                d[h] = d[x] + 1;
                q.push(h);
            }
        }
    }
    int ans = M;
    for (int i = 1; i <= n; ++i)
    {
        if (b[i].fi == -1)
            continue;
        if (c[b[i].fi] != c[b[i].se])
            ans = min(ans, d[b[i].fi] + 3 + d[b[i].se]);
    }
    return ans;
}

int pi[M];

int bfs(int s)
{
    vector<int> v;
    queue<int> q;
    c[s] = 1;
    d[s] = 0;
    q.push(s);
    pi[s] = 0;
    v.push_back(s);
    int ans = M;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (!c[h])
            {
                c[h] = 1;
                d[h] = d[x] + 1;
                q.push(h);
                v.push_back(h);
                pi[h] = gi[x][i];
            }
            else if (gi[x][i] != pi[x])
                ans = min(ans, d[x] + d[h] + 1);
        }
    }
    for (int i = 0; i < v.size(); ++i)
        c[v[i]] = 0;
    return ans;
}

int ans2()
{
    memset(c, 0, sizeof c);
    int ans = M;
    for (int i = 1; i <= 1000; ++i)
    {
        if (u[i] == i)
        {
            ans = min(ans, bfs(i));
        }
    }
    return ans;
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        set<int> s;
        int x = a[i];
        while (x > 1)
        {
            if (s.find(u[x]) == s.end())
                s.insert(u[x]);
            else
                s.erase(u[x]);
            x /= u[x];
        }
        if (s.empty())
        {
            printf("1\n");
            return;
        }
        else if (s.size() == 1)
        {
            ++qq[*s.begin()];
            b[i].fi = b[i].se = -1;
        }
        else
        {
            b[i].fi = *s.begin();
            b[i].se = *(++s.begin());
            g[b[i].fi].push_back(b[i].se);
            g[b[i].se].push_back(b[i].fi);
            gi[b[i].fi].push_back(i);
            gi[b[i].se].push_back(i);
        }
    }
    for (int i = 0; i < M; ++i)
    {
        if (qq[i] > 1)
        {
            printf("2\n");
            return;
        }
    }
    int ans = M;
    ans = min(ans, ans1());
    ans = min(ans, ans2());
    if (ans == M)
        printf("-1\n");
    else
        printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    pre();
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}