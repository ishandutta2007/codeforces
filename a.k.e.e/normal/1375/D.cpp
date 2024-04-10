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
const int MAXN=2005;

int n,a[MAXN];
bool vis[MAXN];
int m,op[MAXN];
void solve()
{
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i]);
	m=0;
	while(1)
	{
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;++i)vis[a[i]]=1;
		int x;
		for(int i=0;i<=n;++i)if(!vis[i]){x=i;break;}
		if(x==n)
		{
			for(int i=1;i<=n;++i)
				if(a[i]!=i-1){op[++m]=i;a[i]=n;break;}
		}
		else
		{
			op[++m]=x+1;
			a[x+1]=x;
		}
		bool flag=1;
		for(int i=1;i<n;++i)
			if(a[i]>a[i+1]){flag=0;break;}
		if(flag)break;
	}
	printf("%d\n",m);
	for(int i=1;i<=m;++i)printf("%d ",op[i]);
	putchar('\n');
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