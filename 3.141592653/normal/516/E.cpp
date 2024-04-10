#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
int n,m;
int A[111111],B[111111];
int gcd(int x,int y)
{int r=y;for(;r;r=x%y,x=y,y=r);return x;}
#include<vector>
std::vector<int>v1[222222],v2[222222];
int ln,lm;
#include<algorithm>
typedef long long ll;
ll max(ll x,ll y){retrun(x<y)?y:x;}
ll X,Y;
void exgcd(ll a,ll b)
{
	if(!b){X=1,Y=0;return;}
	exgcd(b,a%b);ll t=X;X=Y,Y=t-a/b*Y;
}
struct pii
{
	ll v,t;
}p[1111111];
int top;
ll invn,invm;
bool operator<(cpnst pii x,cpnst pii y){return(x.v^y.v)?x.v<y.v:x.t<y.t;}
ll ring(std::vector<int>&vx,std::vector<int>&vy,int m1,int m2,int INV)
{
	top=0;
	for(auto g:vx)p[++top]=(pii){g*1ll*INV%m1,g};
	for(auto g:vy)p[++top]=(pii){(g%m1)*1ll*INV%m1,g};
	std::sort(p+1,p+top+1);
	register int i;
	for(i=1;i<=top;i++)p[top+i]=p[i];top<<=1;
	for(i=2;i<=top;i++)
		if(p[i].t>p[i-1].t+(p[i].v+m1-p[i-1].v)%m1*1ll*m2)
			p[i].t=p[i-1].t+(p[i].v+m1-p[i-1].v)%m1*1ll*m2;
	ll ret=0;
	for(i=(top>>1)+1;i<=top;i++)
		if((i-1==(top>>1))||(p[i].v^p[i-1].v))
			if(p[i].v^((p[i-1].v+1)%m1))
			if(p[i-1].t+(p[i].v+m1-p[i-1].v-1)%m1*1ll*m2>ret)
				ret=p[i-1].t+(p[i].v+m1-p[i-1].v-1)%m1*1ll*m2;
	top=0;
	for(auto g:vx)p[++top]=(pii){g*1ll*INV%m1,g};
	std::sort(p+1,p+top+1);
	int tt=m1-1;for(;tt;tt--,top--)if(p[top].v!=tt)break;
	ret=max(ret,tt);
	return ret;
}
ll extend(int x)
{return max(ring(v1[x],v2[x],ln,lm,invm),ring(v2[x],v1[x],lm,ln,invn));}
ll solve(int x)
{
	exgcd(ln,lm),invn=(X%lm+lm)%lm,exgcd(lm,ln),invm=(X%ln+ln)%ln;
	if(ln==1)
	{
		std::sort(v1[x].begin(),v1[x].end()),std::sort(v2[x].begin(),v2[x].end());
		if(v1[x].size()||!v2[x][0])
		{
			int t=lm-1;
			bool Lf=(!v1[x].size())||(!v2[x].size())||v1[x][0]||v2[x][0];
			for(;v2[x].size();t--,v2[x].pop_back())
				if(v2[x].back()!=t)break;
			if(t<0)if(Lf)t=0;
			return t;
		}else return v2[x][0]-1+lm;
	}else if(lm==1)
	{
		std::sort(v1[x].begin(),v1[x].end()),std::sort(v2[x].begin(),v2[x].end());
		if(v2[x].size()||!v1[x][0])
		{
			int t=ln-1;
			bool Lf=(!v1[x].size())||(!v2[x].size())||v1[x][0]||v2[x][0];
			for(;v1[x].size();t--,v1[x].pop_back())
				if(v1[x].back()!=t)break;
			if(t<0)if(Lf)t=0;
			return t;
		}else return v1[x][0]-1+ln;
	}else return extend(x);
}
int main()
{
	scanf("%d%d",&n,&m);
	int G=gcd(n,m);ln=n/G,lm=m/G;
	if(G>200000)return puts("-1"),0;
	register int i;
	int a,b,x;
	scanf("%d",&a);
	for(i=1;i<=a;i++)
		scanf("%d",&x),v1[x%G].push_back(x/G);
	scanf("%d",&b);
	for(i=1;i<=b;i++)
		scanf("%d",&x),v2[x%G].push_back(x/G);
	ll ans=0;
	for(i=0;i<G;i++)
	{
		if(v1[i].size()+v2[i].size())ans=max(ans,G*1ll*solve(i)+i);
		else return puts("-1"),0;
	}printf("%lld\n",ans);
}
/*
Just go for it.
*/