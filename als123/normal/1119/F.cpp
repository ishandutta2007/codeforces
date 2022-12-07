#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue> 
using namespace std;
typedef long long LL;
typedef pair<int,int> PI;
const LL N=250005;
LL n;
vector<PI> e[N];
vector<LL> vec[N];
LL du[N];
bool cmp (PI x,PI y)	{return du[x.first]<du[y.first];}
LL nxt[N];
struct qq
{
	priority_queue<LL> A,B;
	void push (LL x)	{A.push(x);}
	void del (LL x)	{B.push(x);}
	LL top ()	{while (!B.empty()&&A.top()==B.top()) A.pop(),B.pop();return A.top();}
	void pop ()	{top();A.pop();}
	LL size() {return A.size()-B.size();}
}h[N];
bool vis[N];
LL sum[N];//sum 
void upd (LL x,LL num)	
{
	while (h[x].size()>num)	
	{
		sum[x]=sum[x]-h[x].top();
		h[x].pop();
	}
}
void upd1 (LL x,LL num,vector<LL> & add)
{
	while (h[x].size()>num)	
	{
		sum[x]=sum[x]-h[x].top();add.push_back(h[x].top());h[x].pop();
	}
}
void dele (LL x)// 
{
//	printf("del:%lld\n",x);
	vis[x]=true;
	for (LL u=0;u<e[x].size();u++)
	{
		LL y=e[x][u].first,c=e[x][u].second;	
		if (vis[y]) continue;
		//printf("del:%lld %lld\n",y,c);
		h[y].push(c);	sum[y]=sum[y]+c;
	}
}
LL f[N][2],D;
//0:x    1:x+1 
LL st[N];
void dfs (LL x)
{
	vis[x]=true;LL num=du[x]-D;	
//	printf("%lld %lld %lld %lld\n",x,h[x].size(),num,sum[x]);
	upd(x,num);

	vector<LL> add,del;
	add.clear();del.clear();
	LL siz=e[x].size(),tot=0;
	while (st[x]<siz&&du[e[x][st[x]].first]<=D) st[x]++;
	for (LL u=st[x];u<siz;u++)
	{
		LL y=e[x][u].first,c=e[x][u].second;
		if (vis[y]) continue;
		dfs(y);
		if (f[y][1]+c<=f[y][0])	{num--;tot=tot+f[y][1]+c;}
		else
		{
			tot=tot+f[y][0];
			LL o=f[y][1]+c-f[y][0];
			del.push_back(o);	h[x].push(o);
			sum[x]=sum[x]+o;
		}
	}
	
//	printf("%lld %lld %lld\n",h[x].size(),sum[x],num);
	upd1(x,max(0LL,num),add);
	f[x][0]=tot+sum[x];
	upd1(x,max(0LL,num-1),add);
	f[x][1]=tot+sum[x];
	for (LL u=0;u<add.size();u++) 
	{
		h[x].push(add[u]),sum[x]+=add[u];
	//	printf("add:%lld\n",add[u]);
	}
	for (LL u=0;u<del.size();u++) 
	{
	//	printf("del:%lld\n",del[u]);
		h[x].del(del[u]),sum[x]-=del[u];
	}
//	printf("sum:%lld %lld %lld\n",x,f[x][1],f[x][0]);
}
int main()
{
	scanf("%lld",&n);
	LL ans=0;
	for (LL u=1;u<n;u++)
	{
		LL x,y,c;
		scanf("%lld%lld%lld",&x,&y,&c);
		e[x].push_back({y,c});e[y].push_back({x,c});
		du[x]++;du[y]++;
		ans=ans+c;
	}
	printf("%lld ",ans);
	for (LL u=1;u<=n;u++)
	{
		vec[du[u]].push_back(u);
		sort(e[u].begin(),e[u].end(),cmp);
	}
	nxt[n]=n+1;
	for (LL u=n-1;u>=1;u--)
	{
		if (vec[u+1].size()) nxt[u]=u+1;
		else nxt[u]=nxt[u+1];
	}
	memset(vis,false,sizeof(vis));
	for (LL u=1;u<n;u++)
	{
		for (LL i=0;i<vec[u].size();i++) dele(vec[u][i]);
		ans=0;D=u;
		for (LL i=u+1;i<=n;i=nxt[i])	for (LL j=0;j<vec[i].size();j++)
		{
			if (vis[vec[i][j]]==true) continue;
			dfs(vec[i][j]);
			ans=ans+f[vec[i][j]][0];
		}
		for (LL i=u+1;i<=n;i=nxt[i])	for (LL j=0;j<vec[i].size();j++)	vis[vec[i][j]]=false;
		printf("%lld ",ans);
	}
	return 0;
}