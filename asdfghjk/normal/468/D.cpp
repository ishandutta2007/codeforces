#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
const int N=100005;
struct node
{
	int num,id;
};
bool operator <(node a,node b)
{
	if(a.num!=b.num)
		return a.num>b.num;
	return a.id>b.id;
}
set<int> st[N],mn;
set<int>::iterator ddq;
set<node> w;
set<node>::iterator dg;
int n,i,j,k,size[N],head[N],adj[N*2],nxt[N*2],len[N*2],bl[N],p[N],prt[N],num[N],cnt;
ll dep[N],ans;
void dzx(int x,int dad)
{
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
		{
			dep[adj[y]]=dep[x]+len[y];
			dzx(adj[y],x);
		}
}
void phh(int x,int dad)
{
	bl[x]=cnt;
	st[cnt].insert(x);
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
			phh(adj[y],x);
}
void work(int root)
{
	int i,j,k;
	dep[root]=0;
	dzx(root,-1);
	ans=0;
	for(i=1;i<=n;++i)
		ans+=2*dep[i];
	cnt=0;
	mn.clear();
	w.clear();
	for(i=head[root];i;i=nxt[i])
	{
		++cnt;
		st[cnt].clear();
		phh(adj[i],root);
		mn.insert(*(st[cnt].begin()));
		num[cnt]=2*st[cnt].size();
		w.insert((node){st[cnt].size()*2,cnt});
	}
	++cnt;
	st[cnt].clear();
	st[cnt].insert(root);
	bl[root]=cnt;
	mn.insert(root);
	num[cnt]=2;
	w.insert((node){2,cnt});
	for(i=1;i<=n;++i)
	{
		if(!st[bl[i]].empty())
		{
			dg=w.find((node){num[bl[i]],bl[i]});
			//printf("- %d\n",dg->id);
			w.erase(dg);
			//printf("+ %d\n",bl[i]);
			w.insert((node){num[bl[i]]-1,bl[i]});
			--num[bl[i]];
		}
		dg=w.begin();
		if(dg->id==cnt)
			dg++;
		if(dg!=w.end()&&(dg->id)!=bl[i]&&(dg->num)==n-i+1)
			j=dg->id;
		else
		{
			ddq=mn.begin();
			if(i!=root&&bl[*ddq]==bl[i])
				ddq++;
			j=bl[*ddq];
			//printf("%d\n",j);
		}
		k=*(st[j].begin());
		p[i]=k;
		st[j].erase(k);
		mn.erase(k);
		dg=w.find((node){num[j],j});
		//printf("- %d\n",dg->id);
		/*if(i==2)
		{
			printf("%d %d\n",num[j],j);
			return;
		}*/
		w.erase(dg);
		if(!st[j].empty())
		{
			//printf("+ %d\n",j);
			w.insert((node){num[j]-1,j});
		}
		--num[j];
		if(!st[j].empty())
			mn.insert(*(st[j].begin()));
	}
	for(i=1;i<=n;++i)
		if(p[i]>prt[i])
			return;
		else if(p[i]<prt[i])
			break;
	//if(i<=n)
		for(i=1;i<=n;++i)
			prt[i]=p[i];
}
void dfs(int x,int dad)
{
	bool t=true;
	size[x]=1;
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
		{
			dfs(adj[y],x);
			size[x]+=size[adj[y]];
			if(size[adj[y]]>n/2)
				t=false;
		}
	if(n-size[x]>n/2)
		t=false;
	if(t)
		work(x);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<n;++i)
	{
		scanf("%d%d%d",&j,&k,&len[i*2]);
		adj[i*2-1]=k;
		nxt[i*2-1]=head[j];
		head[j]=i*2-1;
		adj[i*2]=j;
		nxt[i*2]=head[k];
		head[k]=i*2;
		len[i*2-1]=len[i*2];
	}
	prt[1]=1<<30;
	dfs(1,-1);
	printf("%lld\n",ans);
	for(i=1;i<=n;++i)
		printf("%d ",prt[i]);
	return 0;
}