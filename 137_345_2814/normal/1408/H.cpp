#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
#define N 500500
int t,n,v[N],s1[N],ls[N],as,s2[N],s3[N],ct,tp;
struct edge{int l,r,mn,lz;}e[N*4];
void pushup(int x){e[x].mn=min(e[x<<1].mn,e[x<<1|1].mn)+e[x].lz;}
void build(int x,int l,int r)
{
	e[x].l=l;e[x].r=r;e[x].mn=e[x].lz=0;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
}
void modify(int x,int l,int r,int v)
{
	if(e[x].l==l&&e[x].r==r){e[x].mn+=v;e[x].lz+=v;return;}
	int mid=(e[x].l+e[x].r)>>1;
	if(mid>=r)modify(x<<1,l,r,v);
	else if(mid<l)modify(x<<1|1,l,r,v);
	else modify(x<<1,l,mid,v),modify(x<<1|1,mid+1,r,v);
	pushup(x);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);as=ct=tp=0;
		for(int i=1;i<=n;i++)scanf("%d",&v[i]),ct+=!v[i];
		as=ct/2;
		for(int i=1;i<=n;i++)s3[i]=s2[i]=ls[i]=0;
		int tp=as;
		for(int i=1;i<=n&&tp;i++)if(!v[i])s3[as-tp+1]=i,tp--;
		tp=as;
		for(int i=n;i>=1&&tp;i--)if(!v[i])s2[i]=tp,tp--;
		build(1,1,n);
		for(int i=1;i<=n;i++)
		if(v[i])modify(1,ls[v[i]]+1,i,1),ls[v[i]]=i;
		else if(s2[i])
		{
			modify(1,1,s3[s2[i]-tp],-1);
			if(e[1].mn<0)modify(1,1,s3[s2[i]-tp],1),tp++;
		}
		printf("%d\n",as-tp);
	}
}