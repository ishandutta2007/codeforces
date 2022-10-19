#include<cstdio>
#include<queue>
using namespace std;
int n,k,Test_num,edge_t,p,ans;
int la[200008],deg[200008],cnt[200008];
queue<int> q;
struct aaa
{
	int to,nx,used;
}edge[400008];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x],0},la[x]=edge_t,++deg[x];
	edge[++edge_t]=(aaa){x,la[y],0},la[y]=edge_t,++deg[y];
}
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)
	{
		scanf("%d%d",&n,&k),edge_t=1,ans=0;
		for(int i=1;i<=n;++i)la[i]=deg[i]=cnt[i]=0;
		for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
		if(k==1){printf("%d\n",n-1);continue;}
		for(int i=1,v;i<=n;++i)
			if(deg[i]==1)
			{
				++cnt[edge[la[i]].to],edge[la[i]].used=edge[la[i]^1].used=1;
				if(cnt[v=edge[la[i]].to]==k)q.push(v);
			}
		while(!q.empty())
		{
			p=q.front(),q.pop(),deg[p]-=cnt[p],ans+=cnt[p]/k,cnt[p]%=k,deg[p]+=cnt[p];
			if(deg[p]==1)
				for(int i=la[p],v;i;i=edge[i].nx)
					if(!edge[i].used)
					{
						++cnt[v=edge[i].to],edge[i].used=edge[i^1].used=1;
						if(cnt[v]==k)q.push(v);
					}
		}
		printf("%d\n",ans);
	}
	return 0;
}