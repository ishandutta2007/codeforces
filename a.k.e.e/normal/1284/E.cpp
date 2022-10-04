#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=5005;

int n,x[MAXN],y[MAXN],m;
struct Angle
{
	int x,y,more;
	Angle(){}
	Angle(int xx,int yy)
	{
		if(xx>0 && yy>=0)x=xx,y=yy,more=0;
		else if(xx<=0 && yy>0)x=yy,y=-xx,more=1;
		else if(xx<0 && yy<=0)x=-xx,y=-yy,more=2;
		else x=-yy,y=xx,more=3;
	}
	Angle(int x,int y,int more):x(x),y(y),more(more){}
	inline bool operator <(const Angle &b)const
		{return more!=b.more?more<b.more:1ll*x*b.y>1ll*y*b.x;}
	inline Angle operator +(int t)const
		{return Angle(x,y,more+t);}
}ang[MAXN];
inline int lb(Angle a){return lower_bound(ang+1,ang+2*m+1,a)-ang;}
inline int ub(Angle a){return upper_bound(ang+1,ang+2*m+1,a)-ang;}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)
		readint(x[i]),readint(y[i]);
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		ans+=1ll*(n-1)*(n-2)*(n-3)*(n-4)/24;
		m=0;
		for(int j=1;j<=n;++j)if(i!=j)ang[++m]=Angle(x[j]-x[i],y[j]-y[i]);
		sort(ang+1,ang+m+1);
		for(int j=1;j<=m;++j)ang[j+m]=ang[j]+4;
		for(int j=1;j<=m;++j)
		{
			int t=lb(ang[j]+2)-j;
			ans-=1ll*(t-1)*(t-2)*(t-3)/6;
		}
	}
	printf("%lld\n",ans);
	return 0;
}