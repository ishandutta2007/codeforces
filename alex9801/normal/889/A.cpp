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

using namespace std;

int arr[200010];
int mem[200010];
int tim[200010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, c, i;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    c = 1;
    mem[0] = 0;

    memset(tim, -1, sizeof tim);
    tim[0] = 0;

    for(i = 1; i <= n; i++)
    {
        if(tim[mem[arr[i]]] == arr[i])
        {
            mem[i] = mem[arr[i]];
            tim[mem[i]] = i;
        }
        else
        {
            mem[i] = c++;
            tim[mem[i]] = i;
        }
    }
    printf("%d", c);
    return 0;
}