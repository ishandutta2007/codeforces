#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct ban
{
    int m, p;
};
bool operator<(const ban& a, const ban& b)
{
    return a.m < b.m;
}

int n;
ban a[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].m, &a[i].p);
    long long ans = 0;
    priority_queue<int> q;
    int qq = 0;
    sort(a + 1, a + n + 1);
    for (int i = n; i >= 1; --i)
    {
        q.push(-a[i].p);
        while ((i - 1) + qq < a[i].m)
        {
            ++qq;
            ans -= q.top();
            q.pop();
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}