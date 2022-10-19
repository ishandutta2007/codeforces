#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int n;
set<int> a[N];

int qry(int x, int y)
{
    printf("? %d %d\n", x, y);
    fflush(stdout);
    int z;
    scanf("%d", &z);
    return z;
}

void ans(int x)
{
    printf("! %d\n", x);
    fflush(stdout);
    exit(0);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].insert(y);
        a[y].insert(x);
    }
    set<int> s;
    for (int i = 1; i <= n; ++i)
        s.insert(i);
    while (1)
    {
        if (s.size() == 1)
        {
            ans((*s.begin()));
            return 0;
        }
        int x = -1, y = -1;
        for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
        {
            int z = *it;
            if (a[z].size() == 1)
            {
                if (x == -1)
                    x = z;
                else if (y == -1)
                    y = z;
            }
        }
        int z = qry(x, y);
        if (z == x || z == y)
        {
            ans(z);
        }
        s.erase(x);
        s.erase(y);
        a[*a[x].begin()].erase(x);
        a[*a[y].begin()].erase(y);
    }
    return 0;
}