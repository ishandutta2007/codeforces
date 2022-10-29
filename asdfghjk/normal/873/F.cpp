#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=400005;
struct node
{
	int fa,len,ch[26];
}a[N];
int n,lst,cnt,i,j,size[N],head[N],adj[N],nxt[N];
long long ans;
char s[N],t[N];
void dfs(int x)
{
	for(int y=head[x];y;y=nxt[y])
	{
		dfs(adj[y]);
		size[x]+=size[adj[y]];
	}
	ans=max(ans,1ll*a[x].len*size[x]);
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%s",t+1);
	lst=cnt=1;
	for(i=1;i<=n;++i)
	{
		j=s[i]-'a';
		int p,np;
		p=lst;
		np=lst=++cnt;
		if(t[i]=='0')
			size[cnt]=1;
		a[np].len=a[p].len+1;
		for(;p&&!a[p].ch[j];p=a[p].fa)
			a[p].ch[j]=np;
		if(!p)
			a[np].fa=1;
		else
		{
			int q=a[p].ch[j];
			if(a[q].len==a[p].len+1)
				a[np].fa=q;
			else
			{
				int nq=++cnt;
				a[nq]=a[q];
				a[nq].len=a[p].len+1;
				a[np].fa=a[q].fa=nq;
				for(;p&&a[p].ch[j]==q;p=a[p].fa)
					a[p].ch[j]=nq;
			}
		}
	}
	for(i=2;i<=cnt;++i)
	{
		adj[i-1]=i;
		nxt[i-1]=head[a[i].fa];
		head[a[i].fa]=i-1;
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}