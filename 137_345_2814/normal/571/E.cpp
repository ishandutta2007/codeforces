#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
#define N 5002
#define ll long long
#define fail {printf("-1\n");exit(0);}
#define mod 1000000007
map<int,int> tp;
int n,a,b,s1[N],ct,mx;
ll s[N][2],t[N][2],q[3][3],v[N][2];
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll exgcd(ll a,ll b,ll &x,ll &y){if(!b){x=1,y=0;return a;}ll g=exgcd(b,a%b,x,y);ll t=x;x=y;y=t-a/b*y;return g;}
int pw(int a,int p){int as=1;while(p){if(p&1)as=1ll*as*a%mod;a=1ll*a*a%mod;p>>=1;}return as;}
void merge()
{
	int c1=0;
	for(int i=1;i<=ct;i++)
	{
		if(s[i][1]==0&&t[i][1]==0){if(s[i][0]!=t[i][0])fail;continue;}
		q[++c1][0]=s[i][1],q[c1][1]=-t[i][1],q[c1][2]=-t[i][0]+s[i][0];
		ll g=gcd(q[c1][0],q[c1][1]);
		if(q[c1][2]%g)fail;
		q[c1][0]/=g;q[c1][1]/=g;q[c1][2]/=g;
		if(q[c1][0]<0)q[c1][0]*=-1,q[c1][1]*=-1,q[c1][2]*=-1;
		if(c1==2)
		{
			if(q[1][1]==0&&q[2][1]==0)
			{
				if((q[1][2]%q[1][0])||(q[2][2]%q[2][0])||(q[1][2]/q[1][0]!=q[2][2]/q[2][0]))fail;
				ll asx=q[1][2]/q[1][0];
				q[1][0]=1;q[1][1]=0;q[1][2]=asx;c1--;continue;
			}
			if(q[1][0]==0&&q[2][0]==0)
			{
				if((q[1][2]%q[1][1])||(q[2][2]%q[2][1])||(q[1][2]/q[1][1]!=q[2][2]/q[2][1]))fail;
				ll asx=q[1][2]/q[1][1];
				q[1][0]=0;q[1][1]=1;q[1][2]=asx;c1--;continue;
			}
			if(q[1][0]==q[2][0]&&q[1][1]==q[2][1]){if(q[1][2]!=q[2][2])fail;c1--;continue;}
			ll g=gcd(q[1][1],q[2][1]),s1=q[1][1]/g,s2=q[2][1]/g;
			ll asx,asy;
			if(q[1][1]==0)
			{
				if(q[1][2]%q[1][0])fail;
				asx=-q[1][2]/q[1][0];
				if((-q[2][2]-asx*q[2][0])%q[2][1])fail;
				asy=(-q[2][2]-asx*q[2][0])/q[2][1];
			}
			else if(q[2][1]==0)
			{
				if(q[2][2]%q[2][0])fail;
				asx=-q[2][2]/q[2][0];
				if((-q[1][2]-asx*q[1][0])%q[1][1])fail;
				asy=(-q[1][2]-asx*q[1][0])/q[1][1];
			}
			else
			{
				q[1][0]*=s2;q[1][1]*=s2;q[1][2]*=s2;
				q[2][0]*=s1;q[2][1]*=s1;q[2][2]*=s1;
				if((q[2][2]-q[1][2])%(q[1][0]-q[2][0]))fail;
				asx=(q[2][2]-q[1][2])/(q[1][0]-q[2][0]);
				if(q[1][1])
				{
					if((-q[1][2]-asx*q[1][0])%q[1][1])fail;
					asy=(-q[1][2]-asx*q[1][0])/q[1][1];
				}
				else if(q[2][1])
				{
					if((-q[2][2]-asx*q[2][0])%q[2][1])fail;
					asy=(-q[2][2]-asx*q[2][0])/q[2][1];
				}
			}
			if(asx<0||asy<0)fail;
			for(int j=1;j<=ct;j++)
			{
				ll s1=s[j][1]*asx+s[j][0],s2=t[j][1]*asy+t[j][0];
				if(s1!=s2)fail;
				s[j][0]=s1;s[j][1]=0;
			}
			return;
		}
	}
	if(!c1)return;
	//c1=1xw
	ll x,y,s1;
	ll g=exgcd(q[1][0],q[1][1],x,y);
	ll f1=q[1][0],f2=q[1][1];
	int fg1=f1>0?1:-1,fg2=f2>0?1:-1;
	x*=-q[1][2]*g;y*=-q[1][2]*g;
	if(x<0)s1=-x/(f2*fg2),x+=f2*fg2*s1,y-=f1*fg2*s1;
	while(x<0)x+=f2*fg2,y-=f1*fg2;
	if(y<0)s1=-y/(f1*fg1),y+=f1*fg1*s1,x-=f2*fg1*s1;
	while(y<0)y+=f1*fg1,x-=f2*fg1;
	s1=min(fg2*f2==0?0:x/(fg2*f2),fg1*f1==0?0:y/(fg1*f1));
	x-=fg2*f2*s1,y-=fg1*f1*s1;
	while(x>=fg2*f2&&y>=fg1*f1)x-=fg2*f2,y-=fg1*f1;
	if(x<0)fail;
	for(int i=1;i<=ct;i++)
	if(s[i][1]||t[i][1])
	{
		if(s[i][1])
		s[i][0]+=s[i][1]*x,s[i][1]*=f2;
		else
		s[i][0]=t[i][0]+t[i][1]*y;s[i][1]=t[i][1]*f1;
	}
}
int main()
{
	scanf("%d",&n);
	int fg1=0;
	for(int i=1;i<=n;i++){scanf("%lld%lld",&v[i][0],&v[i][1]);if(v[i][1]==1)fg1=1;}
	if(fg1)
	{
		int vl=0;
		for(int i=1;i<=n;i++)if(v[i][1]==1)vl=v[i][0];
		int fg=1;
		for(int i=1;i<=n;i++)
		{
			int st=v[i][0];
			if(st==vl)continue;
			int fg2=0;
			for(int k=1;k<=60;k++)st=(1ll*st*v[i][1]>1e9?1e9+1:st*v[i][1]),fg2|=(st==vl);
			fg&=fg2;
		}
		printf("%d\n",fg?vl:-1);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=ct;j++)t[j][0]=t[j][1]=0;
		a=v[i][0],b=v[i][1];mx=max(mx,a);
		for(int j=2;j<=4e4;j++)
		if(a%j==0||b%j==0)
		{
			if(!tp[j])tp[j]=++ct,s1[ct]=j;
			int s11=0,s21=0;
			while(a%j==0)a/=j,s11++;
			while(b%j==0)b/=j,s21++;
			t[tp[j]][0]=s11,t[tp[j]][1]=s21;
		}
		if(a>1&&b>1&&a==b)
		{
			if(!tp[a])tp[a]=++ct,s1[ct]=a;
			t[tp[a]][0]=1,t[tp[a]][1]=1;
		}
		else if(a>1)
		{
			if(!tp[a])tp[a]=++ct,s1[ct]=a;
			t[tp[a]][0]=1,t[tp[a]][1]=0;
		}
		else if(b>1)
		{
			if(!tp[b])tp[b]=++ct,s1[ct]=b;
			t[tp[b]][0]=0,t[tp[b]][1]=1;
		}
		if(i==1)swap(s,t);else merge();
	}
	int as=1,fg=0;
	for(int i=1;i<=ct;i++)as=1ll*as*pw(s1[i],s[i][0]%(mod-1))%mod;
	printf("%d\n",as);
}