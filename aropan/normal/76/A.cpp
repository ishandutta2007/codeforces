#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

#define X second.first
#define Y second.second
#define Gold first.first
#define Silver first.second

const int MAXM = 555555;
const int MAXN = 444;
const long long INF = (long long)3e+18;

int n, m;
pair < pair <int, int>, pair <int, int> > a[MAXM];

set < pair < int, pair<int, int> > > Set;
long long G, S;

set <int> e[MAXN];

int d[MAXN][MAXN];
int prev[MAXN];
queue <int> q;

int add(int x, int p)
{
    if (prev[x]) return 0;
    prev[x] = p;
    q.push(x);
    return 0;
}

int addE(int x, int y, int s)
{
    if (x > y) swap(x, y);
//    printf("+%d %d %d\n", x, y, s);
    d[x][y] = s;
    d[y][x] = s;
    e[x].insert(y);
    e[y].insert(x);
    Set.insert(make_pair(s, make_pair(x, y)));
    return 0;
}               

int deleteE(int x, int y)
{
    if (x > y) swap(x, y);
//    printf("-%d %d\n", x, y);
    Set.erase(make_pair(d[x][y], make_pair(x, y)));
    e[x].erase(y);
    e[y].erase(x);
    d[x][y] = 0;
    d[y][x] = 0;
    return 0;
}
         

int add(int x, int y, int s)
{
    if (x == y) return 0;

    for (int i = 1; i <= n; i++)
        prev[i] = 0;

    while (q.size()) q.pop();
    add(x, -1);
    while (q.size())
    {
        int x = q.front();
        q.pop();
        set <int> :: iterator i = e[x].begin();

        while (i != e[x].end())
        {
            add(*i, x);
            i++;
        }
    }

//    printf("%d %d %d\n", x, y, s);

    if (prev[y] == 0)
    {
        addE(x, y, s);
        return 0;
    }

    int xa = y, ya = y;

    while (prev[ya] != -1)
    {
        if (d[prev[ya]][ya] > d[prev[xa]][xa])
            xa = ya;

        ya = prev[ya];
    }

    if (d[prev[xa]][xa] > s)
    {
        deleteE(prev[xa], xa);
        addE(x, y, s);
    }
    return 0;
}

int main()
{
    #ifdef OFFLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif

    scanf("%d %d %I64d %I64d", &n, &m, &G, &S);
    int k = 0;
    for (int i = 0; i < m; i++)
        scanf("%d %d %d %d", &a[i].X, &a[i].Y, &a[i].Gold, &a[i].Silver);

    sort(a, a + m);

    long long ans = INF;
    for (int i = 0; i < m; i++)
    {
        add(a[i].X, a[i].Y, a[i].Silver);
        if (Set.size() == n - 1)
            ans = min(ans, G * a[i].Gold + S * Set.rbegin()->first);
    }

    if (ans == INF)
        puts("-1");
    else
        printf("%I64d\n", ans);

    return 0;
}