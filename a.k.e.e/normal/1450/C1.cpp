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
const int MOD=1019260817;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=305;

int n;
char a[MAXN][MAXN];
int cnt[3][2];
void solve()
{
	readint(n);
	for(int i=1;i<=n;++i)scanf("%s",a[i]+1);
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(a[i][j]!='.')++cnt[(i+j)%3][a[i][j]=='X'];
/*	for(int i=0;i<3;++i)
	{
		for(int j=0;j<2;++j)
			cerr<<cnt[i][j]<<" "; 
		cerr<<endl;
	}*/
	char o[2]={'O','X'};
	for(int i=0;i<3;++i)
		for(int j=0;j<2;++j)
			if(cnt[i][j]-2*cnt[i][j^1]
				+cnt[(i+1)%3][j^1]-2*cnt[(i+1)%3][j]
				+cnt[(i+2)%3][j^1]-2*cnt[(i+2)%3][j]>=0)
			{
				for(int x=1;x<=n;++x)
				{
					for(int y=1;y<=n;++y)
						if(a[x][y]=='.')putchar('.');
						else if((x+y)%3==i)putchar(o[j]);
						else putchar(o[j^1]);
					putchar('\n');
				}
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