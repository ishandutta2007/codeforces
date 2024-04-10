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
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
/*const int MOD=998244353;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}*/
const int MAXN=1005,n=10;

char s[15];
int p1[15],p2[15];
void solve()
{
	scanf("%s",s+1);
	for(int i=1;i<=n;i+=2)if(s[i]!='?')s[i]='1'-(s[i]=='1');
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='?')p1[i]=p1[i-1],p2[i]=p2[i-1]+1;
		else p1[i]=p1[i-1]+s[i]-'0',p2[i]=p2[i-1]+s[i]-'0';
	}
	for(int i=0;i<n;++i)
	{
		int l=p1[i]*2-i,r=p2[i]*2-i;
		if(l+n-i<0 || r-n+i>0){printf("%d\n",i);return;}
	}
	printf("%d\n",n);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}