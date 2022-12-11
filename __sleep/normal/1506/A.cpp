#include<cstdio>
const int N=100005;
int n,t,m,a,b;
long long x;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%lld",&m,&n,&x);
        a=(x+m-1)/m;
        b=(x-1)%m+1;
        printf("%lld\n",1ll*(b-1)*n+a);
    }
    return 0;
}