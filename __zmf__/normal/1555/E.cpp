#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
#define int long long
int lazy[N<<2],ans[N<<2],a[N],n,m,k,L,R; 
inline int read()
{
	int sum=0,naga=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')naga=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')sum=sum*10+ch-'0',ch=getchar();
	return sum*naga;
}
inline void write(int X)
{
	if(X<0)putchar('-');
	if(X>9)write(X/10);
	putchar(X%10+'0');
}
inline int lc(int p){return p<<1;}
inline int rc(int p){return p<<1|1;}
void push_up(int x)
{
	ans[x]=min(ans[rc(x)],ans[lc(x)]); 
}
void build(int l,int r,int p)
{
	lazy[p]=0;
	if(l==r){ans[p]=0;return;}
	int mid=(l+r)>>1;
	build(l,mid,lc(p));
	build(mid+1,r,rc(p));
	push_up(p); 
}
void push_down(int l,int r,int p)
{
	int mid=(l+r)>>1;
	if(lazy[p]==0) return;
	lazy[lc(p)]+=lazy[p];
	lazy[rc(p)]+=lazy[p];
	ans[lc(p)]+=lazy[p];
	ans[rc(p)]+=lazy[p];
	lazy[p]=0;
}
void update(int l,int r,int p)
{
	if(L<=l&&r<=R)
	{
		lazy[p]+=k;
		ans[p]+=k;
		return ;
	}
	push_down(l,r,p);
	int mid=(l+r)>>1;
	if(L<=mid)update(l,mid,lc(p));
	if(R>mid)update(mid+1,r,rc(p));
	push_up(p);
}
int query(int l,int r,int p)
{
	int answer=1e9;
	if(L<=l&&r<=R)
		return ans[p];
	int mid=(l+r)>>1;
	push_down(l,r,p);
	if(L<=mid)answer=min(answer,query(l,mid,lc(p)));
	//if(L==1&&R==4)cout<<l<<" "<<r<<" "<<p<<" "<<answer<<endl;
	if(R>mid)answer=min(answer,query(mid+1,r,rc(p)));
	//if(L==1&&R==4)cout<<l<<" "<<r<<" "<<p<<" "<<answer<<endl;
	push_up(p);
	return answer;
}
struct point
{
	int lx, rx, wx;
}x[N*4];
bool cmp(point xxx,point yyy)
{
	return xxx.wx<yyy.wx;
}
signed main()
{
	m=read(),n=read();
	int siz=n-1;
	for(int i=1;i<=n;i++)a[i]=0;
	build(1,siz,1);
	for(int i=1;i<=m;i++)x[i].lx=read(),x[i].rx=read()-1,x[i].wx=read();
	sort(x+1,x+m+1,cmp);
	int lp=1,rp=0,res=1e9;
	L=1,R=siz;
	while(rp<m&&ans[1]==0)
	{
		++rp;
		L=x[rp].lx,R=x[rp].rx,k=1;
		update(1,siz,1);
	}
	//return 0;
	res=x[rp].wx-x[lp].wx;
	while(lp<m)
	{
		L=x[lp].lx,R=x[lp].rx,k=-1;
		lp++;
		update(1,siz,1);
		while(rp<m&&ans[1]==0)
		{
			++rp;
			L=x[rp].lx,R=x[rp].rx,k=1;
			if(rp>m)break;
			update(1,siz,1);
		}
		if(ans[1])res=min(res,x[rp].wx-x[lp].wx);
		//cout<<l<<" "<<r<<endl;
	}
	cout<<res<<endl; 
	return 0;
}