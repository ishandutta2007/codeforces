#include <cstdio>
#include <cmath>
#include <algorithm>


#define sqr(x) ((x)*(x))

using namespace std;

const int MAXN = 1007;

int n;
int xa, ya, xb, yb;
int x[MAXN], y[MAXN], r[MAXN];
int ans;

int check(int X, int Y)
{
    for (int i = 0; i < n; i++)
        if (sqr(X - x[i]) + sqr(Y - y[i]) <= sqr(r[i]))
            return 0;
    ans++;
    return 1;
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &x[i], &y[i], &r[i]);

    if (xa > xb) swap(xa, xb);
    if (ya > yb) swap(ya, yb);

    for (int X = xa; X <= xb; X++)
    {
        check(X, ya);
        check(X, yb);
    }
        
    for (int Y = ya + 1; Y < yb; Y++)
    {
        check(xa, Y);
        check(xb, Y);
    }
    printf("%d\n", ans);
    return 0;
}