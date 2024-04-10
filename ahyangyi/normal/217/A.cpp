#include <stdio.h>

int n;
int x[100], y[100];
int color[100];

void flood (int i)
{
    color[i] = 0;
    for (int j = 0; j < n; j ++)
        if ((x[j] == x[i] || y[j] == y[i]) && color[j] == -1)
            flood(j);
}

int main ()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i ++)
        scanf ("%d%d", x + i, y + i);

    for (int i = 0; i < n; i ++)
        color[i] = -1;

    int ans = -1;
    for (int i = 0; i < n; i ++)
        if (color[i] == -1)
        {
            ans ++;
            flood(i);
        }
    printf ("%d\n", ans);

    return 0;
}