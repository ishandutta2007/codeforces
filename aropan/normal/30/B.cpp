#include <cstdio>
#include <algorithm>

using namespace std;

int M[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int a[3], b[3];

int read(int *a)
{
    int d, m, y;
    scanf("%d.%d.%d", &d, &m, &y);
    a[0] = d;
    a[1] = m;
    a[2] = y;
    return 0;
}


int main()
{
/*
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
//*/
    read(b);
    read(a);
    sort(a, a + 3);
    do
    {
        M[2] = 28 + (int)(a[2] % 4 == 0);
        if (12 < a[1] || a[1] < 1 || a[0] < 1 || M[a[1]] < a[0]) continue;

        if (
            a[2] + 18 < b[2] ||
            a[2] + 18 == b[2] && a[1] < b[1] ||
            a[2] + 18 == b[2] && a[1] == b[1] && a[0] <= b[0]
            )
        {
            puts("YES");
            return 0;
        }
        
    } while (next_permutation(a, a + 3));
    puts("NO");
    return 0;
}