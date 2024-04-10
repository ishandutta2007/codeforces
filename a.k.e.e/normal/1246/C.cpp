#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define k first
#define b second
#define mp make_pair
#define pb push_back
#define enum(i,x,y) for(register int i=(x);i<=(y);++i)
#define try(i,x,y) for(register int i=(x);i>=(y);--i)
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=2005,MOD=1000000007;

int n,m;
char s[MAXN][MAXN];
int num[MAXN][MAXN][2];
int f[MAXN][MAXN][2],pre[MAXN][MAXN][2],whi[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
	#endif
	readint(n);readint(m);
	enum(i,1,n)
	{
		scanf("%s",s[i]+1);
		try(j,m,1)num[i][j][0]=num[i][j+1][0]+(s[i][j]=='R');
	}
	try(i,n,1)
		enum(j,1,m)
			num[i][j][1]=num[i+1][j][1]+(s[i][j]=='R');
	if(n==1 && m==1)return 0*printf("%d\n",s[1][1]=='.');
	enum(j,1,m)whi[j]=1;
	f[1][1][0]=f[1][1][1]=pre[1][1][0]=pre[1][1][1]=1;
	enum(i,1,n)
	{
		int pos=1;
		enum(j,1,m)
		{
			if(i==1 && j==1)continue;
			while(pos<=m && num[i][pos][0]>m-j)++pos;
			if(pos>1)f[i][j][0]=(pre[i][j-1][1]-pre[i][pos-2][1]+MOD)%MOD;
			else f[i][j][0]=pre[i][j-1][1];
			pre[i][j][0]=(pre[i-1][j][0]+f[i][j][0])%MOD;
//cerr<<i<<","<<j<<":"<<pos<<" "<<f[i][j][0]<<" "<<pre[i][j][0]<<endl;
			while(whi[j]<=n && num[whi[j]][j][1]>n-i)++whi[j];
			if(whi[j]>1)f[i][j][1]=(pre[i-1][j][0]-pre[whi[j]-2][j][0]+MOD)%MOD;
			else f[i][j][1]=pre[i-1][j][0];
			pre[i][j][1]=(pre[i][j-1][1]+f[i][j][1])%MOD;
		}
	}
/*enum(i,1,n)
{
	enum(j,1,m)cerr<<f[i][j][1]<<" ";
	cerr<<endl;
}*/
	printf("%d\n",(f[n][m][0]+f[n][m][1])%MOD);
    return 0;
}