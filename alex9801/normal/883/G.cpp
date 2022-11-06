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

struct edg
{
    int t, x, r, i;
};

vector<edg> arr[300010];
bool chk[300010];
int ori[300010];

void f1(int x)
{
    chk[x] = 1;
    for(edg e : arr[x])
    {
        if(chk[e.x])
            continue;

        if(e.t == 2)
            ori[e.i] = e.r;

        f1(e.x);
    }
}

void f2(int x)
{
    chk[x] = 1;
    for(edg e : arr[x])
    {
        if(chk[e.x])
            continue;

        if(e.t == 2)
            ori[e.i] = !e.r;
        else
            f2(e.x);
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m, s, t, x, y, c, i;
    scanf("%d%d%d", &n, &m, &s);
    for(i = 0; i < m; i++)
    {
        scanf("%d%d%d", &t, &x, &y);
        if(t == 1)
        {
            arr[x].push_back({ 1, y, 0, i });
            ori[i] = -1;
        }
        else
        {
            arr[x].push_back({ 2, y, 0, i });
            arr[y].push_back({ 2, x, 1, i });
        }
    }

    f1(s);

    c = 0;
    for(i = 1; i <= n; i++)
        if(chk[i])
            c++;

    printf("%d\n", c);
    for(i = 0; i < m; i++)
    {
        if(ori[i] == -1)
            continue;

        if(ori[i] == 0)
            printf("+");
        else
            printf("-");
    }
    printf("\n");

    memset(chk, 0, sizeof(chk));

    f2(s);
    
    c = 0;
    for(i = 1; i <= n; i++)
        if(chk[i])
            c++;

    printf("%d\n", c);
    for(i = 0; i < m; i++)
    {
        if(ori[i] == -1)
            continue;

        if(ori[i] == 0)
            printf("+");
        else
            printf("-");
    }
    printf("\n");

    return 0;
}