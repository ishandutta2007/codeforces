#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,pov[1001000],cnt[1001000],res;
int main(){
	scanf("%d",&n);
	pov[0]=1;
	for(int i=1;i<n;i++)pov[i]=(pov[i-1]<<1)%mod;
	cnt[0]=1;
	for(int i=1;i<n;i++)cnt[i]=1ll*(i+2)*pov[i-1]%mod;
//	for(int i=0;i<n;i++)printf("%d ",cnt[i]);
	reverse(cnt,cnt+n);
	for(int i=0,x;i<n;i++)scanf("%d",&x),res=(1ll*x*cnt[i]+res)%mod;
	printf("%d\n",res);
	return 0;
}