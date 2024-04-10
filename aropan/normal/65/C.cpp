#include <cstdio>
#include <cmath>

#define sqr(x) ((x)*(x))


using namespace std;

const int MAXN = 11111;
const long double me = 1e-15;

int n;
double x[MAXN], y[MAXN], z[MAXN];
double l[MAXN];
double vp, vs, xo, yo, zo;

bool check(double x, double y)
{
    return x < y || fabs(x - y) < 1e-15;
}

int main()
{
/*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
//*/
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
        scanf("%lf %lf %lf", &x[i], &y[i], &z[i]);

    scanf("%lf %lf", &vp, &vs);
    scanf("%lf %lf %lf", &xo, &yo, &zo);

    l[0] = 0;
    for (int i = 1; i <= n; i++)
        l[i] = l[i - 1] + sqrt(sqr(x[i] - x[i - 1]) + sqr(y[i] - y[i - 1]) + sqr(z[i] - z[i - 1]));


    for (int i = 1; i <= n; i++)
        if (check(sqrt(sqr(x[i] - xo) + sqr(y[i] - yo) + sqr(z[i] - zo)) * vs, l[i] * vp))
        {
            long double left, right, center;
            double X, Y, Z;
            left = 0;
            right = 1;
            while (left + me < right)
            {
                center = (left + right) / 2;
                X = x[i - 1] + center * (x[i] - x[i - 1]),
                Y = y[i - 1] + center * (y[i] - y[i - 1]),
                Z = z[i - 1] + center * (z[i] - z[i - 1]);

                if (check(
                        sqrt(sqr(X - xo) + sqr(Y - yo) + sqr(Z - zo)) * vs,
                        (sqrt(sqr(X - x[i - 1]) + sqr(Y - y[i - 1]) + sqr(Z - z[i - 1])) + l[i - 1]) * vp
                    )
                   )
                   right = center;
                else
                   left = center;
            }
            center = right;
            X = x[i - 1] + center * (x[i] - x[i - 1]),
            Y = y[i - 1] + center * (y[i] - y[i - 1]),
            Z = z[i - 1] + center * (z[i] - z[i - 1]);

            puts("YES");
            printf("%.10lf\n", (sqrt(sqr(X - x[i - 1]) + sqr(Y - y[i - 1]) + sqr(Z - z[i - 1])) + l[i - 1]) / vs);
            printf("%.10lf %.10lf %.10lf\n", X, Y, Z);
            return 0;
        }
    puts("NO");
    return 0;
}