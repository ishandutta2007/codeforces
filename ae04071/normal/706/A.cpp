#include <cstdio>
#include <cmath>
#include <algorithm>

int main()
{
    int hx, hy, n;
    scanf("%d %d", &hx, &hy);
    scanf("%d",&n);
    
    double min = 10000000.0;
    for(int i = 0; i < n; i++)
    {
        int x, y, s;
        scanf("%d %d %d",&x, &y, &s);
        double dist = sqrt(pow(hx-x,2) + pow(hy-y,2));
        min = std::min(min, dist / s);
    }
    
    printf("%.15lf\n", min);
    
    return 0;
}