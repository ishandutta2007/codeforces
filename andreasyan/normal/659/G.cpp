#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;
const long long M = 1000000007;
struct ban
{
    long long x;
    ban()
    {
        x = 0;
    }
    ban(long long x)
    {
        this->x = (x % M);
    }
};
ban operator+(const ban& a, const ban& b)
{
    return ban(a.x + b.x);
}
ban operator-(const ban& a, const ban& b)
{
    return ban(a.x - b.x + M);
}
ban operator*(const ban& a, const ban& b)
{
    return ban(a.x * b.x);
}
 
int n;
int a[N];
 
ban ans[N], s[N];
 
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        if (i == 1)
        {
            ans[i] = ban(a[i] - 1);
            if (i < n && a[i] > a[i + 1])
            {
                s[i] = ban(a[i + 1] - 1);
            }
            continue;
        }
        if (a[i] < a[i - 1])
        {
            ans[i] = s[i - 1] * ban(a[i] - 1);
            ans[i] = ans[i] + ban(a[i] - 1);
            if (i < n && a[i] > a[i + 1])
            {
                s[i] = s[i - 1] * ban(a[i + 1] - 1);
                s[i] = s[i] + ban(a[i + 1] - 1);
            }
        }
        else
        {
            ans[i] = ans[i - 1] * ban(a[i - 1] - 1);
            ans[i] = ans[i] + ban(a[i] - 1);
            if (i < n && a[i] > a[i + 1])
            {
                s[i] = ans[i - 1] * ban(min(a[i + 1] - 1, a[i - 1] - 1));
                s[i] = s[i] + ban(a[i + 1] - 1);
            }
        }
    }
    ban yans;
    for (int i = 1; i <= n; ++i)
        yans = yans + ans[i];
    printf("%lld\n", yans.x);
    return 0;
}