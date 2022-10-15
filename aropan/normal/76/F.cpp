#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 111111;
const int INF = (int)1e+9;

long long x[MAXN], y[MAXN], t[MAXN];
long long xx[MAXN], yy[MAXN];
int d[MAXN];
int a[MAXN];
int v;
int n, m, nx, ny;


int modify(int x, int d)
{
    for (int i = x; i <= n + 1; i += i & -i)
        a[i] = max(a[i], d);
}

int findmax(int x)
{
    int res = -INF;
    for (int i = x; 1 <= i; i -= i & -i)
        res = max(res, a[i]);
    return res;
}

bool opr_sort(const int &a, const int &b)
{
    return x[a] < x[b] || x[a] == x[b] && y[a] < y[b];
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int X, T;
        scanf("%d %d", &X, &T);
        x[i] = X;
        t[i] = T;
    }
    scanf("%d", &v);

    x[n] = 0;
    t[n] = 0;

    for (int i = 0; i <= n; i++)
    {
        yy[i] = y[i] = x[i] + t[i] * v;
        xx[i] = x[i] = -x[i] + t[i] * v;
    }

    sort(xx, xx + n + 1);
    sort(yy, yy + n + 1);

    nx = unique(xx, xx + n + 1) - xx;
    ny = unique(yy, yy + n + 1) - yy;

    for (int i = 0; i <= n; i++)
    {
        x[i] = lower_bound(xx, xx + nx, x[i]) - xx + 1;
        y[i] = lower_bound(yy, yy + ny, y[i]) - yy + 1;
    }

    for (int i = 0; i <= n; i++)
        d[i] = i;

    sort(d, d + n + 1, opr_sort);

    for (int i = 0; i <= n + 1; i++)
        a[i] = -INF;

    int ans = -INF;
    for (int i = 0; i <= n; i++)
    {
        int x = d[i] == n? 0 : findmax(y[d[i]]) + 1;
        modify(y[d[i]], x);

        ans = max(x, ans);
    }
    printf("%d ", ans);


    
    
    
    
    for (int i = 0; i < n; i++)
        d[i] = i;

    sort(d, d + n, opr_sort);

    for (int i = 0; i <= n + 1; i++)
        a[i] = 0;

    ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x = findmax(y[d[i]]) + 1;
        modify(y[d[i]], x);

        ans = max(x, ans);
    }
    printf("%d\n", ans);

    return 0;
}