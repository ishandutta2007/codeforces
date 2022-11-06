#include <iostream>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll inv(ll a,ll b){return a-1?b-inv(b%a,a)*b/a:1;}
int main(){
ll p=1,q=1, n;
cin>>n;
for(ll i=1;i<=n+1;++i){
p=p*(n+1+i)%mod;
q=q*i%mod;
}
cout<<p*inv(q,mod)%mod-1<<endl;
}