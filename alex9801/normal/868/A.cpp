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

char arr[10];
char mem[110][10];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i, j;
    scanf("%s", arr);
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%s", mem[i]);

    for(i = 0; i < n; i++)
    {
        if(strcmp(arr, mem[i]) == 0)
        {
            printf("YES");
            return 0;
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(mem[i][1] == arr[0] && mem[j][0] == arr[1])
            {
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}