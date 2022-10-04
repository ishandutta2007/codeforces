#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:TYPE();}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:TYPE();}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=1005;

int n,m,cnt;
char str[MAXN];
int a[MAXN][MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(m);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",str+1);
		for(int j=1;j<=m;++j)a[i][j]=(str[j]=='#');
	}
	bool col=0,row=0;
	for(int j=1;j<=m;++j)
	{
		int sum=0,l=n,r=0;
		for(int i=1;i<=n;++i)
			if(a[i][j])++sum,chkmin(l,i),chkmax(r,i);
		if(sum && r-l+1!=sum)return 0*printf("-1\n");
		if(!sum)col=1;
	}
	for(int i=1;i<=n;++i)
	{
		int sum=0,l=m,r=0;
		bool flag=0;
		for(int j=1;j<=m;++j)
			if(a[i][j])
			{
				++sum,chkmin(l,j),chkmax(r,j);
				if(a[i-1][j])flag=1;
			}
		if(sum && r-l+1!=sum)return 0*printf("-1\n");
		if(!sum && !col)return 0*printf("-1\n");
		if(sum && !flag)++cnt;
		if(!sum)row=1;
	}
	if(col && !row)return 0*printf("-1\n");
	printf("%d\n",cnt);
	return 0;
}