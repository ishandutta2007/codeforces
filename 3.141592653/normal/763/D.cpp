#include<cstdio>
#include<vector>
#include<map>
int n;
typedef __int128 ll;
const ll mod=1000000000999999999ll,EX=0x4b4d4325;
ll qpow(ll x,ll k){ll r=1;for(;k;k>>=1,x=x*x%mod)if(k&1)r=r*x%mod;return r;}
ll f[1111111],S[1111111],M[1111111];
std::vector<int>v[1111111];
std::map<ll,int>Mt;
int cnt,ans,anp=1;
int d[1111111];
void ins(ll x)
{
	int&t=Mt[x];
	if(!t)cnt++;
	t++;
}
void dec(ll x)
{
	int&t=Mt[x];
	if(t==1)cnt--;
	t--;
}
void dfs(int p=1,int fr=0)
{
	S[p]=1,M[p]=d[p];
	for(int t:v[p])if(t^fr)dfs(t,p),S[p]+=f[t],(M[p]*=f[t])%=mod;
	f[p]=(S[p]%mod*M[p]+EX)%mod;
}
void solve(int p=1,int fr=0,ll fv=0)
{
	if(cnt>ans)ans=cnt,anp=p;
	for(int t:v[p])if(t^fr)
	{
		ll F=(S[p]-f[t]+fv)%mod*qpow(f[t],mod-2)%mod*M[p]%mod;
		if(fv)F=F*fv%mod;
		(F+=EX)%=mod;
		dec(f[t]),ins(F),solve(t,p,F),dec(F),ins(f[t]);
	}
}
int main()
{
	scanf("%d",&n);
	register int i;
	for(i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x),d[x]++,d[y]++;
	}dfs();for(i=2;i<=n;i++)ins(f[i]);solve(),printf("%d\n",anp);
}
/*
Please don't let me down.
*/