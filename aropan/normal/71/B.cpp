#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, k, t, m;

int main()
{
#ifdef ADEBUG
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    scanf("%d %d %d", &n, &k, &t);
    m = n * k * t / 100;

    for (int i = 0; i < n; i++)
    {
        if (i) printf(" ");
        int x = min(m, k);
        printf("%d", x);
        m -= x;
    }
    
    return 0;
}