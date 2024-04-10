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
const int MAXN=300005;

int n;
char a[3][MAXN];
int cnt[3];
void solve()
{
	readint(n);
	for(int i=0;i<3;++i)
	{
		cnt[i]=0;
		scanf("%s",a[i]);
		for(int j=0;j<2*n;++j)cnt[i]+=a[i][j]-'0';
	}
	for(int i=0;i<3;++i)
	{
		int j=(i+1)%3,fl;
		if(cnt[i]>=n && cnt[j]>=n)fl=1;
		else if(cnt[i]<=n && cnt[j]<=n)fl=0;
		else fl=-1;
		if(fl<0)continue;
		for(int x=0,y=0;x<2*n || y<2*n;)
		{
			if(x==2*n)putchar(a[j][y++]);
			else if(y==2*n)putchar(a[i][x++]);
			else if(a[i][x]==a[j][y])putchar(a[i][x]),++x,++y;
			else if(a[i][x]!='0'+fl)putchar(a[i][x++]);
			else putchar(a[j][y++]);
		}
		putchar('\n');
		return;
	}
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