#include<cstdio>
int t;
long long n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        if(n<=6) puts("15");
        else if(n<=8) puts("20");
        else if(n<=10) puts("25");
        else if(n<=12) puts("30");
        else{
            long long ans=0; 
            if(n&1){
                n-=5;
                ans=n/2*5+15;
            }
            else ans=n/2*5;
            printf("%lld\n",ans);
        }
    }
    return 0;
}