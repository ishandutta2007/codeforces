#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
struct ban
{
    int i, x;
};
bool operator<(const ban& a, const ban& b)
{
    return a.x < b.x;
}

int n;
ban a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        a[i].i = i;
        scanf("%d", &a[i].x);
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += ((i - 1) * a[i].x + 1);
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i].i);
    return 0;
}