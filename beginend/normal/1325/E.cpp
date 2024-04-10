#include<bits/stdc++.h>
#define pb push_back

const int maxn=1000000;

int n,now,tim[maxn+5],dis[maxn+5],tot,prime[maxn/10],low[maxn+5];
bool not_prime[maxn+5];
std::queue<int> que;
std::vector<int> e[maxn+5];

void get_prime(int n)
{
	for (int i=2;i<=n;i++)
	{
		if (!not_prime[i]) prime[++tot]=i,low[i]=i;
		for (int j=1;j<=tot&&i*prime[j]<=n;j++)
		{
			not_prime[i*prime[j]]=1;
			low[i*prime[j]]=prime[j];
			if (i%prime[j]==0) break;
		}
	}
}

int bfs(int s)
{
	now++;
	dis[s]=0;tim[s]=now;
	que.push(s);
	int ans=maxn;
	while (!que.empty())
	{
		int x=que.front();que.pop();
		for (int to:e[x])
			if (tim[to]!=now) dis[to]=dis[x]+1,tim[to]=now,que.push(to);
			else if (dis[to]>=dis[x]) ans=std::min(ans,dis[x]+dis[to]+1);
	}
	return ans;
}

int main()
{
	get_prime(maxn);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		while (x>1&&x/low[x]%low[x]==0) x/=low[x]*low[x];
		if (x==1) {puts("1");return 0;}
		int p=low[x];
		if (x/p>1&&not_prime[x/p])
		{
			if (x/p%p==0) x/=p*p;
			else x=p;
		}
		if (x==1) {puts("1");return 0;}
		if (x==low[x]) e[1].pb(x),e[x].pb(1);
		else e[low[x]].pb(x/low[x]),e[x/low[x]].pb(low[x]);
	}
	int ans=maxn;
	for (int i=1;i*i<=maxn;i++) ans=std::min(ans,bfs(i));
	if (ans==maxn) ans=-1;
	printf("%d\n",ans);
	return 0;
}