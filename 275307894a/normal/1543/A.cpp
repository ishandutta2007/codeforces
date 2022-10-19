#include<cstdio>
#include<algorithm>
using namespace std;
int T;
long long a,b;
long long kabs(long long x){return x>0?x:-x;}
int get(){
    scanf("%lld%lld",&a,&b);
    if(a==b)return printf("0 0\n"),0;
    long long p=kabs(a-b);
    printf("%lld %lld\n",p,min(a%p,p-a%p));
    return 0;
}
int main(){
    scanf("%d",&T);while(T--)get();
    return 0;
}