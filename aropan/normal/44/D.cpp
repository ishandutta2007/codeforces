#include <cstdio>
#include <cmath>
#include <algorithm>

#define sqr(x) ((x)*(x))

using namespace std;

const int MAXN = 5555;

double x[MAXN], y[MAXN], z[MAXN];
double s[MAXN];
double ans;
int n;

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf %lf", &x[i], &y[i], &z[i]);
        s[i] = sqrt(sqr(x[i] - x[0]) + sqr(y[i] - y[0]) + sqr(z[i] - z[0]));
    }
        
    ans = 1e+60;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            ans = min(ans, 
                s[i] + s[j] +
                sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]) + sqr(z[i] - z[j]))
            );
        }
    printf("%.10lf\n", ans / 2);
    
    return 0;
}