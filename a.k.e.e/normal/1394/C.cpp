#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){x>y?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
const int MOD=998244353;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=500005,INF=0x3f3f3f3f;

int n;
char str[MAXN];
int x[MAXN],y[MAXN];
struct State
{
	int xl,xr,yl,yr,sl,sr;
	State(){}
	State(int xl,int xr,int yl,int yr,int sl,int sr):xl(xl),xr(xr),yl(yl),yr(yr),sl(sl),sr(sr){}
};
State onion(State s,State t)
{
	return State(max(s.xl,t.xl),min(s.xr,t.xr),max(s.yl,t.yl),min(s.yr,t.yr),max(s.sl,t.sl),min(s.sr,t.sr));
}
pii p;
State s;
bool check(int mid)
{
	s=State(-INF,INF,-INF,INF,-INF,INF);
	for(int i=1;i<=n;++i)s=onion(s,State(x[i]-mid,x[i]+mid,y[i]-mid,y[i]+mid,y[i]-x[i]-mid,y[i]-x[i]+mid));
//cerr<<mid<<": "<<s.xl<<" "<<s.xr<<" "<<s.yl<<" "<<s.yr<<" "<<s.sl<<" "<<s.sr<<endl;
	return s.xl<=s.xr && s.yl<=s.yr && s.sl<=s.sr && s.yl-s.xr<=s.sr && s.yr-s.xl>=s.sl;
}
bool ok(int x,int y){return x>=s.xl && x<=s.xr && y>=s.yl && y<=s.yr && y-x>=s.sl && y-x<=s.sr;}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",str+1);
		int m=strlen(str+1);
		for(int j=1;j<=m;++j)
			if(str[j]=='N')++x[i];
			else ++y[i];
	}
	int L=0,R=1000000,mid,ans=INF;
	while(L<=R)
	{
		mid=(L+R)>>1;
		if(check(mid))R=mid-1,ans=mid;
		else L=mid+1;
	}
	check(ans);
	printf("%d\n",ans);
	int u=0,v=0;
	if(ok(s.xl,s.sr+s.xl))u=s.xl,v=s.sr+s.xl;
	else if(ok(s.xr,s.sr+s.xr))u=s.xr,v=s.sr+s.xr;
	else if(ok(s.yl-s.sr,s.yl))u=s.yl-s.sr,v=s.yl;
	else if(ok(s.yr-s.sr,s.yr))u=s.yr-s.sr,v=s.yr;
	else if(ok(s.xl,s.sl+s.xl))u=s.xl,v=s.sl+s.xl;
	else if(ok(s.xr,s.sl+s.xr))u=s.xr,v=s.sl+s.xr;
	else if(ok(s.yl-s.sl,s.yl))u=s.yl-s.sl,v=s.yl;
	else if(ok(s.yr-s.sl,s.yr))u=s.yr-s.sl,v=s.yr;
	if(u<0)u=0;
	if(v<0)v=0;
	if(!u && !v)u=v=1;
	while(u--)putchar('N');
	while(v--)putchar('B');
	return 0;
}