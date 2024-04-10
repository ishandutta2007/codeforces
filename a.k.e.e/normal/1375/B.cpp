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
const int MAXN=305;

int n,m;
int a[MAXN][MAXN];
void solve()
{
	int x;
	readint(n),readint(m);
	bool flag=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			readint(x);
			a[i][j]=4;
			if(i==1 || i==n)--a[i][j];
			if(j==1 || j==m)--a[i][j];
			if(x>a[i][j])flag=0;
		}
	if(!flag)printf("NO\n");
	else
	{
		printf("YES\n");
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
				printf("%d ",a[i][j]);
			putchar('\n');
		}
	}
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