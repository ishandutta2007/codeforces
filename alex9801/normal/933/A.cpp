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

int arr[2010];
int cnt[2][2010];

int f(int x, int l, int r)
{
    if(r < l)
        return 0;

    return cnt[x][r] - cnt[x][l - 1];
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i, j;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    for(i = 1; i <= n; i++)
    {
        if(arr[i] == 1)
            cnt[0][i]++;
        else
            cnt[1][i]++;
    }

    for(i = 1; i <= n; i++)
    {
        cnt[0][i] += cnt[0][i - 1];
        cnt[1][i] += cnt[1][i - 1];
    }

    int r = 0;
    for(i = 0; i <= n; i++)
        r = max(r, f(0, 1, i) + f(1, i + 1, n));

    for(i = 1; i <= n; i++)
    {
        int t = 0;
        for(j = i; j >= 1; j--)
        {
            if(arr[j] == 2)
                t++;
            else
                t = max(t, f(0, j, i));
            
            r = max(r, t + f(0, 1, j - 1) + f(1, i + 1, n));
        }
    }

    printf("%d", r);
    return 0;
}