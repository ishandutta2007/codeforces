#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    int x1, y1, x2, y2;
    scanf("%*d %*d %d %d %d %d", &x1, &y1, &x2, &y2);
    int x = abs(x1 - x2);
    int y = abs(y1 - y2);
    if (x < y) swap(x,  y);
    if (x > 4 || x == 4 && (y > 2))
    {
    	puts("Second");
    	return 0;
    }

	puts("First");
    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}