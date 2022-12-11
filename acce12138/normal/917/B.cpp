// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

int dp[111][111][30],con[111][111],n,m;
int dfs(int x,int y,int v)
{
	if(dp[x][y][v]!=-1)return dp[x][y][v];
	bool ok=0;
	for(int i=1;i<=n;i++)if(con[x][i]>=v&&!dfs(y,i,con[x][i]))ok=1;
	return dp[x][y][v]=ok;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	char op[5];
	get2(n,m);
	for(int i=1,u,v;i<=m;i++)
	{
		get2(u,v);scanf("%s",op);
		con[u][v]=op[0]-'a'+1;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
	{
		for(int k=1;k<=26;k++)dfs(i,j,k);
		printf("%c",dp[i][j][1]?'A':'B');
		if(j==n)puts("");
	}
	return 0;
}