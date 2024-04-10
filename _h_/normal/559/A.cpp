#include <cmath>
#include <cstdio>
using namespace std;
#define rep(i,a,b) for(int (i)=(int)(a); (i) < (int)(b); ++(i))

int main(){
    int a[6];
    rep(i,0,6)
        scanf("%d",a+i);
    double x[6], y[6];
    x[0] = 0, y[0] = 0;
    x[1] = a[1], y[1] = 0;
    x[2] = x[1] + a[2]/2.0; y[2] = a[2]*sqrt(3/4.0);
    x[3] = x[2] - a[3]/2.0; y[3] = y[2] + a[3]*sqrt(3/4.0);
    x[4] = x[3] - a[4]; y[4] = y[3];
    x[5] = x[4] - a[5]/2.0; y[5] = y[4] - a[5]*sqrt(3/4.0);
    double ar = 0;
    rep(i,0,6)
        ar += x[i]*y[(i+1)%6] - x[(i+1)%6]*y[i];
    printf("%d\n",(int)(abs(ar)/sqrt(3/4.0) + 1e-6));
}