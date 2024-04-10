#include<cstdio>
#include<algorithm>
using namespace std;
#define N 200060
#define ll long long
#define fail {printf("NO\n");exit(0);}
struct sth{ll x,y,t;friend bool operator <(sth a,sth b){return a.t<b.t;}}s[N];
ll n,l,v[N][3],as[N*10],fg1,su[N*10][2];
char vl[5]="LUDR";
void solve(int vl)
{
	int ct=n+2,as1=0,as2=0;
	if(l&1)as2=1;
	else as1=1;
	s[n+1]=(sth){0,0,0};
	s[n+2]=(sth){0,1,l};
	double smn=-l,smx=l;
	sort(s+1,s+ct+1);
	for(int i=2;i<=ct;i++)
	{
		ll s1=s[i].x-s[i-1].x,s2=s[i].y-s[i-1].y,t1=s[i].t-s[i-1].t;
		if(s2&1)
		{
			if((s1-t1)&1)as2=1;
			else as1=1;
		}
		else if((s1-t1)&1)fail;
		if(s2==0){if(s1<-t1||s1>t1)fail;continue;}
		double mn=1.0*(-t1-s1)/s2,mx=1.0*(t1-s1)/s2;
		if(mn>mx)swap(mn,mx);
		if(smn<mn)smn=mn;
		if(smx>mx)smx=mx;
	}
	ll ans=(ll)(smn-1e-6)+1;
	if(smn-1e-6<=0)ans=smn;
	if(as1&&as2)fail;
	if(ans&1)if(as1)ans++;
	if(~ans&1)if(as2)ans++;
	if(ans>smx)fail;
	for(int i=2;i<=ct;i++)
	{
		ll s1=s[i].x-s[i-1].x+(s[i].y-s[i-1].y)*ans,t1=s[i].t-s[i-1].t;
		ll v1=(t1-s1)/2;
		for(int j=s[i-1].t+1;j<=s[i-1].t+v1;j++)as[j]-=vl;
	}
}
int main()
{
	scanf("%lld%lld",&n,&l);for(int i=1;i<=l;i++)as[i]=3;
	for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&v[i][0],&v[i][1],&v[i][2]);
	for(int i=1;i<=n;i++)s[i].x=v[i][1]+v[i][2],s[i].y=-v[i][0]/l,s[i].t=v[i][0]%l;
	solve(1);
	for(int i=1;i<=n;i++)s[i].x=v[i][1]-v[i][2],s[i].y=-v[i][0]/l,s[i].t=v[i][0]%l;
	solve(2);
	for(int i=1;i<=l;i++)
	{
		if(as[i]==0)su[i][0]=su[i-1][0]-1,su[i][1]=su[i-1][1];
		if(as[i]==1)su[i][0]=su[i-1][0],su[i][1]=su[i-1][1]+1;
		if(as[i]==2)su[i][0]=su[i-1][0],su[i][1]=su[i-1][1]-1;
		if(as[i]==3)su[i][0]=su[i-1][0]+1,su[i][1]=su[i-1][1];
	}
	for(int i=1;i<=n;i++)
	{
		ll asx=v[i][0]/l*su[l][0]+su[v[i][0]%l][0],asy=v[i][0]/l*su[l][1]+su[v[i][0]%l][1];
		if(asx!=v[i][1]||asy!=v[i][2])fail;
	}
	for(int i=1;i<=l;i++)printf("%c",vl[as[i]]);
}//.....