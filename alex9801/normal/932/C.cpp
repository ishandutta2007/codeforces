#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>

using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, a, b, i, j, k;
    scanf("%d%d%d", &n, &a, &b);

    for(i = 0; i*a <= n; i++)
    {
        if((n - i * a) % b != 0)
            continue;

        int x = i;
        int y = (n - i * a) / b;

        int t = 1;
        for(j = 0; j < x; j++)
        {
            for(k = 0; k < a - 1; k++)
                printf("%d ", t + 1 + k);
            printf("%d ", t);

            t += a;
        }

        for(j = 0; j < y; j++)
        {
            for(k = 0; k < b - 1; k++)
                printf("%d ", t + 1 + k);
            printf("%d ", t);

            t += b;
        }

        return 0;
    }

    printf("-1");

    return 0;
}