#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;
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
    for (int i = 1; i <= n; ++i)
        a[i].x += i;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        if (a[i].x == a[i - 1].x)
        {
            printf(":(\n");
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        printf("%d ", a[i].x - i);
    }
    printf("\n");
    return 0;
}