#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;


const int MAXN = 1007;
const int MAXM = 3 * 100007;


#define X first.first
#define Y first.second
#define I second


vector < pair < pair <int, int>, int > > S;
vector < pair < pair <int, int>, int > > M;

int root[MAXN];
int n, m, k, l;

int f[MAXN][MAXN];
int p[MAXN], t[MAXN];

int last[MAXN];
int next[MAXM], dest[MAXM], type[MAXM];

int Find(int x)
{
    if (x != root[x]) root[x] = Find(root[x]);
    return root[x];
}

int IsOneSet(int x, int y)
{
    return (Find(x) == Find(y));
}


int addedge(int x, int y, int t)
{
    f[x][y] = f[y][x] = t;

    m++;
    dest[m] = y;
    type[m] = t;
    next[m] = last[x];
    last[x] = m;

    m++;
    dest[m] = x;
    type[m] = t;
    next[m] = last[y];
    last[y] = m;
}
            
int Union(int x, int y, int t)
{
    if (IsOneSet(x, y))
        return 0;

    addedge(x, y, t);

    if (rand() & 1)
        root[Find(x)] = Find(y);
    else
        root[Find(y)] = Find(x);
    return 1;
}

int dfs(int x, int prev = -1, int TYPE = 0)
{
    p[x] = prev;
    t[x] = TYPE;
    for (int i = last[x]; i; i = next[i])
        if (dest[i] != prev && f[x][dest[i]] == type[i])
            dfs(dest[i], x, type[i]);
    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    scanf("%d %d", &n, &m);
    S.reserve(m);
    M.reserve(m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        char c;
        scanf("%d %d %c", &x, &y, &c);
        (c == 'S'? S : M).push_back(make_pair(make_pair(x, y), i + 1));
    }

    m = 0;
    if ((n - 1) & 1)
    {
        puts("-1");
        return 0;
    }


    for (int i = 1; i <= n; i++)
        root[i] = i;

    k = l = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (Union(S[i].X, S[i].Y, S[i].I))
            k++;
    }

    if (k < n / 2)
    {
        puts("-1");
        return 0;
    }

    for (int i = 0; i < M.size(); i++)
        if (Union(M[i].X, M[i].Y, -M[i].I))
            l++;

    for (int i = 0; i < M.size() && l < n / 2; i++)
        if (IsOneSet(M[i].X, M[i].Y))
        {
            dfs(M[i].X);

            int x = M[i].Y;
            while (p[x] != -1)
            {
                if (t[x] > 0)
                {
                    f[p[x]][x] = f[x][p[x]] = 0;
                    addedge(M[i].X, M[i].Y, -M[i].I);
                    k--;
                    l++;
                    break;
                }
                x = p[x];
            }
        }

    if (l != n / 2)
    {
        puts("-1");
        return 0;
    }

    vector <int> ans;
    for (int i = 1; i <= n; i++)
        for (int j = last[i]; j; j = next[j])
            if (f[i][dest[j]] == type[j])
                ans.push_back(abs(type[j]));

    sort(ans.begin(), ans.end());
    int c = unique(ans.begin(), ans.end()) - ans.begin();

    printf("%d\n", c);
    for (int i = 0; i < c; i++)
    {
        if (i) printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}