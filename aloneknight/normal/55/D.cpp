#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int P=2520;
int q[P],d[20],p[20];ll f[20][P][50];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int lcm(int x,int y){return y?x*y/gcd(x,y):x;}
ll dfs(int ps,int md,int w,int ff)
{
	if(!ps)return md%w==0;
	if(!ff&&~f[ps][md][q[w]])return f[ps][md][q[w]];
	ll res=0;
	for(int i=0,c=ff?d[ps]:9;i<=c;i++)res+=dfs(ps-1,(md+p[ps-1]*i)%P,lcm(w,i),ff&&i==c);
	return ff?res:f[ps][md][q[w]]=res;
}
ll sol(ll x){int nn=0;while(x)d[++nn]=x%10,x/=10;return dfs(nn,0,1,1);}
int main()
{
	memset(f,-1,sizeof(f));int T,cc=0;scanf("%d",&T);
	for(int i=1;i<P;i++)if(P%i==0)q[i]=++cc;
	p[0]=1;for(int i=1;i<=18;i++) p[i]=p[i-1]*10%P;
	while(T--){ll l,r;scanf("%lld%lld",&l,&r);printf("%lld\n",sol(r)-sol(l-1));}
	return 0;
}