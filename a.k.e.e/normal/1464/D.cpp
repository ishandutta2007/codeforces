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
const int MOD=1000000007;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=1000005;

int n,a[MAXN];
bool vis[MAXN];
int b[5];
void solve()
{
	memset(b,0,sizeof(b));
	readint(n);
	if(n%3==0)printf("%d ",qmi(3,n/3));
	else if(n%3==1)printf("%d ",qmi(3,(n-4)/3)*4ll%MOD);
	else printf("%d ",qmi(3,(n-2)/3)*2ll%MOD);
	for(int i=1;i<=n;++i)readint(a[i]),vis[i]=0;
	int res=0;
	for(int i=1;i<=n;++i)
	{
		if(vis[i])continue;
		int cnt=0;
		for(int j=i;!vis[j];j=a[j])vis[j]=1,++cnt;
		if(cnt==1)++b[1];
		else if(cnt%3==0)res+=(cnt-3)/3;
		else if(cnt%3==1)res+=(cnt-4)/3,++b[4];
		else if(cnt%3==2)res+=(cnt-2)/3,++b[2];
	}
	int need=(n%3==1);
	if(b[4]>need)b[1]+=b[4]-need,res+=b[4]-need,b[4]=need;
	if(n%3==0)
	{
		while(b[1]<b[2])--b[2],b[1]+=2,++res;
		while(b[1]>b[2])b[1]-=2,++b[2],++res;
		res+=b[1];
	}
	else if(n%3==2)
	{
		while(b[1]<b[2]-1)--b[2],b[1]+=2,++res;
		while(b[1]>b[2]-1)b[1]-=2,++b[2],++res;
		res+=b[1];
	}
	else
	{
		int ex=res;
		res=1<<30;
		int tb1=b[1],tb2=b[2];
		if(b[4])
		{
			int s=0;
			while(b[1]<b[2])--b[2],b[1]+=2,++s;
			while(b[1]>b[2])b[1]-=2,++b[2],++s;
			s+=b[1];
			chkmin(res,ex+s);
			b[1]=tb1,b[2]=tb2;
			++ex;b[1]+=b[4];b[4]=0;
		}
		if(b[1]+b[2]*2>=4)
		{
			int s=0;
			while(b[1]<b[2]-2)--b[2],b[1]+=2,++s;
			while(b[1]>b[2]-2)b[1]-=2,++b[2],++s;
			s+=b[1];
			chkmin(res,ex+s);
			b[1]=tb1,b[2]=tb2;
		}
		int s=0;
		while(b[1]-1<b[2])--b[2],b[1]+=2,++s;
		while(b[1]-1>b[2])b[1]-=2,++b[2],++s;
		s+=b[1];
		chkmin(res,ex+s);
	}
	printf("%d\n",res);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}