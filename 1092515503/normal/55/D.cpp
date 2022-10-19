#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=2520;
int _1,n,m,cnt,num[20],f[20][2521][50],hs[2521];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int LCM(int a,int b){if(!b)return a;return a/gcd(a,b)*b;}
int dfs(int pos,int mod,int lcm,bool lim){
	if(!pos)return !(mod%lcm);
	if(!lim&&f[pos][mod][hs[lcm]]!=-1)return f[pos][mod][hs[lcm]];
	int res=0;
	for(int i=0;i<=(lim?num[pos]:9);i++)res+=dfs(pos-1,(mod*10+i)%MOD,LCM(lcm,i),lim&&(i==num[pos]));
	if(!lim)return f[pos][mod][hs[lcm]]=res;
	return res;
}
int part(int ip){
	int t=0;
	while(ip)num[++t]=ip%10,ip/=10;
	return dfs(t,0,1,1);
}
signed main(){
	memset(f,-1,sizeof(f));
	for(int i=1;i<=MOD;i++)if(!(MOD%i))hs[i]=++cnt;
	scanf("%I64d",&_1);
	while(_1--)scanf("%I64d%I64d",&n,&m),printf("%I64d\n",part(m)-part(n-1));
	return 0;
}