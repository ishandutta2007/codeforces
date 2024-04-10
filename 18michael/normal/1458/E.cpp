#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,tot,sum=0,ok,nx,ny,y_t=0;
int ans[100002],arr[200002]={};
struct aaa
{
	int x,y,y1,opt;
}pos[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(aaa a,aaa b)
{
	return a.y<b.y? 1:0;
}
inline bool cmp1(aaa a,aaa b)
{
	return (a.x==b.x)? ((a.y==b.y)? (a.opt<b.opt):(a.y<b.y)):(a.x<b.x);
}
inline int lowbit(int x)
{
	return x&(-x);
}
inline void modify(int x)
{
	while(x<=y_t)++arr[x],x+=lowbit(x);
}
inline int query(int x)
{
	int res=0;
	while(x)res+=arr[x],x-=lowbit(x);
	return res;
}
int main()
{
	read(n),read(m),tot=n+m;
	for(int i=1;i<=n;++i)read(pos[i].x),read(pos[i].y),pos[i].opt=0;
	for(int i=1;i<=m;++i)read(pos[i+n].x),read(pos[i+n].y),pos[i+n].opt=i;
	sort(pos+1,pos+tot+1,cmp);
	for(int i=1,j;i<=tot;i=j)for(j=i,++y_t;j<=tot && pos[j].y==pos[i].y;++j)pos[j].y1=y_t;
	sort(pos+1,pos+tot+1,cmp1);
	for(int i=1,j;i<=tot;i=j)
	{
		ok=0;for(j=i+1;j<=tot && pos[j].x==pos[i].x;++j);
		for(int k=i,k1=0;k<j;++k)
		{
			if(pos[k].opt)
			{
				if(k1 && pos[k].x==pos[k1].x && pos[k].y==pos[k1].y){ans[pos[k].opt]=1;continue;}
				if(ok || (query(pos[k].y1)-query(pos[k].y1-1))){ans[pos[k].opt]=0;continue;}
				ans[pos[k].opt]=((pos[k].x-sum)==(pos[k].y-query(pos[k].y1)));
			}
			else
			{
				k1=k,nx=pos[k].x-sum,ny=pos[k].y-query(pos[k].y1);
				if(nx<ny)
				{
					if(query(pos[k].y1)-query(pos[k].y1-1))continue;
					modify(pos[k].y1);
				}
				else if(nx>ny)sum+=(!ok),ok=1;
			}
		}
	}
	for(int i=1;i<=m;++i)puts(ans[i]? "LOSE":"WIN");
	return 0;
}