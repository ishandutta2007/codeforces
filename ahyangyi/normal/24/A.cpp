#include <stdio.h>

int ind[100], next[200], to[200], cost[200], p;
int tmp;

void dfs (int x, int y)
{
    if (x == 0 && y != -1)
        return;

    for (int i = ind[x]; i != -1; i = next[i])
        if (to[i] != y)
        {
            tmp += cost[i];
            dfs (to[i], x);
            return;
        }
}

int main ()
{
    int n, tot;

    p = 0;
    scanf ("%d", &n);
    for (int i = 0; i < n; i ++)
        ind[i] = -1;
    tot = 0;
    for (int i = 0; i < n; i ++)
    {
        int a, b, c;

        scanf ("%d%d%d", &a, &b, &c);
        a --;
        b --;

        next[p] = ind[a];
        to[p] = b;
        cost[p] = 0;
        ind[a] = p ++;

        next[p] = ind[b];
        to[p] = a;
        cost[p] = c;
        ind[b] = p ++;

        tot += c;
    }

    tmp = 0;
    dfs (0, -1);

    printf ("%d\n", tmp < tot - tmp? tmp : tot - tmp);

    return 0;
}