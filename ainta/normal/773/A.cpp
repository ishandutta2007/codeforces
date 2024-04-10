#include<cstdio>
#include<algorithm>
using namespace std;
int TC;
long long x, y, p, q;
int main(){
    scanf("%d",&TC);
    while(TC--){
        scanf("%lld%lld%lld%lld",&x,&y,&p,&q);
        if(p==0){
            if(x==0){
                printf("0\n");
            }
            else{
                printf("-1\n");
            }
            continue;
        }
        if(p==q){
            if(x==y){
                printf("0\n");
            }
            else{
                printf("-1\n");
            }
            continue;
        }
        printf("%lld\n",max(max((y-x+(q-p)-1)/(q-p), (x+p-1)/p), (y+q-1)/q) * q - y);
    }
}