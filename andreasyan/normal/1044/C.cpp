#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 300005, INF = 1000000009;

int n;
int x[N], y[N];

int f(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return (max(x1, max(x2, x3)) - min(x1, min(x2, x3)) + max(y1, max(y2, y3)) - min(y1, min(y2, y3))) * 2;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &x[i], &y[i]);
    int maxx = -INF, minx = INF;
    int maxy = -INF, miny = INF;
    for (int i = 1; i <= n; ++i)
    {
        maxx = max(maxx, x[i]);
        minx = min(minx, x[i]);
        maxy = max(maxy, y[i]);
        miny = min(miny, y[i]);
    }
    int ans4 = (maxx - minx + maxy - miny) * 2;
    int ans3 = -INF;
    for (int i = 1; i <= n; ++i)
    {
        ans3 = max(ans3, f(maxx, y[i], minx, y[i], x[i], y[i]));
        ans3 = max(ans3, f(x[i], maxy, minx, y[i], x[i], y[i]));
        ans3 = max(ans3, f(maxx, y[i], x[i], miny, x[i], y[i]));
        ans3 = max(ans3, f(x[i], maxy, x[i], miny, x[i], y[i]));
        ans3 = max(ans3, f(maxx, y[i], maxx, y[i], x[i], y[i]));
        ans3 = max(ans3, f(x[i], maxy, maxx, y[i], x[i], y[i]));
        ans3 = max(ans3, f(maxx, y[i], x[i], maxy, x[i], y[i]));
        ans3 = max(ans3, f(x[i], maxy, x[i], maxy, x[i], y[i]));
        ans3 = max(ans3, f(minx, y[i], minx, y[i], x[i], y[i]));
        ans3 = max(ans3, f(x[i], miny, minx, y[i], x[i], y[i]));
        ans3 = max(ans3, f(minx, y[i], x[i], miny, x[i], y[i]));
        ans3 = max(ans3, f(x[i], miny, x[i], miny, x[i], y[i]));
    }
    printf("%d ", ans3);
    for (int i = 4; i <= n; ++i)
        printf("%d ", ans4);
    printf("\n");
    return 0;
}