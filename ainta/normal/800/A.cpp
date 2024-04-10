#include<cstdio>
#include<algorithm>
using namespace std;
int n, p;
struct point{
    int a, b;
}w[101000];
int main(){
    int i;
    scanf("%d%d",&n,&p);
    for(i=1;i<=n;i++){
        scanf("%d%d",&w[i].a,&w[i].b);
    }
    double b = 0.0, e = 1e13, mid;
    for(int tt=0;tt<70;tt++){
        mid = (b+e)*0.5;
        double s = 0.0;
        for(i=1;i<=n;i++){
            if(w[i].a*mid > w[i].b) s += (w[i].a*mid-w[i].b)/p;
        }
        if(s > mid) e = mid;
        else b = mid;
    }
    if(mid > 9e12){
        printf("-1\n");
        return 0;
    }
    printf("%.10f\n",mid);
}