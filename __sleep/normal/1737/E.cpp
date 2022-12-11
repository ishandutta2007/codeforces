#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;
using ll=long long;
const int N=1000005,P=1000000007;
ll f[N],s[N],inv2[N];
void work(){
    int n;
    cin>>n;
    s[n]=f[n]=inv2[(n-1)/2];
    s[n+1]=0;
    for(int i=n-1;i>=1;--i){
        f[i]=inv2[(i+1)/2]*(1-(2*i>n?0:s[2*i])+P)%P;
        s[i]=s[i+1]+f[i];
        if(s[i]>P) s[i]-=P;
    }
    for(int i=1;i<=n;i++)
        printf("%lld\n",f[i]);
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    inv2[0]=1; inv2[1]=(P+1)>>1;
    for(int i=1;i<N;i++)
        inv2[i]=inv2[i-1]*inv2[1]%P;
    cin>>t;
    while(t--) work();
    return 0;
}