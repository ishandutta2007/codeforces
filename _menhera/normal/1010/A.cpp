#include<bits/stdc++.h>
using namespace std;
int N, M;
int a[1010], b[1010];
double calc(double x, double y)
{
    return x/y;
}
bool can(double init)
{
    for(int i=0; i<N; ++i)
    {
        init -= calc(M+init, a[i]);
        if(init < 0) return false;
        init -= calc(M+init, b[(i+1)%N]);
        if(init < 0) return false;
    }
    return true;
}
int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; ++i) scanf("%d", a+i);
    for(int i=0; i<N; ++i) scanf("%d", b+i);
    double lo = 0;
    double hi = 1e10;
    for(int iter=0; iter<200; ++iter)
    {
        double mi = (lo+hi)/2;
        if(can(mi)) hi = mi;
        else lo = mi;
    }
    if(hi > 5e9) puts("-1");
    else printf("%.12f\n", hi);
    return 0;
}