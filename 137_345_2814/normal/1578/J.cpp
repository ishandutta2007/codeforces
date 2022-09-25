#include<cstdio>
#include<algorithm>
using namespace std;
#define N 200500
#define M 18000500
#define S 13000600
#define ll long long
int n,a,l,r,k;
ll ls;
//las
struct segt{
	struct node{int l,r,mn;}e[N*4];
	void pushup(int x){e[x].mn=min(e[x<<1].mn,e[x<<1|1].mn);}
	void build(int x,int l,int r)
	{
		e[x].l=l;e[x].r=r;
		if(l==r)return;
		int mid=(l+r)>>1;
		build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	}
	void modify(int x,int s,int v)
	{
		if(e[x].l==e[x].r){e[x].mn=v;return;}
		int mid=(e[x].l+e[x].r)>>1;
		if(mid>=s)modify(x<<1,s,v);
		else modify(x<<1|1,s,v);
		pushup(x);
	}
	int query(int x,int l,int r,int v)
	{
		if(e[x].mn>v||l>r)return -1;
		if(e[x].l==e[x].r)return e[x].l;
		int mid=(e[x].l+e[x].r)>>1;
		if(mid>=r)return query(x<<1,l,r,v);
		else if(mid<l)return query(x<<1|1,l,r,v);
		else
		{
			int s1=query(x<<1,l,mid,v);
			if(s1==-1)s1=query(x<<1|1,mid+1,r,v);
			return s1;
		}
	}
	int querymn(int x,int l,int r)
	{
		if(l>r)return n+1;
		if(e[x].l==l&&e[x].r==r)return e[x].mn;
		int mid=(e[x].l+e[x].r)>>1;
		if(mid>=r)return querymn(x<<1,l,r);
		else if(mid<l)return querymn(x<<1|1,l,r);
		else return min(querymn(x<<1,l,mid),querymn(x<<1|1,mid+1,r));
	}
}tr;
//pretree 1
struct ptree{
	int ch[S][2],rt[N],vl[S],ct,ls;
	int modify(int x,int l,int r,int s,int v)
	{
		int st=++ct;
		ch[st][0]=ch[x][0];ch[st][1]=ch[x][1];
		if(l==r){vl[st]=v;return st;}
		int mid=(l+r)>>1;
		if(mid>=s)ch[st][0]=modify(ch[x][0],l,mid,s,v);
		else ch[st][1]=modify(ch[x][1],mid+1,r,s,v);
		return st;
	}
	void modify1(int x,int y){ls=modify(ls,0,n,x,y);}
	void modify2(int t){rt[t]=ls;}
	int query(int x,int l,int r,int s)
	{
		if(l==r)return vl[x];
		int mid=(l+r)>>1;
		if(s<=mid)return query(ch[x][0],l,mid,s);
		else return query(ch[x][1],mid+1,r,s);
	}
}pt;
//pretree for ans
struct sth{ll a,b;};
sth operator +(sth a,sth b){return (sth){a.a+b.a,a.b+b.b};}
sth operator *(sth a,int b){return (sth){a.a*b,a.b*b};}
struct ptree2{
	int ch[M][2],rt[N*4],ct,c1;
	sth su[M],lz[M];
	int modify(int x,int l,int r,int l1,int r1,sth tp)
	{
		if(l1<l)l1=l;if(r1>r)r1=r;
		if(l1>r1)return x;
		int st=++ct;
		ch[st][0]=ch[x][0];ch[st][1]=ch[x][1];
		su[st]=su[x];lz[st]=lz[x];
		if(l==l1&&r==r1){lz[st]=lz[st]+tp;return st;}
		su[st]=su[st]+tp*(r1-l1+1);
		int mid=(l+r)>>1;
		ch[st][0]=modify(ch[x][0],l,mid,l1,r1,tp);
		ch[st][1]=modify(ch[x][1],mid+1,r,l1,r1,tp);
		return st;
	}
	void modify2(int ls,int l,int r,sth tp){rt[++c1]=modify(rt[ls],1,n,l,r,tp);}
	sth query(int x,int l,int r,int l1,int r1,sth tp)
	{
		if(l1<l)l1=l;if(r1>r)r1=r;
		if(l1>r1)return (sth){0,0};
		tp=tp+lz[x];
		if(l==l1&&r==r1)return su[x]+tp*(r-l+1);
		int mid=(l+r)>>1;
		return query(ch[x][0],l,mid,l1,r1,tp)+query(ch[x][1],mid+1,r,l1,r1,tp);
	}
}pt2;
void modify(int l,int r,int x,int y,int ti)
{
	if(l>r)return;
	if(x!=-1)
	{
		int ls=pt.query(pt.ls,0,n,x);
		pt2.modify2(ls,l,r,(sth){-1,ti});
		pt.modify1(x,pt2.c1);
	}
	int ls=pt.query(pt.ls,0,n,y);
	pt2.modify2(ls,l,r,(sth){1,-ti});
	pt.modify1(y,pt2.c1);
}
void modify1(int x,int y,int ti)
{
	modify(ti,ti,-1,0,ti);
	if(tr.query(1,0,x-1,tr.querymn(1,x,x))!=-1){tr.modify(1,x,y);return;}
	int nw=x,vl=tr.querymn(1,x,x),ls=min(y,tr.querymn(1,0,x-1)),nt=tr.query(1,x+1,n,vl);
	tr.modify(1,x,y);
	while(nw<nt)
	{
		int t1=tr.query(1,nw,n,ls-1),v1=tr.querymn(1,t1,t1);
		modify(vl+1,ls,nw,t1,ti);
		nw=t1;ls=v1;
	}
}
ll query(int l,int r,int k)
{
	int ls=pt.query(pt.rt[r],0,n,k);
	sth as=pt2.query(pt2.rt[ls],1,n,l,r,(sth){0,0});
	return as.b+as.a*(r+1);
}
int main()
{
	scanf("%d",&n);n++;
	tr.build(1,0,n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d%d",&a,&l,&r,&k);
		a=(a+ls)%n;k=(k+ls)%n;
		l=(l+ls)%i+1;r=(r+ls)%i+1;
		if(l>r)l^=r^=l^=r;
		modify1(a,i,i);pt.modify2(i);
		printf("%lld\n",ls=query(l,r,k));
	}
}