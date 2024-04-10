#include<cstdio>
#include<map>
using namespace std;
#define N 100400
#define M 406
#define ll long long
int n,m,v[M][N],ct,su[N],ci[N];
ll as;
map<int,int> tp;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	{
		scanf("%d",&v[i][j]);
		if(!tp[v[i][j]])tp[v[i][j]]=++ct;
		v[i][j]=tp[v[i][j]];su[v[i][j]]++;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	{
		int sv=ci[v[i][j]];ci[v[i][j]]++;
		as+=1ll*i*(sv*2-su[v[i][j]]+1);
	}
	for(int i=1;i<=n*m;i++)ci[i]=0;
	for(int j=1;j<=m;j++)for(int i=1;i<=n;i++)
	{
		int sv=ci[v[i][j]];ci[v[i][j]]++;
		as+=1ll*j*(sv*2-su[v[i][j]]+1);
	}
	printf("%lld\n",as);
}