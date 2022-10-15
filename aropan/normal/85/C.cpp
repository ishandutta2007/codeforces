#include <cstdio>
#include <algorithm>

using namespace std;

#define V first
#define I second

const int MAXN = 333333;

int prev[MAXN], value[MAXN];
int left[MAXN], right[MAXN];
int minv[MAXN], maxv[MAXN];
pair <int, int> a[MAXN];
int d[MAXN];
long long f[MAXN];
long double ans[MAXN];
int n, m;

int fdfs(int x)
{
    if (x == 0) return 0;
    fdfs(left[x]);
    fdfs(right[x]);
    minv[x] = min(value[x], min(minv[left[x]], minv[right[x]]));
    maxv[x] = max(value[x], max(maxv[left[x]], maxv[right[x]]));
    return 0;
}


int sdfs(int x)
{
    if (left[x] == 0 || right[x] == 0)
    {
        ans[x] = (long double)f[x] / d[x];
        return 0;
    }

    d[left[x]] = d[x] + 1;
    d[right[x]] = d[x] + 1;

    f[left[x]] = f[x] + minv[right[x]];
    f[right[x]] = f[x] + maxv[left[x]];

    sdfs(left[x]);
    sdfs(right[x]);
    return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &prev[i], &value[i]);

    int root;
    minv[0] = (int)2e+9;
    maxv[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (prev[i] == -1)
        {
            root = i;
            continue;
        }

        if (value[i] < value[prev[i]])
            left[prev[i]] = i;
        else
            right[prev[i]] = i;
    }
    fdfs(root);
    sdfs(root);

    for (int i = 1; i <= n; i++)
        a[i - 1] = make_pair(value[i], i);

    sort(a, a + n);

    scanf("%d", &m);
    while (m--)
    {
        int x;
        scanf("%d", &x);
        int i = lower_bound(a, a + n, make_pair(x, 0)) - a;
        if (i == n || left[a[i].I] || right[a[i].I]) i--;
        printf("%.11lf\n", (double)ans[a[i].I]);
    }
    return 0;
}