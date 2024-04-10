#include<bits/stdc++.h>
using namespace std;
const int M=1000000007,M2=1004535809,M3=469762049,E=524288,N=1000005;
int t,n,k,p[N],a,s[26];
long long l,r;
long long cal(long long n){
    if(n==0)
        return 0;
    long long p=(long long)sqrt((long double)n+0.5);
    return 3*(p-1)+(n-p*p)/p+1;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld",&l,&r);
        printf("%lld\n",cal(r)-cal(l-1));
    }
}