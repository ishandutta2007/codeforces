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
const int MAXN=200005;

int n;
char a[MAXN];
char x[MAXN],y[MAXN];
void solve()
{
	readint(n);
	scanf("%s",a+1);x[n+1]=y[n+1]='\0';
	int u=0,v=0;
	for(int i=1;i<=n;++i)
		if(a[i]=='1')x[i]=y[i]='(',++u,++v;
		else if(u<v)x[i]='(',y[i]=')',++u,--v;
		else x[i]=')',y[i]='(',--u,++v;
	if(u!=v || u<0){printf("NO\n");return;}
	else
	{
		for(int i=n;u;--i)
			if(x[i]=='(' && y[i]=='(')
				u-=2,v-=2,x[i]=y[i]=')';
		u=v=0;
		for(int i=1;i<=n;++i)
		{
			x[i]=='('?++u:--u;
			if(u<0){printf("NO\n");return;}
			y[i]=='('?++v:--v;
			if(v<0){printf("NO\n");return;}
		}
		printf("YES\n%s\n%s\n",x+1,y+1);
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