#include<stdio.h>
int n;
int Count(long long t){
    int r = 0;
    while(t){
        if(t%2)r++;
        t/=2;
    }
    return r;
}
int main(){
    int i, M, Res, j;
    long long a, b, t, Ans;
    scanf("%d",&n);
    while(n--){
        scanf("%lld%lld",&a,&b);
        Res = Count(a), Ans = a;
        for(i=0;i<63;i++){
            if((1ll<<i)&a)continue;
            t = ((a>>i) +1)<<i;
            if(t>b)continue;
            for(j=i;j>=0;j--){
                if(t+(1ll<<j)-1 <= b)break;
            }
            M = Count(t+(1ll<<j)-1);
            if(Res<M)Res=M,Ans=t+(1ll<<j)-1;
        }
        printf("%lld\n",Ans);
    }
}