#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define PI 3.14159265359
int n;
double r, v, d, t, b, e, mid;
int main(){
    int n, dr, dv, bb, ee, i;
    scanf("%d%d%d",&n,&dr,&dv);
    r=dr,v=dv;
    while(n--){
        scanf("%d%d",&bb,&ee);
        d = ee-bb;
        e = d/r;
        b = e - 2*PI;
        if(b<0)b=0.0;
        for(i=0;i<50;i++){
            mid = (b+e)*0.5;
            t = sin(mid*0.5);
            if(t<0)t=-t;
            t = r*mid + 2*r*t;
            if(t<d)b = mid;
            else e = mid;
        }
        printf("%.10lf\n",b*r/v);
    }
}