#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e18;
int n,m;
ll b[300100],dd[300100],res;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
    ll a=0,d=0;
    for(int i=n;i;i--){
        a-=d,d-=dd[i];
        // printf("%lld:%lld\n",a,d);
        if(a<b[i]){
            ll dif=(b[i]-a-1)/min(m,i)+1;
            a+=dif*min(m,i),d+=dif,res+=dif;
            dd[max(i-m,0)]+=dif;
        }
    }
    printf("%lld\n",res);
    return 0;
}