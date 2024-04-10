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
const int MAXN=100005;

char a[MAXN];
int n,pre[MAXN][2],suf[MAXN][2];
ll x[2];

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	scanf("%s",a+1);
	n=strlen(a+1);
	readint(x[0]),readint(x[1]);
	for(int i=1;i<=n;++i)
		for(int j=0;j<=1;++j)
			pre[i][j]=pre[i-1][j]+(a[i]=='0'+j);
	for(int i=n;i;--i)
		for(int j=0;j<=1;++j)
			suf[i][j]=suf[i+1][j]+(a[i]=='0'+j);
	ll res=1ll<<60;
	for(int j=0;j<=1;++j)
	{
		ll sum=0;
		for(int i=1;i<=n;++i)
			if(a[i]=='?')sum+=x[j^1]*pre[i][j^1]+x[j]*suf[i][j^1];
		chkmin(res,sum);
		for(int i=1;i<=n;++i)
			if(a[i]=='?')
			{
				sum-=x[j^1]*(i-1-pre[i-1][j])+x[j]*suf[i][j^1];
				sum+=x[j]*pre[i][j]+x[j^1]*(n-i-suf[i+1][j^1]);
				chkmin(res,sum);
			}
	}
	for(int i=1;i<=n;++i)
		if(a[i]=='0')res+=pre[i][1]*x[1];
		else if(a[i]=='1')res+=pre[i][0]*x[0];
	cout<<res<<endl;
	return 0;
}