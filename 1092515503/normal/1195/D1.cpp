#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
ll n,tmp,ans;
void cal(ll pla,ll ip){
	ll res=0,s[10001],t=0;
	while(ip)s[++t]=ip%10,ip/=10;
	while(t)res*=100,res+=s[t--];
	ans+=res;
	ans%=MOD;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&tmp),cal(i,tmp);
	printf("%d\n",((ans*n)%MOD*11)%MOD);
	return 0;
}