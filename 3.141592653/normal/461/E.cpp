#include<bits/stdc++.h>
#include<tr1/unordered_map>
typedef long long ll;
const ll INF=2e18;
void emin(ll&x,ll y){x>y?x=y:0;}
ll n;
char str[1111111];
struct mat{ll a[4][4];}E[65];
ll min(ll a,ll b,ll c,ll d){ll t=(a>b?a=b:0,a>c?a=c:0,a>d?d:a);if(t>INF)t=INF;return t;}
mat operator*(const mat&x,const mat&y)
{
	mat r;
	for(register int i=0,ii;i<4;i++)
		for(ii=0;ii<4;ii++)
			r.a[i][ii]=min(x.a[i][0]+y.a[0][ii],x.a[i][1]+y.a[1][ii],x.a[i][2]+y.a[2][ii],x.a[i][3]+y.a[3][ii]);
	return r;
}
bool execute(ll*x,const mat&y)
{
	ll t[4]={INF,INF,INF,INF};
	for(register int i=0,ii;i<4;i++)for(ii=0;ii<4;ii++)emin(t[ii],x[i]+y.a[i][ii]);
	if(t[0]>=n&&t[1]>=n&&t[2]>=n&&t[3]>=n)return 0;
	return x[0]=t[0],x[1]=t[1],x[2]=t[2],x[3]=t[3],1;
}
std::tr1::unordered_map<ll,int>mp;
ll bs=23515,bt=68247,ms=1004535809,mt=1000000009;
ll ps[1111111],pt[1111111],hs[1111111],ht[1111111];
ll gs(int l,int r){return(hs[r]+ms-hs[l-1]*ps[r-l+1]%ms)%ms;}
ll gt(int l,int r){return(ht[r]+mt-ht[l-1]*pt[r-l+1]%mt)%mt;}
ll gth(int l,int r){return gs(l,r)*(1ll<<30)+gt(l,r);}
ll tp[5];
int main()
{
	scanf("%lld%s",&n,str+1);
	int l=strlen(str+1);
	register int i,ii;
	for(i=ps[0]=pt[0]=1;i<=l;i++)
		ps[i]=ps[i-1]*bs%ms,pt[i]=pt[i-1]*bt%mt,
		hs[i]=(hs[i-1]*bs+str[i])%ms,ht[i]=(ht[i-1]*bt+str[i])%mt;
	for(i=0;i<4;i++)E[0].a[i][0]=E[0].a[i][1]=E[0].a[i][2]=E[0].a[i][3]=1e9;
	for(i=1;i<=l;i++)
		for(ii=i;ii<=i+10&&ii<=l;ii++)mp[gth(i,ii)]=1;
	for(i=1;i<=l;i++)
	{
		ll qs=0,qt=0;
		int s=str[i]-65;
		for(ii=i;ii<=i+10&&ii<=l;ii++)
		{
			qs=(qs*bs+str[ii])%ms,qt=(qt*bt+str[ii])%mt;
			for(char t:"ABCD")
			{
				if(!t)continue;
				int e=t-65;
				ll ws=(qs*bs+t)%ms,wt=(qt*bt+t)%mt;
				if(!mp[ws*(1ll<<30)+wt])emin(E[0].a[s][e],ii+1-i);
			}
		}
	}for(i=1;i<=62;i++)E[i]=E[i-1]*E[i-1];
	ll ans=0;
	for(i=62;~i;i--)if(execute(tp,E[i]))ans+=(1ll<<i);
	printf("%lld\n",ans+1);
}
/*
Please don't let me down.
*/