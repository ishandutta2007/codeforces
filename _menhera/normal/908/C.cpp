#include<bits/stdc++.h>
using namespace std;
int x[10101];
double y[10101];
int N, R;
int main()
{
    scanf("%d%d", &N, &R);
    for(int i=0; i<N; ++i)
        scanf("%d", x+i);
    for(int i=0; i<N; ++i)
    {
        double fc = R;
        for(int j=0; j<i; ++j)
        {
            if(abs(x[j]-x[i])>2*R) continue;
            double dx = x[j]-x[i];
            double dy = sqrt(max(0.0, 4*R*R-dx*dx));
            fc = max(fc, y[j]+dy);
        }
        y[i] = fc;
    }
    for(int i=0; i<N; ++i)
        printf("%.12f ", y[i]);
    return 0;    
}