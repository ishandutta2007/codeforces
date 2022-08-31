#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        long long a, b,n,c=0;
        scanf("%lld%lld%lld",&a,&b,&n);
        while(a<=n&&b<=n){
            if(a>b)b+=a;
            else a+=b;
            c++;
        }
        printf("%lld\n",c);
    }
}