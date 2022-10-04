#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
/*const int MOD=;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}*/
const int MAXN=400005;

int n,to[MAXN];
bool vis[MAXN],on[MAXN];
int a[MAXN],b[MAXN],Max,sum;
int work(int l)
{
//cerr<<l<<endl;
	if(l>n)return 0;
	int cx=0,cy=0,u=l,y=l,v=2*n-l+1;
	while(1)
	{
		vector<int> c;
		for(int i=u;i<=y;++i)if(!vis[i])c.pb(to[i]),vis[i]=1,++cx,cy+=on[i],chkmax(Max,i),++sum;
		for(int i=1;i<c.size();++i)if(c[i]>c[i-1])exit(0*printf("-1\n"));
		for(int i=0;i<c.size();++i)vis[c[i]]=1,chkmax(Max,2*n-c[i]+1),++sum;
		int x=c.back();
//cerr<<u<<" "<<y<<" "<<x<<" "<<v<<endl;
		if(x<=n)exit(0*printf("-1\n"));
		if(sum==Max*2)return work(Max+1)+min(cy,cx-cy);
		c.clear();
		for(int i=v;i>=x;--i)if(!vis[i])c.pb(to[i]),vis[i]=1,++cx,cy+=on[i],chkmax(Max,2*n-i+1),++sum;
		for(int i=1;i<c.size();++i)if(c[i]<c[i-1])exit(0*printf("-1\n"));
		for(int i=0;i<c.size();++i)vis[c[i]]=1,chkmax(Max,c[i]),++sum;
		u=y+1;y=c.back();
		if(y>n)exit(0*printf("-1\n"));
		if(sum==Max*2)return work(Max+1)+min(cy,cx-cy);
//cerr<<u<<" "<<y<<" "<<x<<" "<<v<<" "<<Max<<" "<<sum<<endl;
		v=x-1;
	}
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)
	{
		int x,y;
		readint(x),readint(y);
		to[x]=y,to[y]=x;
		on[x]=1;
	}
	printf("%d\n",work(1));
	return 0;
}