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
const int MAXN=505;

int n,m,a[MAXN][MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(m);
	bool flag=(n>m);
	if(flag)swap(n,m);
	if(n==1 && m==1)return 0*printf("0\n");
	if(n==1)for(int i=1;i<=m;++i)a[1][i]=i+1;
	else
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				a[i][j]=i*(j+n);
	}
	if(flag)
	{
		for(int i=1;i<=m;++i)
		{
			for(int j=1;j<=n;++j)
				printf("%d ",a[j][i]);
			printf("\n");
		}
	}
	else
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
				printf("%d ",a[i][j]);
			printf("\n");
		}
	}
	return 0;
}