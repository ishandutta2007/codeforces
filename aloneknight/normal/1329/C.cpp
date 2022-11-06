#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
#define db double
#define ld long double
#define pii pair<int,int> 
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<a.size();++i) 
inline int rd()
{
	int x=0,w=1;char c=getchar();while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')w=-1,c=getchar();while(isdigit(c))x=x*10+c-48,c=getchar();return x*w;
}
const int N=1<<21;
int h,g,hh,gg,lg[N],a[N],d[N];
priority_queue<pair<int,int> >Q;
void del(int x)
{
	int l=x*2,r=x*2+1;
	if(!a[l]&&!a[r])a[x]=0,d[x]=0;
	else
	{
		if(a[l]>a[r])
		{
			a[x]=a[l];
			del(l);
		}
		else if(a[r]>a[l])
		{
			a[x]=a[r];
			del(r);
		}
	}
	if(!a[x])d[x]=0;
	else if(!a[l]&&!a[r])d[x]=lg[x];
	else if(a[l]>a[r])d[x]=d[l];
	else if(a[r]>a[l])d[x]=d[r];
}
void ins(int x)
{
	if(!d[x])return;
	int l=x*2,r=x*2+1;
	if(a[l]>a[r])
	{
		ins(l);
		if(a[r]&&d[r]>g)Q.push(mp(a[r],r));
		else if(d[r]==g)ins(r);
	}
	else if(a[r]>a[l])
	{
		ins(r);
		if(a[l]&&d[l]>g)Q.push(mp(a[l],l));
		else if(d[l]==g)ins(l);
	}
}
int main()
{
	int T;T=rd();
	rep(i,1,N-1)lg[i]=lg[i>>1]+1;
	while(T--)
	{
		vi V;V.clear();
		while(!Q.empty())Q.pop();
		h=rd();g=rd();hh=1<<h;gg=1<<g;
		hh--;gg--;int tt=hh-gg;ll ans=0;
		rep(i,1,hh)a[i]=a[i*2]=a[i*2+1]=0;
		rep(i,1,hh)a[i]=rd(),d[i]=h,ans+=a[i];
		Q.push(mp(a[1],1));
		rep(i,1,tt)
		{
			int x=Q.top().Y;
			ans-=Q.top().X;Q.pop();
			V.pb(x);del(x);
			if(d[x]==g)ins(x);
			else Q.push(mp(a[x],x));
		}
		printf("%lld\n",ans);
		fore(i,V)printf("%d ",V[i]);puts("");
	}
	return 0;
}