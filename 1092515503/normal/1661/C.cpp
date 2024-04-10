#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,a[300100],b[300100],mx;
bool che(ll odd,ll eve){
    for(int i=1;i<=n;i++)b[i]=a[i];
    for(int i=1;i<=n;i++)if(b[i]&1)odd--,b[i]--;
    if(odd<0)return false;
    eve+=odd>>1;
    for(int i=1;i<=n;i++){
        b[i]>>=1;
        eve-=b[i];
    }
    return eve>=0;
}
ll solve(){
    ll l=0,r=1e18;
    while(l<r){
        ll mid=(l+r)>>1;
        if(che((mid+1)>>1,mid>>1))r=mid;else l=mid+1;
    }
    return l;
}
void mina(){
    scanf("%d",&n),mx=0;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),mx=max(mx,a[i]);
    for(int i=1;i<=n;i++)a[i]=mx-a[i];
    ll ret=solve();
    for(int i=1;i<=n;i++)a[i]++;
    ret=min(ret,solve());
    printf("%lld\n",ret);
}
int main(){
    scanf("%d",&T);
    while(T--)mina();
    return 0;
}