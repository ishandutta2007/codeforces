#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


const int MAXN = 111111;
const int MAXM = MAXN << 1;

int n, m;
int last[MAXN];
int next[MAXM], dest[MAXM], dist[MAXM];
int t[MAXN], c[MAXN];
int ans[MAXN];

int dfs_fs(int x, int p)
{
    t[x] = 0;
    c[x] = 1;

    for (int i = last[x]; i; i = next[i])
    {
        if (p == dest[i]) continue;

        dfs_fs(dest[i], x);

        c[x] += c[dest[i]];
        t[x] += t[dest[i]] + 2 * dist[i];

        t[dest[i]] += 2 * dist[i];
    }
    return 0;
}


bool opr_sort(pair <int, int> i, pair <int, int> j)
{
    return (long long)t[i.first] * c[j.first] < (long long)t[j.first] * c[i.first];
}


int dfs_sc(int x, int p, int l)
{

    ans[x] = l;

    vector < pair <int, int> > a;
    for (int i = last[x]; i; i = next[i])
    {
        if (p == dest[i]) continue;
        a.push_back(make_pair(dest[i], dist[i]));
    }

    sort(a.begin(), a.end(), opr_sort);


    for (int i = 0; i < (int)a.size(); i++)
    {
        dfs_sc(a[i].first, x, l + a[i].second);
        l += t[a[i].first];
    }
    return 0;
}



int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);

        dest[i] = y;
        dist[i] = z;
        next[i] = last[x];
        last[x] = i;

        dest[i + n] = x;
        dist[i + n] = z;
        next[i + n] = last[y];
        last[y] = i + n;
    }


    dfs_fs(1, 0);
    dfs_sc(1, 0, 0);


    double x = 0;
    for (int i = 1; i <= n; i++)
        x += ans[i];
    printf("%.8lf\n", x / (n - 1));

    return 0;
}