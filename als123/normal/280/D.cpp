#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=100005;
int n;
int a[N];
struct qq
{
	int lmn,lmx,lmnp,lmxp;
	int rmn,rmx,rmnp,rmxp;
	int mx,mxl,mxr;
	int mn,mnl,mnr;
	int c;
	int rev;
	qq () {};
	qq (int x,int id)
	{
		c=mx=mn=rmn=rmx=lmn=lmx=x;
		mxl=mxr=mnl=mnr=lmnp=lmxp=rmnp=rmxp=id;
		rev=0;
	}
};
qq operator + (qq l,qq r)
{
	qq c;
	c.c=l.c+r.c;
	if (l.lmx>l.c+r.lmx)	{c.lmx=l.lmx;c.lmxp=l.lmxp;}
	else	{c.lmx=l.c+r.lmx;c.lmxp=r.lmxp;}
	
	if (r.rmx>r.c+l.rmx)	{c.rmx=r.rmx;c.rmxp=r.rmxp;}
	else	{c.rmx=r.c+l.rmx;c.rmxp=l.rmxp;}
	
	if (l.lmn<l.c+r.lmn)	{c.lmn=l.lmn;c.lmnp=l.lmnp;}
	else 	{c.lmn=l.c+r.lmn;c.lmnp=r.lmnp;}
	
	if (r.rmn<r.c+l.rmn)	{c.rmn=r.rmn;c.rmnp=r.rmnp;}
	else	{c.rmn=r.c+l.rmn;c.rmnp=l.rmnp;}
	
	if (l.mx>r.mx)	{c.mx=l.mx;c.mxl=l.mxl;c.mxr=l.mxr;}
	else	{c.mx=r.mx;c.mxl=r.mxl;c.mxr=r.mxr;}
	if (l.rmx+r.lmx>c.mx)	{c.mx=l.rmx+r.lmx;c.mxl=l.rmxp;c.mxr=r.lmxp;}
	
	if (l.mn<r.mn)	{c.mn=l.mn;c.mnl=l.mnl;c.mnr=l.mnr;}
	else	{c.mn=r.mn;c.mnl=r.mnl;c.mnr=r.mnr;}
	if (l.rmn+r.lmn<c.mn)	{c.mn=l.rmn+r.lmn;c.mnl=l.rmnp;c.mnr=r.lmnp;}
	
	c.rev=false;
	
	return c;
}
struct qt
{
	int l,r;
	int s1,s2;
	qq c;
}tr[N*2];int num=0;
void update (int now)
{
	int s1=tr[now].s1,s2=tr[now].s2;
	tr[now].c=tr[s1].c+tr[s2].c;
}
void bt (int l,int r)
{
	//printf("%d %d\n",l,r);
	int now=++num;
	tr[now].l=l;tr[now].r=r;
	if (l==r)	
	{
		tr[now].c=qq(a[l],l);
		//printf("YES:%d\n",tr[now].c.c);
		return ;
	}
	int mid=(tr[now].l+tr[now].r)>>1;
	tr[now].s1=num+1;bt(l,mid);
	tr[now].s2=num+1;bt(mid+1,r);
	update(now);
	//printf("%d %d %d\n",l,r,tr[now].c.c);
}
queue<pair<int,int> >q;
qq get (int now,int l,int r)
{
	if (tr[now].l==l&tr[now].r==r)	return tr[now].c;
	int mid=(tr[now].l+tr[now].r)>>1;
	int s1=tr[now].s1,s2=tr[now].s2;
	if (r<=mid) return get(s1,l,r);
	else if (l>mid) return get(s2,l,r);
	else return get(s1,l,mid)+get(s2,mid+1,r);
}
void Rev (int now)
{
	qq &x=tr[now].c;
	swap(x.mx,x.mn);swap(x.mxl,x.mnl);swap(x.mxr,x.mnr);
	swap(x.lmx,x.lmn);swap(x.lmxp,x.lmnp);
	swap(x.rmx,x.rmn);swap(x.rmxp,x.rmnp);
	
	x.rev^=1;
	
	x.mn*=-1;
	x.mx*=-1;
	x.lmn*=-1;
	x.lmx*=-1;
	x.rmn*=-1;
	x.rmx*=-1;
	x.c*=-1;
}
void Push_down (int now)
{
	if (tr[now].c.rev)
	{
		int s1=tr[now].s1,s2=tr[now].s2;
		Rev(s1);Rev(s2);
		tr[now].c.rev=false;
	}
}
void rev (int now,int l,int r)
{
	if (tr[now].l==l&&tr[now].r==r)	
	{
		//if (l==r) printf("YES:%d\n",tr[now].c.mn);
		Rev(now);
		return ;
	}
	Push_down (now);
	int mid=(tr[now].l+tr[now].r)>>1;
	int s1=tr[now].s1,s2=tr[now].s2;
	if (r<=mid) rev(s1,l,r);
	else if (l>mid) rev(s2,l,r);
	else rev(s1,l,mid),rev(s2,mid+1,r);
	update(now);
}
void change (int now,int x,int xx)
{
	if (tr[now].l==tr[now].r)
	{
		tr[now].c=qq(xx,x);
		return ;
	}
	Push_down (now);
	int mid=(tr[now].l+tr[now].r)>>1;
	int s1=tr[now].s1,s2=tr[now].s2;
	if (x<=mid) change(s1,x,xx);
	else change(s2,x,xx);
	update(now);
}
int main()
{
	//freopen("3638.in","r",stdin);
	//freopen("3638.out","w",stdout);
	scanf("%d",&n);
	for (int u=1;u<=n;u++)	scanf("%d",&a[u]);
	bt(1,n);
//	printf("%d\n",tr[1].c.mx);
	int m;
	scanf("%d",&m);
	while (m--)
	{
		int op;
		scanf("%d",&op);
		if (op==1)
		{
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			int ans=0;
			while (k--)
			{
				qq c=get(1,l,r);
				if (c.mx<=0) break;
				ans=ans+c.mx;
				//printf("%d %d %d\n",c.mx,c.mxl,c.mxr);
				q.push(make_pair(c.mxl,c.mxr));
				rev(1,c.mxl,c.mxr);
			}
			while (!q.empty())
			{
				int x=q.front().first,y=q.front().second;q.pop();
				rev(1,x,y);
			}
			printf("%d\n",ans);
		}
		else
		{
			int id,x;
			scanf("%d%d",&id,&x);
			change(1,id,x);
		}
	}
	return 0;
}