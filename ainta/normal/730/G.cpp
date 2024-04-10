#include<stdio.h>
#include<algorithm>
using namespace std;
struct point{
    int b, e;
}w[220];
int n;
int main(){
    int i, j, bb, dd, ee, MM, k;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d%d",&bb,&dd);
        ee=bb+dd-1;
        for(j=0;j<=i;j++){
            if(max(w[j].b,bb) <= min(w[j].e,ee))break;
        }
        if(j==i+1){
            printf("%d %d\n",bb,ee);
            w[i].b=bb,w[i].e=ee;
            continue;
        }
        MM = 2e9;
        for(j=0;j<=i;j++){
            bb = w[j].e+1;
            ee = bb+dd-1;
            for(k=0;k<=i;k++){
                if(max(w[k].b,bb) <= min(w[k].e,ee))break;
            }
            if(k == i+1){
                MM = min(MM, bb);
            }
        }
        bb=MM,ee=MM+dd-1;
        printf("%d %d\n",bb,ee);
        w[i].b=bb,w[i].e=ee;
    }
}