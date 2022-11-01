#include <bits/stdc++.h>
using namespace std;
void solve(long long a, long long b, long long c, long long d){
    if(a>b*c) puts("-1");
    else if(c <= d) printf("%lld\n",a);
    else{
        long long t=a/(b*d);
        printf("%lld\n",a*(t+1)-t*(t+1)/2LL*b*d);
    }
}
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        long long a,b,c,d;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        solve(a,b,c,d);
    }
}