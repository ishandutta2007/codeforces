#include<stdio.h>
int i, t, r, m, be, ed;
int main(){
    scanf("%d",&m);
    for(i=1;i<=1000000;i++){
        r = 0;
        for(t=5;t<=i;t*=5) r += i/t;
        if(r==m){
            if(be==0)be=i;
            ed=i;
        }
    }
    if(!be)printf("0\n");
    else{
        printf("%d\n",ed-be+1);
        for(i=be;i<=ed;i++)printf("%d ",i);
    }
}