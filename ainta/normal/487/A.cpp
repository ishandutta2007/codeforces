#include<stdio.h>
#include<algorithm>
using namespace std;
int h1, a1, d1, h2, a2, d2, c1, c2, c3;
int main()
{
    int i, j, k, d, H, Res = 999999999;
    scanf("%d%d%d",&h1,&a1,&d1);
    scanf("%d%d%d",&h2,&a2,&d2);
    scanf("%d%d%d",&c1,&c2,&c3);
    for(i=a1;i<=300;i++){
        if(i<=d2)continue;
        for(j=d1;j<=100;j++){
            d = (h2-1)/(i-d2)+1;
            if(j >= a2) H = 1;
            else H = (a2-j)*d+1;
            Res=min(Res,(i-a1)*c2 + (j-d1)*c3 + (max(H,h1)-h1)*c1);
        }
    }
    printf("%d\n",Res);
}