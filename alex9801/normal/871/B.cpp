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

int res[5010];
int tmp[5010];
int ans[5010];

int bak[5010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    bool u;
    int n, r, i, j;
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("? %d 0\n", i);
        fflush(stdout);
        scanf("%d", &res[i]);
    }

    for(i = 0; i < n; i++)
    {
        printf("? 0 %d\n", i);
        fflush(stdout);
        scanf("%d", &bak[i]);
    }

    r = 0;
    for(i = 0; i < n; i++)
    {
        if(res[i] != i)
            continue;

        u = 1;
        for(j = 0; j < n; j++)
        {
            tmp[j] = res[j] ^ i;
            if(tmp[j] >= n)
            {
                u = 0;
                break;
            }
            if((bak[tmp[j]] ^ tmp[0]) != j)
            {
                u = 0;
                break;
            }
        }
        if(!u)
            continue;

        r++;
        for(j = 0; j < n; j++)
            ans[j] = tmp[j];
    }
    
    printf("!\n%d\n", r);
    for(i = 0; i < n; i++)
        printf("%d ", ans[i]);
    printf("\n");
    fflush(stdout);
    return 0;
}