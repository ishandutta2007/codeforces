#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int mod=998244353;
int l,r,k,num[23],pov[23],tp;
pii f[23][1<<10];
pii dfs(int pos,int sta,bool lim,bool lead){
	if(__builtin_popcount(sta)>k)return make_pair(0,0);
	if(!pos)return make_pair(0,1);
	if(!lim&&!lead&&f[pos][sta]!=make_pair(-1ll,-1ll))return f[pos][sta];
	pii res=make_pair(0,0);
	for(int i=0;i<=(lim?num[pos]:9);i++){
		pii tmp=dfs(pos-1,sta|(lead&&!i?0:(1<<i)),lim&&(i==num[pos]),lead&&(!i));
		(res.first+=tmp.first)%=mod;
		(res.second+=tmp.second)%=mod;
		(res.first+=tmp.second*i%mod*pov[pos]%mod)%=mod;
	}
	if(!lim&&!lead)f[pos][sta]=res;
	return res;
}
int calc(int ip){
	tp=0;
	while(ip)num[++tp]=ip%10,ip/=10;
	return dfs(tp,0,1,1).first;
}
signed main(){
	scanf("%lld%lld%lld",&l,&r,&k),l--,memset(f,-1,sizeof(f));
	pov[1]=1;
	for(int i=2;i<23;i++)pov[i]=(pov[i-1]*10)%mod;
	printf("%lld\n",(calc(r)-calc(l)+mod)%mod);
	return 0;
}