#include<cstdio>
const int N=1000000;
int t,a[N];
long long x;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&x);
        if((x&-x)==x){puts("-1"); continue;}
        long long ans=0;
        for(long long a=2;a/2*(a+1)<=x;a<<=1)
            if(x%a==a/2){ans=a; break;}
        if(ans){printf("%lld\n",ans); continue;}
        while(!(x&1)) x>>=1;
        printf("%lld\n",x);
    }
    return 0;
}