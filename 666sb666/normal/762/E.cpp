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
const int N=1e5+5,M=1e4+5,INF=1e9;
int n,k,tot,x[N],r[N],f[N];
long long ans;
struct S{int x,r,f;}s[N];
inline bool cmp(S a,S b){return a.x<b.x;}
struct T{int l,r,v;}t[N*40];
struct CMT
{
	vector<int>root;
	void insert(int&x,int y,int l,int r,int v)
	{
		x=++tot;t[x].l=t[y].l;t[x].r=t[y].r;t[x].v=t[y].v+1;if(l==r)return;
		int mid=(l+r)/2;if(r-l==1)mid=l;if(v<=mid)insert(t[x].l,t[y].l,l,mid,v);else insert(t[x].r,t[y].r,mid+1,r,v);
	}
	inline void add(int x){int tmp=0,last=0;if(root.size())last=root[root.size()-1];insert(tmp,last,-INF,INF,x);root.push_back(tmp);}
	int query(int x,int y,int l,int r,int v)
	{
		if(r<=v)return t[y].v-t[x].v;int mid=(l+r)/2;if(r-l==1)mid=l;
		if(v<=mid)return query(t[x].l,t[y].l,l,mid,v);else return query(t[x].l,t[y].l,l,mid,v)+query(t[x].r,t[y].r,mid+1,r,v);
	}
	inline int query(int x,int y,int z){int a=0;if(x)a=root[x-1];return query(a,root[y],-INF,INF,z);}
}tree[M];
vector<pair<int,int> >vc[M];
inline int binary1(int x,int y)
{
	if(!vc[x].size())return INF;
	if(vc[x][vc[x].size()-1].second<=y)return INF;
	int l=0,r=vc[x].size()-1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(vc[x][mid].second<=y)l=mid+1;
		else r=mid;
	}
	return r;
}
inline int binary2(int x,int y)
{
	if(!vc[x].size())return -INF;
	if(vc[x][0].first>y)return -INF;
	int l=0,r=vc[x].size()-1;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(vc[x][mid].first<=y)l=mid;
		else r=mid-1;
	}
	return l;
}
inline void work(int X,int id)
{
	if(X<0||X>10000)return;
	int L=binary1(X,id),R=binary2(X,x[id]+r[id]);
	if(L>R)return;
	ans+=tree[X].query(L,R,x[id]);
}
int main()
{
	read(n),read(k);
	for(int i=1;i<=n;i++)read(s[i].x),read(s[i].r),read(s[i].f);
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=n;i++)x[i]=s[i].x,r[i]=s[i].r,f[i]=s[i].f,tree[f[i]].add(x[i]-r[i]),vc[f[i]].push_back(make_pair(x[i],i));
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)if(!j)work(f[i],i);else work(f[i]+j,i),work(f[i]-j,i);
	printf("%lld\n",ans);
	return 0;
}