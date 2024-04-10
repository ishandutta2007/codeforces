#include<cstdio>
#include<map>
using namespace std;
const int N=2e5+5;
int n,k,d,a[N],b[N],c[N],lst[N],pre[N];
map<int,int>mp;
inline void work()
{
	int now=1,L=1,R=1;
	while(now<=n)
	{
		int tmp=now;
		while(now<n&&a[now]==a[now+1])now++;
		if(now-tmp+1>R-L+1)L=tmp,R=now;
		now++;
	}
	printf("%d %d\n",L,R);
}
struct T{long long sum,lazy,mn;}t[N<<2];
inline void pushdown(int u,int l,int r)
{
	if(t[u].lazy)
	{
		int mid=(l+r)>>1;
		t[u<<1].lazy+=t[u].lazy;t[u<<1].mn+=t[u].lazy;t[u<<1].sum+=(long long)t[u].lazy*(mid-l+1);
		t[u<<1|1].lazy+=t[u].lazy;t[u<<1|1].mn+=t[u].lazy;t[u<<1|1].sum+=(long long)t[u].lazy*(r-mid);
		t[u].lazy=0;
	}
}
inline void pushup(int u){t[u].sum=t[u<<1].sum+t[u<<1|1].sum;t[u].mn=min(t[u<<1].mn,t[u<<1|1].mn);}
void add(int u,int l,int r,int left,int right,int v)
{
	if(left<=l&&right>=r){t[u].lazy+=v;t[u].mn+=v;t[u].sum+=(long long)v*(r-l+1);return;}
	int mid=(l+r)>>1;pushdown(u,l,r);
	if(left<=mid)add(u<<1,l,mid,left,right,v);
	if(right>mid)add(u<<1|1,mid+1,r,left,right,v);
	pushup(u);
}
int querymin(int u,int l,int r,int left,int right)
{
	if(left<=l&&right>=r)return t[u].mn;
	int mid=(l+r)>>1;pushdown(u,l,r);
	if(right<=mid)return querymin(u<<1,l,mid,left,right);
	if(left>mid)return querymin(u<<1|1,mid+1,r,left,right);
	return min(querymin(u<<1,l,mid,left,right),querymin(u<<1|1,mid+1,r,left,right));
}
int query(int u,int l,int r,int left,int right,int k)
{
	if(l==r)return l;
	int mid=(l+r)>>1;pushdown(u,l,r);
	if(right<=mid)return query(u<<1,l,mid,left,right,k);
	if(left>mid)return query(u<<1|1,mid+1,r,left,right,k);
	if(querymin(1,1,n,max(left,l),mid)<=k)return query(u<<1,l,mid,left,right,k);
	return query(u<<1|1,mid+1,r,left,right,k);
}
int ask(int u,int l,int r,int pos)
{
	if(l==r)return t[u].mn;
	int mid=(l+r)>>1;pushdown(u,l,r);
	if(pos<=mid)return ask(u<<1,l,mid,pos);
	else return ask(u<<1|1,mid+1,r,pos);
}
struct Q1
{
	int v[N],id[N],top;
	inline void push(int x,int y)
	{
		int now=y-1;
		while(top&&x>v[top])
		{
			if(top==1)add(1,1,n,1,now,x-v[top]);
			else add(1,1,n,id[top-1]+1,now,x-v[top]);
			now=id[top-1],top--;
		}
		top++;v[top]=x;id[top]=y;add(1,1,n,y,y,y+x);
	}
}q1;
struct Q2
{
	int v[N],id[N],top;
	inline void push(int x,int y)
	{
		int now=y-1;
		while(top&&x<v[top])
		{
			if(top==1)add(1,1,n,1,now,v[top]-x);
			else add(1,1,n,id[top-1]+1,now,v[top]-x);
			now=id[top-1],top--;
		}
		top++;v[top]=x;id[top]=y;add(1,1,n,y,y,-x);
	}
}q2;
int main()
{
	scanf("%d%d%d",&n,&k,&d);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(d==0)return work(),0;
	for(int i=1;i<=n;i++)a[i]+=1e9,b[i]=a[i]%d,c[i]=a[i]/d,lst[i]=mp[a[i]],mp[a[i]]=i;
	pre[1]=1;
	for(int i=2;i<=n;i++)pre[i]=(b[i]==b[i-1])?pre[i-1]:i;
	int L=1,R=1,now=0;
	for(int i=1;i<=n;i++)
	{
		q1.push(c[i],i);q2.push(c[i],i);
		now=max(max(now,lst[i]+1),pre[i]);
		int pos=query(1,1,n,now,i,k+i);
		//printf("%d\n",ask(1,1,n,3));
		//if(i==850)return printf("%d\n",pos),0;
		if(i-pos+1>R-L+1)L=pos,R=i;
	}
	printf("%d %d\n",L,R);
	return 0;
}