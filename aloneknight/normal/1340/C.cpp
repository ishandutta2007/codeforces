#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
#define db long double
#define pii pair<ll,int>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define per(i,b,a) for(register int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(register int i=(a);i<(b);++i)
#define fore(i,a) for(register int i=0;i<a.size();++i)
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r
#define gc() getchar()
inline int rd()
{
	int x=0,w=1;char c=gc();while(!isdigit(c)&&c!='-')c=gc();
	if(c=='-')w=-1,c=gc();while(isdigit(c))x=x*10+c-48,c=gc();return x*w;
}
const int N=10005,M=10000005;
const ll inf=1e16;
int n,m,G,R,p[N],q1[M*2],q2[M*2],f[10005][1005];
int main()
{
	n=rd();m=rd();rep(i,1,m)p[i]=rd();
	sort(p+1,p+m+1);G=rd();R=rd();
	rep(i,1,m)rep(j,0,G-1)f[i][j]=M;
	int ql=M,qr=M;
	f[1][0]=0;qr++;q1[qr]=1;q2[qr]=0;
	while(ql<qr)
	{
		ql++;int x=q1[ql],t=q2[ql],w=f[x][t];
		if(x>1)
		{
			int t2=t+p[x]-p[x-1];
			if(t2<G&&f[x-1][t2]==M) 
			{
				f[x-1][t2]=w;
				q1[ql]=x-1;q2[ql]=t2;ql--;
			}
			if(t2==G&&f[x-1][0]==M)
			{
				f[x-1][0]=w+1;
				qr++;q1[qr]=x-1;q2[qr]=0;
			}
		}
		if(x<m)
		{
			int t2=t+p[x+1]-p[x];
			if(t2<G&&f[x+1][t2]==M) 
			{
				f[x+1][t2]=w;
				q1[ql]=x+1;q2[ql]=t2;ql--;
			}
			if(t2==G&&f[x+1][0]==M)
			{
				f[x+1][0]=w+1;
				qr++;q1[qr]=x+1;q2[qr]=0;
			}
		}
	}
	ll ans=inf;
	rep(j,0,G-1)if(f[m][j]!=M)ans=min(ans,1ll*f[m][j]*(G+R)+(j?j:-R));
	printf("%lld\n",ans==inf?-1:ans);return 0;
}