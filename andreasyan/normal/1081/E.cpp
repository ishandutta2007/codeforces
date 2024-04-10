#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
int a[N];

vector<long long> v;

int main()
{
    scanf("%d", &n);
    n /= 2;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    long long u = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (long long j = sqrt(u) + 1; ; ++j)
        {
            long long xx = (j * j + a[i]);
            long long x = sqrt(xx);
            if (x * x == xx)
            {
                v.push_back(j * j - u);
                v.push_back(a[i]);
                u = xx;
                break;
            }
            if ((double)clock() / CLOCKS_PER_SEC > 1.5)
            {
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    for (int i = 0; i < v.size(); ++i)
        printf("%lld ", v[i]);
    printf("\n");
    return 0;
    for (int i = 1; i <= 1; ++i)
    {
        set<int> s;
        for (int j = i; j <= 100; ++j)
        {
            s.insert(j * j - i * i);
        }
        for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
            printf("%d ", *it);
        printf("\n");
    }
    return 0;
}