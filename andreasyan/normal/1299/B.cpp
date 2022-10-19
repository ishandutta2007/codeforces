#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
int x[N], y[N];

bool stg()
{
    if (n % 2 == 1)
        return false;
    for (int i = 0; i < n; ++i)
    {
        int x1 = x[(i + 1) % n] - x[i];
        int y1 = y[(i + 1) % n] - y[i];
        int x2 = x[(i + n / 2) % n] - x[(i + n / 2 + 1) % n];
        int y2 = y[(i + n / 2) % n] - y[(i + n / 2 + 1) % n];
        //x2 *= -1;
        //y2 *= -1;
        if (x1 != x2 || y1 != y2)
            return false;
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &x[i], &y[i]);
    if (stg())
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}