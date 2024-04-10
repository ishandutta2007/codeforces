#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<set>
#include<map>
using namespace std;
const int N=300005;
int n,C;
struct qq
{
	int l,r,c;
}s[N];
struct qt
{
	int x,v,id;
	qt () {};
	qt (int _x,int _v,int _id)	{x=_x;v=_v;id=_id;}
}a[N*2];
struct qr
{
	int id,cost;
}g[N];
bool cmp (qq x,qq y)	{return x.c<y.c;}
bool cmp1 (qt x,qt y)	{return x.x<y.x;}
bool cmp2 (qr x,qr y)	{return x.cost<y.cost;}
int ans[N];
int m;
set<int>:: iterator it;
set<int> S;
map<int,int> cross[N];
int opt[N];
int single[N];
void update (int &x,int y)	{x=x>y?x:y;}
int mymax (int x,int y)	{return x>y?x:y;}
int seg[N*4];
void change (int now,int l,int r,int x)
{
	if (l==r)	{seg[now]=single[l];return ;}
	int mid=(l+r)>>1;
	int s1=now<<1,s2=s1|1;
	if (x<=mid) change(s1,l,mid,x);
	else change(s2,mid+1,r,x);
	seg[now]=mymax(seg[s1],seg[s2]);
}
int lx,rx;
int calc (int x,int y)
{
	if (x>y) swap(x,y);
	return single[x]+single[y]+cross[x][y];
}
int search (int now,int l,int r)
{
	if (l==r) return l;
	int mid=(l+r)>>1;
	int s1=now<<1,s2=s1|1;
	if (seg[s1]>seg[s2]) return search(s1,l,mid);
	else return search(s2,mid+1,r);
}
int get (int now,int l,int r)
{
	//printf("%d %d %d %d\n",l,r,now,seg[now]);
	if (rx<l||lx>r) return 0;
	if (lx<=l&&r<=rx)	return search(now,l,r);
	int mid=(l+r)>>1;
	int s1=now<<1,s2=s1|1;
	int t1=get(s1,l,mid),t2=get(s2,mid+1,r);
	return single[t1]>single[t2]?t1:t2;
}
int tot;
void solve ()
{
	int now,mx;//  
	now=mx=0;
	int lst=0,sum=0;
	int pos=0;
	for (int u=1;u<=tot;u++)
	{
		int x,y;
		int o=a[u].x-lst;lst=a[u].x;
		//printf("now:%d mx:%d\n",now,mx);
		if (sum==0)	now=now+o;
		else if (sum==1)
		{
			it=S.begin();
			x=(*it);
			single[x]+=o;
			//printf("lalal:%d %d\n",x,single[x]);
			change(1,1,n,x);
			opt[x]+=o;
			int lalal=C-s[x].c;
			if (lalal>=0)
			{
				int xx=single[x];
				if (lalal>=s[1].c)
				{
					int l=1,r=n;
					while (l<=r)
					{
						int mid=(l+r)>>1;
						if (s[mid].c<=lalal) l=mid+1;
						else r=mid-1;
					}
				//	printf("%d %d %d\n",xx,l,r);
					lx=1;rx=l-1;
					if (x==rx) rx--;
					//printf("%d %d %d\n",lx,rx,x);
					if (x<rx)
					{
						lx=x+1;
						if (lx<=rx) update(xx,calc(x,get(1,1,n)));
						lx=1;rx=x-1;
					}
					//printf("OZY:%d %d %d\n",lx,rx,get(1,1,n));
					if (lx<=rx) update(xx,calc(x,get(1,1,n)));
				}
				update(opt[x],xx);
				update(mx,opt[x]);
			}
		//	printf("A\n");
		}
		else if (sum==2)
		{
			it=S.begin();x=(*it);it++;y=(*it);
			cross[x][y]+=o;
			if (s[x].c+s[y].c<=C)
			{
				update(opt[x],calc(x,y));
				update(opt[y],calc(x,y));
				update(mx,opt[x]);
				update(mx,opt[y]);
			}
		}
		while (pos<m&&mx+now>=g[pos+1].cost)
		{
			pos++;
			ans[g[pos].id]=lst-(mx+now-g[pos].cost);
		}
		if (a[u].v==1) S.insert(a[u].id),sum++;
		else S.erase(a[u].id),sum--;
	}
}
int main()
{
	scanf("%d%d",&n,&C);
	for (int u=1;u<=n;u++)	scanf("%d%d%d",&s[u].l,&s[u].r,&s[u].c);
	sort(s+1,s+1+n,cmp);
	tot=0;
	for (int u=1;u<=n;u++)
	{
		a[++tot]=qt(s[u].l,1,u);
		a[++tot]=qt(s[u].r,-1,u);
	}
	a[++tot]=qt(2e9,1,n+1);
	sort(a+1,a+1+tot,cmp1);
	scanf("%d",&m);
	for (int u=1;u<=m;u++)
	{
		g[u].id=u;
		scanf("%d",&g[u].cost);
	}
	sort(g+1,g+1+m,cmp2);
	solve();
	for (int u=1;u<=m;u++) printf("%d\n",ans[u]);
	return 0;
}