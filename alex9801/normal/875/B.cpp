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

int arr[300010];
bool chk[300010];

int par[300010];
int rnk[300010];
int siz[300010];

int root(int x)
{
    return x == par[x] ? x : (par[x] = root(par[x]));
}

bool merge(int x, int y)
{
    x = root(x);
    y = root(y);
    if(x == y)
        return 0;

    if(rnk[x] < rnk[y])
    {
        par[x] = y;
        siz[y] += siz[x];
    }
    else
    {
        par[y] = x;
        siz[x] += siz[y];
        if(rnk[x] == rnk[y])
            rnk[x]++;
    }
    return 1;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, t, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("1 ");
    for(i = 1; i <= n; i++)
    {
        par[i] = i;
        siz[i] = 1;
    }

    for(i = 0; i < n; i++)
    {
        t = arr[i];
        chk[t] = 1;
        if(chk[t - 1])
            merge(t - 1, t);
        if(chk[t + 1])
            merge(t + 1, t);

        if(chk[n])
            printf("%d ", i + 2 - siz[root(n)]);
        else
            printf("%d ", i + 2);
    }
    return 0;
}