#include<stdio.h>
int n, m, L1, L2, C[7], Res;
int main(){
    int i, j, t, k;
    scanf("%d%d",&n,&m);
    if((long long)n*m>1000000){
        printf("0\n");
        return 0;
    }
    t = n-1;
    while(t){
        t/=7;
        L1++;
    }
    if(!L1)L1++;
    t = m-1;
    while(t){
        t/=7;
        L2++;
    }
    if(!L2)L2++;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            for(k=0;k<7;k++)C[k]=0;
            t = i;
            for(k=0;k<L1;k++){
                C[t%7]++;
                t/=7;
            }
            t = j;
            for(k=0;k<L2;k++){
                C[t%7]++;
                t/=7;
            }
            for(k=0;k<7;k++)if(C[k]>1)break;
            if(k==7){
                Res++;
            }
        }
    }
    printf("%d\n",Res);
}