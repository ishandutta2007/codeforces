#include<cstdio>
#include<cstring>
#define GC getchar()
inline void read(int&n)
{int x=0,f=1;char ch=GC;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=GC;}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=GC;n=x*f;}
const int N=2e5+5;
struct LB
{
	int a[32],cnt;
	LB(){memset(a,0,sizeof(a));cnt=0;}
	inline void insert(int x)
	{
		for(int i=31;i>=0;i--)if(x&(1<<i))
		{
			if(!a[i]){a[i]=x;cnt++;break;}
			x^=a[i];
		}
	}
};
inline LB merge(LB a,LB b)
{
	LB c=a;
	for(int i=0;i<32;i++)if(b.a[i])c.insert(b.a[i]);
	return c;
}
struct T{LB a;}t[N<<2];
int n,m,a[N],b[N];
inline void pushup(int u){t[u].a=merge(t[u<<1].a,t[u<<1|1].a);}
void build(int u,int l,int r)
{
	if(l==r){t[u].a.insert(a[l]);return;}
	int mid=(l+r)>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);
}
void modify(int u,int l,int r,int pos,int val)
{
	if(l==r){LB tmp;tmp.insert(a[l]^=val);t[u].a=tmp;return;}
	int mid=(l+r)>>1;
	if(pos<=mid)modify(u<<1,l,mid,pos,val);
	else modify(u<<1|1,mid+1,r,pos,val);
	pushup(u);
}
LB query(int u,int l,int r,int left,int right)
{
	if(left<=l&&right>=r)return t[u].a;
	int mid=(l+r)>>1;
	if(right<=mid)return query(u<<1,l,mid,left,right);
	if(left>mid)return query(u<<1|1,mid+1,r,left,right);
	return merge(query(u<<1,l,mid,left,right),query(u<<1|1,mid+1,r,left,right));
}
struct BIT
{
	int t[N];
	inline int lowbit(int x){return x&-x;}
	inline void add(int x,int v){while(x<=n)t[x]^=v,x+=lowbit(x);}
	inline void add(int l,int r,int v){add(l,v);if(r<n)add(r+1,v);}
	inline int query(int x){int tmp=0;while(x)tmp^=t[x],x-=lowbit(x);return tmp;}
}bit;
int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)read(b[i]),bit.add(i,i,b[i]),a[i]=b[i]^b[i-1];
	build(1,1,n);
	while(m--)
	{
		int k,l,r,x;
		read(k),read(l),read(r);
		if(k==1)
		{
			read(x);
			modify(1,1,n,l,x);
			if(r<n)modify(1,1,n,r+1,x);
			bit.add(l,r,x);
		}
		if(k==2)
		{
			LB tmp;
			if(l<r)tmp=query(1,1,n,l+1,r);
			tmp.insert(bit.query(l));
			printf("%d\n",1<<tmp.cnt);
		}
	}
	return 0;
}