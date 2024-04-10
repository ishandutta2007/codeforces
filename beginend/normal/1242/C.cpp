#include<bits/stdc++.h>
#define mp std::make_pair

typedef long long LL;
typedef std::pair<int,int> pi;

const int N=20;
const int M=5005;

int n,s[N],nx[N][M][2],bin[N],vis[N][M],tim,pos[N],top;
LL a[N][M],val[N],cho[N];
bool f[50005],use[N],flag[N];
pi ans[50005],stack[N*M];
std::map<LL,pi> ma;

void dfs(int x,int y)
{
	stack[++top]=mp(x,y);
	vis[x][y]=tim;
	if (!nx[x][y][0]) return;
	int p=nx[x][y][0],q=nx[x][y][1];
	if (vis[p][q]==tim)
	{
		int sta=bin[p-1];
		for (int i=1;i<=n;i++) use[i]=0;
		use[p]=1;
		while (stack[top]!=mp(p,q))
		{
			int x=stack[top].first;
			if (use[x]) return;
			sta+=bin[x-1];use[x]=1;top--;
		}
		f[sta]=1;ans[sta]=mp(p,q);
	}
	else if (!vis[p][q]) dfs(p,q);
}

void work(int sta)
{
	if (ans[sta]==mp(0,0))
	{
		for (int i=(sta-1)&sta;i;i=(i-1)&sta)
			if (f[i]&&f[sta-i])
			{
				work(i);work(sta-i);
				return;
			}
	}
	else
	{
		int x=ans[sta].first,y=ans[sta].second;
		while (!flag[x])
		{
			flag[x]=1;
			cho[x]=a[x][y];pos[nx[x][y][0]]=x;
			int p=nx[x][y][0],q=nx[x][y][1];
			x=p;y=q;
		}
	}
}

int main()
{
	scanf("%d",&n);
	LL sum=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
		for (int j=1;j<=s[i];j++)
			scanf("%lld",&a[i][j]),sum+=a[i][j],val[i]+=a[i][j],ma[a[i][j]]=mp(i,j);
	}
	if (sum%n!=0)
	{
		puts("No");
		return 0;
	}
	sum/=n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=s[i];j++)
		{
			LL w=sum-val[i]+a[i][j];
			if (ma[w]==mp(0,0)) continue;
			int x=ma[w].first,y=ma[w].second;
			if (x==i&&y!=j) continue;
			nx[i][j][0]=x;nx[i][j][1]=y;
		}
	bin[0]=1;
	for (int i=1;i<=n;i++) bin[i]=bin[i-1]*2;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=s[i];j++)
		{
			if (vis[i][j]) continue;
			tim++;
			top=0;
			dfs(i,j);
		}
	for (int i=1;i<bin[n];i++)
		for (int j=i;j;j=(j-1)&i)
			f[i]|=f[j]&f[i-j];
	if (!f[bin[n]-1]) {puts("No");return 0;}
	puts("Yes");
	work(bin[n]-1);
	for (int i=1;i<=n;i++) printf("%lld %d\n",cho[i],pos[i]);
	return 0;
}