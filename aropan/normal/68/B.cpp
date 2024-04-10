#include <cstdio>

using namespace std;

const int MAXN = 10001;
const double E = 1e-10;

double left, right, center;
double a[MAXN];
int n, k;

int main()
{
/*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
//*/
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%lf", &a[i]);

    left = 0;
    right = 1001;
    while (left + E < right)
    {
        center = (left + right) / 2;
        double s = 0;
        for (int i = 0; i < n; i++)
            if (a[i] > center)
                s += (a[i] - center) * (100 - k) / 100;
            else
                s -= center - a[i];

        if (s < 0)
            right = center;
        else
            left = center;
    }
    printf("%.10lf\n", (left + right) / 2);
    
    return 0;
}