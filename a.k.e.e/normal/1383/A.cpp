#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
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
const int MAXN=1000005;

int n;
char a[MAXN],b[MAXN];
bool c[25][25],is[25],si[25];
void solve()
{
	memset(c,0,sizeof(c));
	memset(is,0,sizeof(is));
	memset(si,0,sizeof(si));
	readint(n);scanf("%s%s",a+1,b+1);
	for(int i=1;i<=n;++i)c[a[i]-'a'][b[i]-'a']=1;
	for(int i=0;i<20;++i)
		for(int j=0;j<i;++j)
			if(c[i][j])
			{
				printf("-1\n");
				return;
			}
	int cnt=0;
	for(int i=0;i<20;++i)
	{
		int x=-1;
		for(int j=i+1;j<20;++j)
			if(c[i][j]){x=j;break;}
		if(x<0)continue;
		++cnt;
		for(int j=x+1;j<20;++j)
			if(c[i][j])c[x][j]=1;
	}
	printf("%d\n",cnt);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}