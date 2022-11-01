#include <stdio.h>
#include <stdint.h>
#define ll int64_t


struct pr
{
    ll f, s;
} a[100001], b[100001];

int cmp(const void* p1, const void* p2)
{
    ll d = - ((const struct pr*)p1)->f + ((const struct pr*)p2)->f;
    if (d) return d < 0 ? -1 : 1;
    return ((const struct pr*)p1)->s - ((const struct pr*)p2)->s > 0 ? 1 : -1;
}

int main()
{
    int n, m; ll d;
    scanf("%d%d%I64d", &n, &m, &d);
    for(int i = 0; i < n; ++i)
    {
        scanf("%I64d%I64d", &(a[i].f), &(a[i].s));
    }
    for(int i = 0; i < m; ++i)
    {
        scanf("%I64d%I64d", &(b[i].f), &(b[i].s));
    }
    qsort(a, n, sizeof(struct pr), cmp);
    qsort(b, m, sizeof(struct pr), cmp);
    for(int i = 1; i < n; ++i)
    {
        a[i].f += a[i-1].f;
        a[i].s += a[i-1].s;
    }
    for(int i = 1; i < m; ++i)
    {
        b[i].f += b[i-1].f;
        b[i].s += b[i-1].s;
    }
    int i = 0, j = 0;
    if (a[0].s + b[0].s > d)
    {
        printf("0");
        return 0;
    }
    while(i < n && a[i].s + b[0].s <= d) ++i;
    ll ans = 0;
    while(j < m && i >= 0)
    {
        if (i < n && a[i].s + b[j].s <= d)
        {
            if (a[i].f + b[j].f > ans) ans = a[i].f + b[j].f;
            ++j;
        }
        else --i;
    }
    printf("%I64d", ans);
    return 0;
}