#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define pb push_back
#define mp make_pair
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template <typename T> void readint(T &x)
{
	int f=1;char c;x=0;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
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
const int MAXN=100005;

int n,a[MAXN],res[MAXN];
pii f[MAXN];
bool checkd(int mid)
{
	int cur=0;
	for(int i=1;i<=n;++i)
	{
		cur+=mid;
		chkmax(cur,a[i]);
		if(cur>a[i+1])return 0;
	}
	return 1;
}
bool checku(int mid)
{
	int cur=0;
	for(int i=1;i<=n;++i)
	{
		cur+=mid;
		chkmin(cur,a[i+1]);
		if(cur<a[i])return 0;
	}
	return cur>=a[n+1];
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int useless;readint(useless),readint(n);a[n+1]=useless;
	for(int i=1;i<=n;++i)readint(a[i]);
	int rd=0,ru=a[n+1];
	int L=1,R=a[n+1]-1,mid;
	while(L<=R)
	{
		mid=(L+R)>>1;
		if(checkd(mid))rd=mid,L=mid+1;
		else R=mid-1;
	}
	L=1,R=a[n+1]-1,mid;
	while(L<=R)
	{
		mid=(L+R)>>1;
		if(checku(mid))ru=mid,R=mid-1;
		else L=mid+1;
	}
	int cd=0,cu=0;
	f[0]=mp(0,0);
	for(int i=1;i<=n;++i)f[i]=mp(max(f[i-1].x+rd,a[i]),min(f[i-1].y+ru,a[i+1]));
	res[n]=a[n+1];
	for(int i=n;i;--i)res[i-1]=max(res[i]-ru,f[i-1].x);
	for(int i=0;i<n;++i)printf("%d %d\n",res[i],res[i+1]);
	return 0;
}