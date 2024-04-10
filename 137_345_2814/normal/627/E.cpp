#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
#define N 6050
set<int> tp;
int pr[N],nt[N],sz[N],id[N],n,m,k,t,as1,ct,st1[31];
long long as;
struct pt{int x,y;friend bool operator <(pt a,pt b){return a.y<b.y;}}v[N];
void init()
{
	as1=n*(n+1)/2;
	tp.clear();tp.insert(n+1);
	for(int i=1;i<=n+k+3;i++)pr[i]=nt[i]=sz[i]=id[i]=0;
	sz[1]=n;id[n+1]=1;ct=1;
}
void ins(int s)
{
	int s1=*tp.lower_bound(s),vl=id[s1],st=++ct;
	int p=pr[vl];
	sz[st]=sz[vl]-s1+s,sz[vl]=s1-s-1;id[s]=st;tp.insert(s);
	nt[p]=st;pr[st]=p;nt[st]=vl;pr[vl]=st;
	for(int i=0;i<=20;i++)st1[i]=0;
	st1[9]=st;
	for(int i=8,nw=pr[st];i>=0&&nw;i--,nw=pr[nw])st1[i]=nw;
	for(int i=10,nw=nt[st];i<=20&&nw;i++,nw=nt[nw])st1[i]=nw;
	for(int i=0;i<=9;i++)if(i+t>9&&st1[i]&&st1[i+t])
	as1-=(sz[st1[i]]+1)*(sz[st1[i+t]]+1);
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&t);
	as=1ll*n*(n+1)*m*(m+1)/4;
	for(int i=1;i<=k;i++)scanf("%d%d",&v[i].x,&v[i].y);
	sort(v+1,v+k+1);
	for(int i=1;i<=m;i++)
	{
		int las=i-1,lb=1;
		init();
		while(lb<=k&&v[lb].y<i)lb++;
		for(int j=lb;j<=k;j++)
		as-=1ll*(v[j].y-1-las)*as1,ins(v[j].x),las=v[j].y-1;
		as-=1ll*(m-las)*as1;
	}
	printf("%lld\n",as);
}