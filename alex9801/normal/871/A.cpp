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

    int q, n, i;
    scanf("%d", &q);
    for(i = 0; i < q; i++)
    {
        scanf("%d", &n);
        if(n < 4 || n % 2 && n < 9 || n == 11)
            printf("-1\n");
        else
        {
            if(n % 2 == 0)
                printf("%d\n", n / 4);
            else
                printf("%d\n", (n - 9) / 4 + 1);
        }
    }
    return 0;
}