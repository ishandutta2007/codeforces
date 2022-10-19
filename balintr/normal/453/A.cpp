#include <stdio.h>
#include <cmath>
int m, n;
double ans;
int main(){
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= m; ++i) ans += (pow((double) i/m, n) - pow((double) (i-1)/m, n)) * i;
    printf("%.6f\n", ans);
}