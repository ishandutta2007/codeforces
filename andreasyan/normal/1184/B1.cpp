#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct ban
{
    int i;
    int x, g;
};
bool operator<(const ban& a, const ban& b)
{
    return a.x < b.x;
}

int n, m;
ban a[N], b[N];

int ans[N];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        a[i].i = i;
        scanf("%d", &a[i].x);
    }
    for (int i = 1; i <= m; ++i)
    {
        b[i].i = i;
        scanf("%d%d", &b[i].x, &b[i].g);
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int yans = 0;
    int j = 0;
    for (int i = 1; i <= n; ++i)
    {
        while (j != m && b[j + 1].x <= a[i].x)
        {
            ++j;
            yans += b[j].g;
        }
        ans[a[i].i] = yans;
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}