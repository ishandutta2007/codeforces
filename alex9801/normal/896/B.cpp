#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <ctime>

using namespace std;

int arr[1010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m, c, p, x, i, j;
    scanf("%d%d%d", &n, &m, &c);

    for(i = 0; i < m; i++)
    {
        scanf("%d", &p);
        if(p <= c / 2)
        {
            for(j = 1; j <= n; j++)
            {
                if(j == n || arr[j] == 0 || arr[j] > p)
                {
                    x = j;
                    break;
                }
            }
        }
        else
        {
            for(j = n; j >= 1; j--)
            {
                if(j == 1 || arr[j] == 0 || arr[j] < p)
                {
                    x = j;
                    break;
                }
            }
        }

        arr[x] = p;
        printf("%d\n", x);
        fflush(stdout);

        bool u = 1;
        for(j = 1; j <= n; j++)
        {
            if(arr[j] == 0 || j != n && arr[j] > arr[j + 1])
            {
                u = 0;
                break;
            }
        }
        if(u)
            break;
    }
    return 0;
}