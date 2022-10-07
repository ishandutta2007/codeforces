#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 3e3;
struct node
{
    int v, next;
};
node a[2 * maxn];
int head[maxn];
bool use[maxn];
bool use2[maxn];
int dist[maxn];
int uk = 0;

void add(int x, int y)
{
    a[uk].v = y;
    a[uk].next = head[x];
    head[x] = uk;
    uk++;
}

int dfs1(int v, int p)
{
    use[v] = true;
    int k, d = head[v];
    while (d != -1)
    {
        if (a[d].v == p)
        {
            d = a[d].next;
            continue;
        }
        if (use[a[d].v])
        {
            use2[v] = true;
            return a[d].v;
        }
        if (! use[a[d].v])
        {
            k = dfs1(a[d].v, v);
            if (k != -1)
            {
                use2[v] = true;
                if (k == v)
                    return -1;
                else
                    return k;
            }
        }
        d = a[d].next;
    }
    return -1;
}

int dfs2(int v, int k)
{
    if (use2[v])
        return k;
    use[v] = 1;
    int h, d = head[v];
    while (d != -1)
    {
        if (! use[a[d].v])
        {
            h = dfs2(a[d].v, k + 1);
            if (h != -1)
                return h;
        }
        d = a[d].next;
    }

    return -1;
}


int main()
{
    int n, i, k, x, y;
    scanf("%d", &n);
    memset(head, -1, sizeof head);
    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        x--;
        y--;
        add(x, y);
        add(y, x);
    }
    dfs1(0, -1);
    for (i = 0; i < n; i++)
    {
        memset(use, 0, sizeof use);
        k = dfs2(i, 0);
        dist[i] = k;
    }
    for (i = 0; i < n; i++)
        printf("%d ", dist[i]);


    return 0;
}