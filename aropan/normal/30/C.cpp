#include <cstdio>
#include <algorithm>

#define sqr(x) (long long)(((long long)x) * ((long long)x))

using namespace std;

struct Txytp
{
    int x, y, t;
    double p;
};

const int MAXN = 1111;
Txytp a[MAXN];
double f[MAXN];
int n;

bool operator<(const Txytp &a, const Txytp &b)
{
    return a.t < b.t;
}

int main()
{
/*
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
//*/
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d %d %lf", &a[i].x, &a[i].y, &a[i].t, &a[i].p);
    sort(a, a + n);
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        f[i] = 0;
        for (int j = 0; j < i; j++)
            if (sqr(a[i].x - a[j].x) + sqr(a[i].y - a[j].y) <= sqr(a[i].t - a[j].t))
                f[i] = max(f[i], f[j]);
        f[i] += a[i].p;
        ans = max(ans, f[i]);
    }
    printf("%.10lf\n", ans);
    return 0;
}