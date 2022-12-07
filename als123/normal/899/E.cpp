#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<set>
using namespace std;
const int N=200005;
typedef pair<int,pair<int,int> > P;
int n;
int A[N];
set<pair<int,pair<int,int> > >s;
struct qq
{
	int l,r;
	int s1,s2;
	int c;//
	P x;//
	P lazy;
	int lazy1;
}tr[N*2];int num;
P c[N];//
void bt (int l,int r)
{
	int a=++num;
	tr[a].l=l;tr[a].r=r;
	tr[a].lazy1=0;
	if (l==r)
	{
		tr[a].x=c[l];tr[a].c=A[l];
		return ;
	}
	int mid=(l+r)>>1;
	tr[a].s1=num+1;bt(l,mid);
	tr[a].s2=num+1;bt(mid+1,r);
}
P X;
int Y;
void update (int x)
{
	int s1=tr[x].s1,s2=tr[x].s2;
	if (tr[x].lazy1!=0)
	{
		tr[s1].c=tr[x].lazy1;tr[s1].x=tr[x].lazy;
		tr[s1].lazy1=tr[x].lazy1;tr[s1].lazy=tr[x].lazy;
		tr[s2].c=tr[x].lazy1;tr[s2].x=tr[x].lazy;
		tr[s2].lazy1=tr[x].lazy1;tr[s2].lazy=tr[x].lazy;
		tr[x].lazy1=0;
	}
}
void find (int now,int x)// 
{
	if (tr[now].l==tr[now].r)
	{
		X=tr[now].x;Y=tr[now].c;
		return ;
	}
	update(now);
	int s1=tr[now].s1,s2=tr[now].s2;
	int mid=(tr[now].l+tr[now].r)>>1;
	if (x<=mid) find(s1,x);
	else find(s2,x);
}
void change (int now,int l,int r)
{
	/*if (tr[now].l==tr[now].r)
	{
		tr[now].x=X;tr[now].c=Y;
		return ;
	}*/
	if (tr[now].l==l&&tr[now].r==r)
	{
		tr[now].x=X;tr[now].c=Y;
		tr[now].lazy=X;tr[now].lazy1=Y;
		return ;
	}
	update(now);
	int s1=tr[now].s1,s2=tr[now].s2;
	int mid=(tr[now].l+tr[now].r)>>1;
	if (r<=mid) change(s1,l,r);
	else if (l>mid) change(s2,l,r);
	else change(s1,l,mid),change(s2,mid+1,r);
}
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++) scanf("%d",&A[u]);
	int last=1;
	for (int u=2;u<=n;u++)
		if (A[u]!=A[last])//
		{
		//	printf("YES:%d %d\n",last,u-1);
			for (int i=last;i<=u;i++)	c[i]=make_pair(-(u-last),make_pair(last,u-1));
			s.insert(make_pair(-(u-last),make_pair(last,u-1)));
			last=u;
		}
	for (int i=last;i<=n;i++) c[i]=make_pair(-(n-last+1),make_pair(last,n));
//	printf("YES:%d %d\n",last,n);
	s.insert(make_pair(-(n-last+1),make_pair(last,n)));
	bt(1,n);
	int ans=0;
	int o=n;
	while (o>0)
	{
		P x=(*s.begin());
		o=o+x.first;
		s.erase(x); 	
	//	printf("%d %d %d\n",x.first,x.second.first,x.second.second);
		P g,G;
		int h=-1,H=0;
		if ((x.second.first)-1>=1)
		{
			find(1,x.second.first-1);
			g=X;h=Y;
		}
		if ((x.second.second)+1<=n)
		{
			find(1,x.second.second+1);
			G=X;H=Y;
		}
	/*	printf("G:%d %d %d\n",G.first,G.second.first,G.second.second);
		printf("g:%d %d %d\n",g.first,g.second.first,g.second.second);*/
		if (h==H)// 
		{
			s.erase(g);s.erase(G);
			/*
			/*
			if ((g.second.first)-1>=1)
			{
				find(1,g.second.first-1);
				change(1,g.second.first,g.second.second);
			}
			else if ((g.second.second)+1<=n)
			{
				find(1,g.second.second+1);
				change(1,g.second.first,g.second.second);
			}
			/**/
			/*
			if ((G.second.first)-1>=1)
			{
				find(1,G.second.first-1);
				change(1,G.second.first,G.second.second);
			}
			else if ((G.second.second)+1<=n)
			{
				find(1,G.second.second+1);
				change(1,G.second.first,G.second.second);
			}
			/**/
			int l=g.second.first,r=G.second.second;
			X=make_pair(g.first+G.first,make_pair(l,r));
		//	printf("ADD:%d %d %d\n",g.first+G.first,l,r);
			Y=H;
			s.insert(X);
			change(1,l,r);
		}
		else// 
		{
			if (H!=0)// 
			{
				s.insert(make_pair(G.first,make_pair(x.second.first,G.second.second)));
			//	printf("add:%d %d %d\n",G.first,x.second.first,G.second.second);
				s.erase(G);
				X=make_pair(G.first,make_pair(x.second.first,G.second.second));Y=H;
				change(1,x.second.first,G.second.second);
			}
			else if (h!=-1)
			{
				s.insert(make_pair(g.first,make_pair(g.second.first,x.second.second)));
			//	printf("add:%d %d %d\n",g.first,g.second.first,x.second.second);
				s.erase(g);
				X=make_pair(g.first,make_pair(g.second.first,x.second.second));Y=h;
				change(1,g.second.first,x.second.second);
			}
		}
		ans++;
	//system("pause");
	}
	printf("%d\n",ans);
	return 0;
}