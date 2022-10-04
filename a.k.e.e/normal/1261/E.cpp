#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=1005;

int n;
int a[MAXN];
int res[MAXN][MAXN];
bool vis[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i]);
//	sort(a+1,a+n+1);
	vis[0]=vis[n+1]=1;
	for(int i=1;i<=n;++i)
	{
		int las=0,L=0,R=0;
		for(int j=1;j<=n+1;++j)
			if(vis[j])
			{
				if(j-las>=2)
				{
					L=las+1,R=j;
					break;
				}
				las=j;
			}
//for(int j=1;j<=n+1;++j)cerr<<vis[j]<<" ";cerr<<": "<<L<<" "<<R<<endl;
		if(a[i]<=R-L)
		{
			for(int j=L;j<L+a[i];++j)res[j][i]=1;
			vis[L+a[i]-1]=1;
		}
		else
		{
			for(int j=L;j<R;++j)res[j][i]=1;
			vis[R-1]=1;
			a[i]-=R-L;
			for(int j=1;j<L;++j)
				if(a[i])res[j][i]=1,--a[i];
			for(int j=R+1;j<=n+1;++j)
				if(a[i])res[j][i]=1,--a[i];
		}
	}
	int cnt=0;
	for(int i=1;i<=n+1;++i)
	{
		bool flag=0;
		for(int j=1;j<=n;++j)flag|=res[i][j];
		cnt+=flag;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=n+1;++i)
	{
		bool flag=0;
		for(int j=1;j<=n;++j)flag|=res[i][j];
		if(flag)
		{
			for(int j=1;j<=n;++j)putchar('0'+res[i][j]);
			putchar('\n');
		}
	}
	return 0;
}