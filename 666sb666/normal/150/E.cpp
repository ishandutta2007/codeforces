#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define GC getchar()
#define PC putchar
inline void read(int&n)
{int x=0,f=1;char ch=GC;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=GC;}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=GC;n=x*f;}
int outputarray[20];
inline void write(int k)
{int num=0;if(k<0)PC('-'),k=-k;do{outputarray[++num]=k%10,k/=10;}while(k);while(num)PC(outputarray[num--]+'0');puts("");}
const int N=1e5+5;
struct E{int to,v,have,next;}edge[N<<1];
int n,l,r,head[N],tot=-1,mxdep[N],Ans=-1;
pair<int,int>f[N],g[N],answer;
inline bool cmp(int a,int b){return mxdep[edge[a].to]<mxdep[edge[b].to];}
int getsize(int u,int f)
{
	int tmp=1;
	for(int i=head[u];i!=-1;i=edge[i].next)if(edge[i].have&&edge[i].to!=f)tmp+=getsize(edge[i].to,u);
	return tmp;
}
int getcenter(int u,int f,int&x,int siz)
{
	int s=1,flag=1;
	for(int i=head[u];i!=-1;i=edge[i].next)if(edge[i].have&&edge[i].to!=f)
	{
		int tmp=getcenter(edge[i].to,u,x,siz);
		if((tmp<<1)>siz)flag=0;
		s+=tmp;
	}
	if(((siz-s)<<1)>siz)flag=0;
	if(flag)x=u;
	return s;
}
void getdep(int u,int f)
{
	mxdep[u]=1;
	for(int i=head[u];i!=-1;i=edge[i].next)if(edge[i].have&&edge[i].to!=f)getdep(edge[i].to,u),mxdep[u]=max(mxdep[u],mxdep[edge[i].to]+1);
}
void dfs(int u,int f,int d,int dep,int mid)
{
	g[dep]=max(g[dep],make_pair(d,u));
	for(int i=head[u];i!=-1;i=edge[i].next)if(edge[i].have&&edge[i].to!=f)dfs(edge[i].to,u,d+(edge[i].v>=mid?1:-1),dep+1,mid);
}
struct QUEUE
{
	int id[N],H,T;
	pair<int,int>x[N];
	inline void init(){H=1;T=0;}
	inline void push(pair<int,int>p,int q){while(H<=T&&x[T]<p)T--;T++;x[T]=p;id[T]=q;}
	inline pair<int,int> top(){if(H<=T)return x[H];return make_pair(-1e9,0);}
	inline void pop(int p){if(H<=T&&id[H]==p)H++;}
}Q;
void divide(int u)
{
	int x;
	getcenter(u,0,x,getsize(u,0));
	vector<int>son;son.clear();
	for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].have)edge[i].have=edge[i^1].have=0,getdep(edge[i].to,x),son.push_back(i);
	sort(son.begin(),son.end(),cmp);
	int depth=0;for(int i=0;i<son.size();i++)depth=max(depth,mxdep[edge[son[i]].to]);
	int L=0,R=1e9;
	pair<int,int>ans=make_pair(-1,-1);
	while(L<=R)
	{
		int mid=(L+R+1)>>1;int flag=0,ret=0;if(L==R)ret=1;
		for(int i=1;i<=depth;i++)f[i]=make_pair(-1e9,0);
		for(int i=0;i<son.size();i++)
		{
			for(int j=1;j<=mxdep[edge[son[i]].to];j++)g[j]=make_pair(-1e9,0);
			dfs(edge[son[i]].to,x,edge[son[i]].v>=mid?1:-1,1,mid);
			int lim=min(r,mxdep[edge[son[i]].to]);
			for(int j=l;j<=lim;j++)if(g[j].first>=0){ans=make_pair(x,g[j].second);flag=true;break;}
			if(flag)break;
			Q.init();
			for(int j=lim;j>=l;j--)Q.push(f[j],j);
			for(int j=1;j<=mxdep[edge[son[i]].to];j++)
			{
				if(j>l)break;
				Q.pop(r+1-j);
				if(l-j<=depth)Q.push(f[l-j],l-j);
				pair<int,int>tmp=Q.top();
				if(tmp.first+g[j].first>=0){ans=make_pair(tmp.second,g[j].second);flag=true;break;}
			}
			if(flag)break;
			for(int j=1;j<=mxdep[edge[son[i]].to];j++)f[j]=max(f[j],g[j]);
		}
		if(flag)L=mid;else R=mid-1;
		if(ret)break;
	}
	if(ans.first>0&&L>Ans)Ans=L,answer=ans;
	for(int i=0;i<son.size();i++)divide(edge[son[i]].to);
}
int main()
{
	memset(head,-1,sizeof(head));
	read(n),read(l),read(r);
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		read(x),read(y),read(z);
		edge[++tot]=(E){y,z,1,head[x]};head[x]=tot;
		edge[++tot]=(E){x,z,1,head[y]};head[y]=tot;
	}
	divide(1);
	printf("%d %d\n",answer.first,answer.second);
	return 0;
}