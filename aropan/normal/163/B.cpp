#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct lemming
{
    int m, v, i;
    lemming(int m = 0, int v = 0, int i = 0) : m(m), v(v), i(i) { }
};

const int MAXN = 100007;

int n, k, h;
lemming a[MAXN];
int answer[MAXN];

bool operator < (const lemming &a, const lemming &b)
{
    return a.m > b.m || a.m == b.m && a.v > b.v;
}

bool f(long double t)
{
    int m = k;
    for (int i = 0; i < n && m; i++)
        if (m * (long long)h <= t * a[i].v)
            answer[--m] = a[i].i;
    return m == 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    scanf("%d %d %d", &n, &k, &h);
    for (int i = 0; i < n; i++) scanf("%d", &a[i].m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i].v);
    for (int i = 0; i < n; i++) a[i].i = i;
    sort(a, a + n);

    long double l = 0, r = (long long)1e+10;
    for (int i = 0; i < 256; i++)
    {
        long double c = (l + r) / 2;
        if (f(c))
            r = c;
        else
            l = c;
    }
    f(r);
    for (int i = 0; i < k; i++)
    {
        if (i) printf(" ");
        printf("%d", answer[i] + 1);
    }
    printf("\n");
    return 0;
}