#include<bits/stdc++.h>
using namespace std;
const int N=2000005,E=1000001;
struct str{
	int l;
	long long x;
	int d;
	long long las(){return x+(l-1)*d;}
}a[N];
int ch[N][2],fa[N],h[N],tot,hc,ls[N],siz[N],i;
struct seg{
	int l,r,x;
	bool operator <(const seg &a)const
	{
		return a.r>r;
	}
};
set<seg> p;
void pushup(int i)
{
	siz[i]=siz[ch[i][0]]+siz[ch[i][1]]+a[i].l;
}
void rotate(int x)
{
    int y=fa[x];bool d=(ch[y][0]==x);
    ch[y][!d]=ch[x][d];
    if(ch[x][d]!=0)fa[ch[x][d]]=y;
    fa[x]=fa[y];if(fa[y])ch[fa[y]][ch[fa[y]][1]==y]=x;
    ch[x][d]=y;fa[y]=x;pushup(y);
}
void splay(int i,int x,int t=0)
{
	for(int y=fa[x];y!=t;rotate(x),y=fa[x])
		if(fa[y]!=t&&(ch[fa[y]][0]==y)==(ch[y][0]==x))
			rotate(y);
	pushup(x);
	h[i]=x;
}
void Findmx(int x)
{
	int i=h[x];
	while(ch[i][1])
		i=ch[i][1];
	splay(x,i);
}
void Findmn(int x)
{
	int i=h[x];
	while(ch[i][0])
		i=ch[i][0];
	splay(x,i);
}
void MMerge(int x,int y)
{
	if(h[y]==0||h[x]==0)
	{
		h[x]=h[y]=max(h[x],h[y]);
		return;
	}
	int i=h[y];
	for(;ch[i][0];i=ch[i][0]);
	ch[i][0]=h[x];
	fa[h[x]]=i;
	splay(y,h[x]);
}
int Merge(int x,int y)
{
	Findmx(x),Findmn(y);
	if(abs(a[h[x]].las()-a[h[y]].x)<=1)
	{
		MMerge(x,y);
		return x;
	}
	if(a[h[x]].las()>a[h[y]].x)
	{
		long long la=a[h[y]].x;
		while(h[x]&&abs(a[h[x]].las()-la)>1)
		{
			if(a[h[x]].d==-1)
				la+=a[h[x]].l;
			else
			{
				if(la+a[h[x]].l<a[h[x]].x)
					la+=a[h[x]].l;
				else
				{
					int li=(a[h[x]].l-a[h[x]].x+la+2)/2;
					la+=a[h[x]].l-li;
					a[h[x]].l=li;
					break;
				}
			}
			h[x]=ch[h[x]][0];
			fa[h[x]]=0;
			Findmx(x);
		}
		h[++hc]=++tot;
		a[tot]={(int)(la-a[h[y]].x),la,-1};
		pushup(tot);
		ls[hc]=ls[x];
		MMerge(x,hc);
		MMerge(hc,y);
	}
	else
	{
		long long la=a[h[x]].las();
		while(h[y]&&abs(a[h[y]].x-la)>1)
		{
			if(a[h[y]].d==1)
				la+=a[h[y]].l;
			else
			{
				if(a[h[y]].las()>la+a[h[y]].l)
					la+=a[h[y]].l;
				else
				{
					int li=(a[h[y]].x-la)/2;
					a[h[y]].x-=li;
					a[h[y]].l-=li;
					la+=li;
					break;
				}
			}
			h[y]=ch[h[y]][1];
			fa[h[y]]=0;
			Findmn(y);
		}
		h[++hc]=++tot;
		a[tot]={(int)(la-a[h[x]].las()),a[h[x]].las()+1,1};
		pushup(tot);
		ls[hc]=ls[x];
		MMerge(x,hc);
		MMerge(hc,y);
	}
	return hc;
}
void Find(int n,int x,int w)
{
	if(w<siz[ch[x][0]])
		Find(n,ch[x][0],w);
	else
		if(siz[ch[x][0]]+a[x].l>w)
		{
			if(siz[ch[x][0]]==w)
			{
				splay(n,x,0);
				return;
			}
			int tmp=ch[x][1];
			ch[x][1]=++tot;
			ch[tot][1]=tmp;
			if(tmp)
				fa[tmp]=tot;
			fa[tot]=x;
			a[tot].l=a[x].l-(w-siz[ch[x][0]]);
			a[x].l=w-siz[ch[x][0]];
			a[tot].x=a[x].x+a[x].d*a[x].l;
			a[tot].d=a[x].d;
			splay(n,tot,0);
			return;
		}
		else
			Find(n,ch[x][1],w-a[x].l-siz[ch[x][0]]);
}
void Update(int l,int x)
{
	if(l==ls[x])
		return;
	int ti=l-ls[x];
	ls[x]=l;
	Findmn(x);
	long long w=a[h[x]].x;
	h[++hc]=++tot;
	a[tot]={ti,w+ti,-1};
	pushup(tot);
	MMerge(hc,x);
	while(1)
	{
		Findmx(x);
		if(ti<a[h[x]].l)
		{
			a[h[x]].l-=ti;
			break;
		}
		ti-=a[h[x]].l;
		h[x]=ch[h[x]][0];
		fa[h[x]]=0;
	}
}
void Add(int ti,int l,int r)
{
	h[++hc]=++tot;
	a[tot]={r-l+1,1<<30,1};
	pushup(tot);
	seg t={l,r,hc};
	ls[hc]=ti;
	auto it=p.lower_bound(t);
	if(it!=p.end()&&it->l==r+1)
	{
		Update(ti,it->x);
		t.x=Merge(t.x,it->x);
		t.r=it->r;
		p.erase(it);
	}
	it=p.lower_bound(t);
	if(it!=p.begin())
	{
		--it;
		if(it->r==l-1)
		{
			Update(ti,it->x);
			t.x=Merge(it->x,t.x);
			t.l=it->l;
			p.erase(it);
		}
	}
	p.insert(t);
}
void Del(int ti,int l,int r)
{
	seg t=*p.lower_bound({l,r,0});
	p.erase(t);
	Update(ti,t.x);
	Find(t.x,h[t.x],l-t.l);
	int u=ch[h[t.x]][0];
	fa[u]=ch[h[t.x]][0]=0;
	pushup(h[t.x]);
	int v=0;
	if(siz[h[t.x]]!=r-l+1)
	{
		Find(t.x,h[t.x],r-l+1);
		v=ch[h[t.x]][0];
		fa[v]=ch[h[t.x]][0]=0;
		v=h[t.x];
	}
	if(l!=t.l)
	{
		h[++hc]=u;
		ls[hc]=ti;
		p.insert({t.l,l-1,hc});
	}
	if(r!=t.r)
	{
		h[++hc]=v;
		ls[hc]=ti;
		p.insert({r+1,t.r,hc});
	}
}
int n,l,r,x,y,u,v,tree[N*4],lazy[N*4];
long long as=1<<30;
struct node{
	int l,r;
};
vector<node> ad[E+5],de[E+5];
void modify(int i,int l,int r,int ll,int rr,int x)
{
	if(l>=ll&&r<=rr)
	{
		lazy[i]+=x;
		tree[i]+=x;
		return;
	}
	int mid=l+r>>1;
	if(mid>=ll)
		modify(i<<1,l,mid,ll,rr,x);
	if(mid<rr)
		modify(i<<1|1,mid+1,r,ll,rr,x);
	tree[i]=max(tree[i<<1],tree[i<<1|1])+lazy[i];
}
int Query(int i,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)
		return tree[i];
	int mid=l+r>>1,s=0;
	if(mid>=ll)
		s=max(s,Query(i<<1,l,mid,ll,rr));
	if(mid<rr)
		s=max(s,Query(i<<1|1,mid+1,r,ll,rr));
	return s+lazy[i];
}
int Findmx(int i,int l,int r,int ll,int s)
{
	if(s+tree[i]==0)
		return -1;
	if(l==r)
		return l-1;
	int mid=l+r>>1;
	s+=lazy[i];
	if(l>=ll)
	{
		int y=Findmx(i<<1,l,mid,ll,s);
		if(y!=-1)
			return y;
		else
			return Findmx(i<<1|1,mid+1,r,ll,s);
	}
	if(mid>=ll)
	{
		int y=Findmx(i<<1,l,mid,ll,s);
		if(y!=-1)
			return y;
	}
	return Findmx(i<<1|1,mid+1,r,ll,s);
}
int Findmn(int i,int l,int r,int rr,int s)
{
	if(s+tree[i]==0)
		return -1;
	if(l==r)
		return l+1;
	int mid=l+r>>1;
	s+=lazy[i];
	if(r<=rr)
	{
		int y=Findmn(i<<1|1,mid+1,r,rr,s);
		if(y!=-1)
			return y;
		else
			return Findmn(i<<1,l,mid,rr,s);
	}
	if(mid<rr)
	{
		int y=Findmn(i<<1|1,mid+1,r,rr,s);
		if(y!=-1)
			return y;
	}
	return Findmn(i<<1,l,mid,rr,s);
}
void dfs(int i)
{
	if(!i)
		return;
	as=min({as,a[i].x,a[i].las()});
	dfs(ch[i][0]);
	dfs(ch[i][1]);
}
int main()
{
	scanf("%d",&n);
	scanf("%d",&x);
	for(i=1;i<=n;++i)
	{
		scanf("%d %d %d %d",&l,&r,&u,&v);
		--l,++r;
		de[l].push_back({u,v});
		ad[r].push_back({u,v});
	}
	p.insert({0,E*2+5,++hc});
	h[hc]=++tot;
	a[tot]={E*2+5-x+1,0,1};
	ch[tot][0]=2;
	fa[++tot]=1;
	a[tot]={x,x,-1};
	pushup(2);
	pushup(1);
	for(i=0;i<=E+1;++i)
	{
		for(auto it:ad[i])
		{
			modify(1,0,E,it.l,it.r,-1);
			auto ii=p.lower_bound({it.l,it.r,0});
			int nr=ii->l-1;
			--ii;
			int nl=ii->r+1;
			if(nl>nr)
				continue;
			int y=Findmx(1,0,E,nl,0);
			if(y>=nr||y==-1)
				Add(i,nl,nr);
			else
			{
				if(y>=nl)
					Add(i,nl,y);
				int y=Findmn(1,0,E,nr,0);
				if(y<=nr)
					Add(i,y,nr);
			}
		}
		for(auto it:de[i])
		{
			modify(1,0,E,it.l,it.r,1);
			while(1)
			{
				auto y=p.lower_bound({0,it.l,0});
				if(y!=p.end())
				{
					if(min(it.r,y->r)>=max(it.l,y->l))
						Del(i,max(it.l,y->l),min(it.r,y->r));
					else
						break;
				}
				else
					break;
			}
		}
	}
	dfs(h[p.begin()->x]);
	cout<<as;
}