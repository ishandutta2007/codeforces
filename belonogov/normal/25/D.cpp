#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;
const int maxn = 1e3 + 2;
struct node
{
    int next, x;
};

int use[maxn];
int head[maxn];
int cl[maxn];
bool use2[maxn];
bool use3[maxn];
node a[2 * maxn];
int color = 0, uk = 0;

void dfs(int v)
{
    use[v] = color;
    int d = head[v];
    while (d != -1)
    {
        if (use[a[d].x] == -1)
            dfs(a[d].x);
        d = a[d].next;
    }
}

pair<int, int> dfs2(int v, int p)
{
    use3[v] = 1;
    pair<int, int> g;
    int d = head[v];
    while (d != -1)
    {
        if (use3[a[d].x] == 1 && a[d].x != p)
            return make_pair(v, a[d].x);
        if (use3[a[d].x] == 0)
        {
            g = dfs2(a[d].x, v);
            if (g.first != -1)
                return g;
        }
        d = a[d].next;
    }
    return make_pair(-1, -1);
}
void add(int x, int y)
{
    a[uk].next = head[x];
    a[uk].x = y;
    head[x] = uk;
    uk++;
}
void dl(int x, int y)
{
    int d = head[x], d1 = -1;
    if (a[d].x == y)
    {
        head[x] = a[d].next;
        return;
    }
    while (a[d].x != y)
    {
        d1 = d;
        d = a[d].next;
    }
    a[d1].next = a[d].next;
}

int main()
{
    int uk2 = 1, n, i, x, y;
    pair <int, int> k;
    scanf("%d", &n);
    memset(head, -1, sizeof head);
    memset(use, -1, sizeof use);
    for (i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &x, &y);
        x--;
        y--;
        add(x, y);
        add(y, x);
    }
    for (i = 0; i < n; i++)
    {
        if (use[i] == -1)
        {
            dfs(i);
            cl[color] = i;
            color++;
        }
    }
    printf("%d\n", color - 1);
    for (i = 0; i < n; i++)
    {
        while (! use2[i])
        {
            memset(use3, 0, sizeof use3);
            k = dfs2(i, -1);
            if (k.first == -1)
                use2[i] = true;
            else
            {
                printf("%d %d %d %d\n", k.first + 1, k.second + 1, 1, cl[uk2++] + 1);
                dl(k.first, k.second);
                dl(k.second, k.first);
            }
        }
    }
    return 0;
}