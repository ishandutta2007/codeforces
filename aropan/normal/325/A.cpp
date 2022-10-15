#include <cstdio>
#include <algorithm>

using namespace std;


int abs(int x) { return x < 0? -x : x; }
               
int main()
{
/*  
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
//*/
    int n;
    scanf("%d", &n);
    int x[n * 2 + 2], y[n * 2 + 2];
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &x[i * 2], &y[i * 2], &x[i * 2 + 1], &y[i * 2 + 1]);
        s += abs(x[i * 2 + 1] - x[i * 2]) * abs(y[i * 2 + 1] - y[i * 2]);
    }


    int w = (*max_element(x, x + 2 * n)) - (*min_element(x, x + 2 * n));
    int h = (*max_element(y, y + 2 * n)) - (*min_element(y, y + 2 * n));
    puts((w == h && w * h == s)? "YES" : "NO");
    return 0;
}