#include<bits/stdc++.h>
#define LL long long
using namespace std;
int k,num_t=0,edge_t=0,p,ok,Mx,col_t=0,t;
LL res=0;
int n[16],arr[75002],id[75002],la[75002]={},deg[75002]={},to[75002],ans1[16],ans2[16],from[32768],col[75002],g[32768],cnt[16]={};
bitset<32768> f;
LL sum[16];
vector<int> v1,v2;
vector<int> vec[16],num[16],vvec[32768],vnum[32768];
queue<int> q;
struct aaa
{
	int to,nx;
}edge[75002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(int a,int b)
{
	return arr[a]<arr[b]? 1:0;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t,++deg[y];
}
inline int binary_search(LL x)
{
	int l=1,r=num_t,mid;
	while(l<=r)
	{
		mid=((l+r)>>1);
		if(arr[id[mid]]==x)return mid;
		if(arr[id[mid]]<x)l=mid+1;
		else r=mid-1;
	}
	return 0;
}
inline void Topo()
{
	for(int i=1;i<=num_t;++i)if(!deg[i])q.push(i);
	while(!q.empty())
	{
		p=q.front(),q.pop();
		for(int i=la[p],v;i;i=edge[i].nx)
			if(!(--deg[v=edge[i].to]))
				q.push(v);
	}
}
inline void dfs(int x,int y,int c)
{
	col[x]=c,t|=(1<<(to[x]-1)),v1.push_back(x),v2.push_back(y);
	if((++cnt[to[x]])>1){ok=0;return ;}
	for(int i=la[x],v;i;i=edge[i].nx)
		if(deg[v=edge[i].to])
		{
			if(col[v] && col[v]!=c)continue;
			if(!col[v])dfs(v,-sum[to[x]]+y,c);
			return ;
		}
	ok=0;
}
int main()
{
	read(k),Mx=(1<<k)-1;
	for(int i=1,x;i<=k;++i)
	{
		read(n[i]);
		for(int j=1;j<=n[i];++j)read(x),vec[i].push_back(x),sum[i]+=x,num[i].push_back(++num_t),arr[num_t]=x,id[num_t]=num_t,to[num_t]=i;//printf("to[%d]=%d\n",num_t,i);
		res+=sum[i];
	}
	if(res%k)return 0&puts("No");
	sort(id+1,id+num_t+1,cmp);
	for(int i=1,x;i<=k;++i)
	{
		sum[i]-=res/k;
		for(int j=0;j<n[i];++j)
			if(x=binary_search(-sum[i]+vec[i][j]))
				add_edge(num[i][j],id[x]);
	}
	Topo();
	for(int i=1;i<=k;++i)
	{
		ok=0;
		for(int j=0;j<n[i];++j)ok|=deg[num[i][j]];
		if(!ok)return 0&puts("No");
	}
	for(int i=1,x;i<=k;++i)
		for(int j=0;j<n[i];++j)
			if(deg[num[i][j]] && !col[num[i][j]])
			{
				t=0,ok=1,memset(cnt,0,sizeof(cnt)),v1.clear(),v2.clear(),dfs(num[i][j],vec[i][j],++col_t);
				if(!g[t] && ok)g[t]=col_t,vnum[t]=v1,vvec[t]=v2;
			}
	f[0]=1;
	for(int i=0,t;i<=Mx;++i)
		if(g[i])
		{
			t=(Mx^i);
			for(int j=t;;j=(j-1)&t)
			{
				if(f[j] && !f[j|i])f[j|i]=1,from[j|i]=i;
				if(!j)break;
			}
		}
	if(!f[Mx])return 0&puts("No");
	puts("Yes");
	while(Mx)
	{
		for(int i=0,x;i<vnum[from[Mx]].size();++i)
		{
			for(int j=la[vnum[from[Mx]][i]];j;j=edge[j].nx)
				if(deg[x=edge[j].to])
					break;
			ans1[to[vnum[from[Mx]][i]]]=vvec[from[Mx]][i],ans2[to[x]]=to[vnum[from[Mx]][i]];
		}
		Mx^=from[Mx];
	}
	for(int i=1;i<=k;++i)printf("%d %d\n",ans1[i],ans2[i]);
	return 0;
}