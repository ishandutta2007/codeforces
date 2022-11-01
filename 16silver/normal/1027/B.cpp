#include <cstdio>
int main(){
    long long n,q,x,y,i;
    scanf("%lld%lld",&n,&q);
    for(i=0;i<q;i++){
        scanf("%lld%lld",&x,&y);
        if(n%2LL==0LL){
            if((x+y)%2LL == 0LL){
                printf("%lld\n",(x-1LL)*(n/2LL)+(y+1LL)/2LL);
            }
            else{
                printf("%lld\n",(x-1LL)*(n/2LL)+(y+1LL)/2LL+(n*n/2LL));
            }
        }
        else{
            if(x%2LL == 1LL){
                if(y%2LL == 1LL){
                    printf("%lld\n",n*(x/2LL)+(y+1LL)/2LL);
                }
                else{
                    printf("%lld\n",n*(x/2LL)+y/2LL+(n*n)/2LL+1LL);
                }
            }
            else{
                if(y%2LL == 0LL){
                    printf("%lld\n",n*(x/2LL-1LL)+n/2LL+y/2LL+1LL);
                }
                else{
                    printf("%lld\n",n*(x/2LL-1LL)+n/2LL+y/2LL+(n*n)/2LL+2LL);
                }
            }
        }
    }
}