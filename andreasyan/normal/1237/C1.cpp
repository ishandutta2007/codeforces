#include <bits/stdc++.h>
using namespace std;
const int N = 50004;
struct ban
{
    int x, y, z;
};

int n;
ban a[N];

bool c[N];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (c[i])
            continue;
        int minj = -1;
        for (int j = i + 1; j <= n; ++j)
        {
            if (c[j])
                continue;
            if (minj == -1)
                minj = j;
            if (abs(a[j].x - a[i].x) < abs(a[minj].x - a[i].x))
                minj = j;
            else if (abs(a[j].x - a[i].x) == abs(a[minj].x - a[i].x))
            {
                if (abs(a[j].y - a[i].y) < abs(a[minj].y - a[i].y))
                    minj = j;
                else if (abs(a[j].y - a[i].y) == abs(a[minj].y - a[i].y))
                {
                    if (abs(a[j].z - a[i].z) < abs(a[minj].z - a[i].z))
                        minj = j;
                }
            }
        }
        printf("%d %d\n", i, minj);
        c[i] = c[minj] = true;
    }
    return 0;
}