#include<bits/stdc++.h>
#define Mx 5000
#define LL long long
#define mod 1000000007
using namespace std;
int n,m;
bool ok;
int s[5002],l[5002],r[5002];
LL fac[5002],inv[5002];
vector<int> pos[5002];
vector<int> vec[2][5002];
struct aaa
{
	int mx;
	LL cnt;
}tmp={0,1},ans;
inline void upd(aaa &a,aaa b)
{
	if(a.mx<b.mx)swap(a,b);
	if(a.mx==b.mx && (a.cnt+=b.cnt)>=mod)a.cnt-=mod;
}
inline LL Pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline void calc(int x,int y,int o)
{
	if(x>y)swap(x,y);
	if(!x && !y);
	else if(!x)tmp.mx+=o,(tmp.cnt*=(~o? y:inv[y]))%=mod;
	else if(x==1 && y==1)tmp.mx+=o,(tmp.cnt*=(~o? 2:inv[2]))%=mod;
	else tmp.mx+=o*2,(tmp.cnt*=(~o? x*(y-1):inv[x]*inv[y-1])%mod)%=mod;
}
inline void init()
{
	fac[0]=1;for(int i=1;i<=Mx;++i)fac[i]=(fac[i-1]*i)%mod;
	inv[Mx]=Pow(fac[Mx],mod-2);for(int i=Mx;i;--i)inv[i-1]=(inv[i]*i)%mod,(inv[i]*=fac[i-1])%=mod;
}
int main()
{
	init(),scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&s[i]),pos[s[i]].push_back(i);
	for(int i=1,x,y;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		if(y>pos[x].size())continue;
		++r[x],vec[0][pos[x][y-1]].push_back(x),vec[1][pos[x][pos[x].size()-y]].push_back(x);
	}
	for(int i=1;i<=n;++i)calc(l[i],r[i],1);
	ans=tmp,++tmp.mx;
	for(int i=1,x;i<=n;++i)
	{
		ok=0;
		for(int j=0;j<vec[0][i].size();++j)x=vec[0][i][j],calc(l[x],r[x],-1),++l[x],calc(l[x],r[x],1),ok|=(x==s[i]);
		for(int j=0;j<vec[1][i].size();++j)x=vec[1][i][j],calc(l[x],r[x],-1),--r[x],calc(l[x],r[x],1);
		if(ok)calc(l[s[i]],r[s[i]],-1),calc(0,r[s[i]]-(l[s[i]]<=r[s[i]]),1),upd(ans,tmp),calc(0,r[s[i]]-(l[s[i]]<=r[s[i]]),-1),calc(l[s[i]],r[s[i]],1);
	}
	return 0&printf("%d %lld",ans.mx,(ans.cnt+mod)%mod);
}