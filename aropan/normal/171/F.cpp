#include <cstdio>
#include <algorithm>
#include <ctime>

using namespace std;


const int MAXX = 2000000;

bool f[MAXX];
int n;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    scanf("%d", &n);

    for (int i = 2; i * i < MAXX; i++)
        if (f[i] == false)
            for (int j = i * i; j < MAXX; j += i) f[j] = true;
    for (int i = 2; i < MAXX; i++)
        if (!f[i])
        {
            int x = i, y = 0;
            do y = y * 10 + x % 10; while (x /= 10);
            if (f[y] || y == i) continue;
            n--;
            if (n == 0)
            {
                printf("%d\n", i);
                return 0;
            }
        }
    
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}