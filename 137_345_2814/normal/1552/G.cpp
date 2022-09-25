#include<cstdio>
using namespace std;
#define N 45
#define ll long long
int n,k,s,a,is[N],ct[N],fg;
ll tp[N],su[N][N];
void dfs(int d,ll v)
{
	if(fg)return;
	if(d==k+1){fg|=((v+1)&(-v-1))!=v+1;return;}
	int s1=__builtin_popcountll(v&tp[d]);v-=v&tp[d];
	for(int i=0;i<=ct[d];i++)dfs(d+1,v|su[d][i+s1]);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&s);
		for(int j=1;j<=s;j++)
		{
			scanf("%d",&a);
			if(!is[a])is[a]=1,ct[i]++;
			su[i][j]=su[i][j-1]|(1ll<<a-1);
		}
		tp[i]=su[i][s];
	}
	for(int i=1;i<=n;i++)if(!is[i]&&n>1)fg=1;
	dfs(0,0);
	printf("%s\n",fg?"REJECTED":"ACCEPTED");
}