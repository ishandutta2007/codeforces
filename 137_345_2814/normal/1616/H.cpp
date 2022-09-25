#include<cstdio>
using namespace std;
#define N 150050
#define M 5910001
#define mod 998244353
int n,k,v[N],ch[M][2],sz[M],pw[N],ct=1,as,a;
void ins(int v)
{
	int nw=1;
	for(int d=29;d>=0;d--)
	{
		int tp=(v>>d)&1;
		if(!ch[nw][tp])ch[nw][tp]=++ct;
		nw=ch[nw][tp],sz[nw]++;
	}
}
int solve(int x,int y,int d)
{
	if(!x||!y||!d)return pw[sz[x]+sz[y]];
	int tp=(k>>d-1)&1;
	if(tp)return 1ll*solve(ch[x][0],ch[y][1],d-1)*solve(ch[x][1],ch[y][0],d-1)%mod;
	else return (4ll*mod+pw[sz[x]]-pw[sz[ch[x][0]]]-pw[sz[ch[x][1]]]+pw[sz[y]]-pw[sz[ch[y][0]]]-pw[sz[ch[y][1]]]+solve(ch[x][0],ch[y][0],d-1)+solve(ch[x][1],ch[y][1],d-1)+1)%mod;
}
void dfs(int x,int d)
{
	if(!x)return;
	if(!d){as=(as+pw[sz[x]]-1)%mod;return;}
	if((1<<d-1)<=k){as=(as+solve(ch[x][0],ch[x][1],d-1)-1)%mod;return;}
	dfs(ch[x][0],d-1);dfs(ch[x][1],d-1);
}
int main()
{
	scanf("%d%d",&n,&k);
	pw[0]=1;
	for(int i=1;i<=n;i++)scanf("%d",&a),pw[i]=2*pw[i-1]%mod,ins(a);
	dfs(1,30);
	printf("%d\n",(as+mod)%mod);
}