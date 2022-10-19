#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
struct ban
{
    int x, y;
};
bool operator<(const ban& a, const ban& b)
{
    if (a.x < b.x)
        return true;
    if (a.x > b.x)
        return false;
    return a.y < b.y;
}

int n;
ban a[N];

int m;
char ans[N * N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].x, &a[i].y);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        if (!(a[i - 1].x <= a[i].x && a[i - 1].y <= a[i].y))
        {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
    m = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = a[i - 1].x; j < a[i].x; ++j)
            ans[m++] = 'R';
        for (int j = a[i - 1].y; j < a[i].y; ++j)
            ans[m++] = 'U';
    }
    ans[m++] = 0;
    printf("%s\n", ans);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}