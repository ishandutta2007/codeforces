#include <bits/stdc++.h>
using namespace std;

long long x, y;
void solv()
{
    scanf("%lld%lld", &x, &y);
    set<long long> s;
    while (1)
    {
        if (s.find(x) != s.end())
        {
            printf("NO\n");
            return;
        }
        s.insert(x);
        if (x >= y)
        {
            printf("YES\n");
            return;
        }
        if (x % 2 == 0)
            x = (x / 2) * 3;
        else
            --x;
    }
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}