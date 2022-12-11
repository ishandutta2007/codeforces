#include<cstdio>
int t,n,x,sum,flag,k;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        k=n;sum=0; flag=0;
        while(n--)
            scanf("%d",&x),sum+=x,flag|=(x==1);
        if(sum&1) puts("NO");
        else if(!flag&&(k&1)) puts("NO");
        else puts("YES");
    }
    return 0;
}