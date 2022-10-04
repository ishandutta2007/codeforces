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
const int MAXN=3005,MOD=998244353;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}

int n,m;
char a[MAXN],b[MAXN];
int f[MAXN][MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1),m=strlen(b+1);
	for(int i=1;i<=m;++i)if(a[1]==b[i])f[1][i]=2;
	int res=0;
	int mi=1;
	for(int i=2;i<=n;++i)
	{
		mi=dmy(mi<<1);
		for(int j=1;j<=m;++j)
		{
			if(a[i]==b[j])inc(f[i][j],f[i-1][j+1]);
			if(a[i]==b[j+i-1])inc(f[i][j],f[i-1][j]);
			if(a[i]==b[m] && j==m)inc(f[i][j],mi);
			if(j+i-1>m)inc(f[i][j],f[i-1][j]);
		}
	}
	for(int i=m;i<=n;++i)
		inc(res,f[i][1]);
	printf("%d\n",res);
	return 0;
}