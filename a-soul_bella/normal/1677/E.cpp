#include <bits/stdc++.h>
#define int long long
using namespace std;
struct stree
{
	int a[500005],b[500005];
	struct node
	{
		int l,r,sa,sb;
		int addab,adda1;
		int kb,bb;
	}t[2100005];
	inline node mer(node x,node y)
	{
		return {x.l,y.r,(x.sa+y.sa),(x.sb+y.sb),0,0,1,0};
	}
	inline void build(int now,int l,int r)
	{
		t[now]={l,r,0,0,0,0,1,0};
		if(l==r)
		{
			t[now].sa=a[l],t[now].sb=b[l];
			return ;
		}
		int mid=(l+r)/2;
		build(now*2,l,mid),build(now*2+1,mid+1,r);
		t[now].sa=(t[now*2].sa+t[now*2+1].sa);
		t[now].sb=(t[now*2].sb+t[now*2+1].sb);
	}
	inline void givea(int now,int ab,int a1)
	{
		t[now].addab=(t[now].addab+ab*t[now].kb);
		t[now].adda1=(t[now].adda1+ab*t[now].bb+a1);
		t[now].sa=(t[now].sa+t[now].sb*ab+a1*(t[now].r-t[now].l+1));
	}
	inline void giveb(int now,int k,int b)
	{
		t[now].bb=(t[now].bb*k+b);
		t[now].kb=t[now].kb*k;
		t[now].sb=(t[now].sb*k+b*(t[now].r-t[now].l+1));
	}
	inline void pd(int now)
	{
		givea(now*2,t[now].addab,t[now].adda1);
		givea(now*2+1,t[now].addab,t[now].adda1);
		giveb(now*2,t[now].kb,t[now].bb);
		giveb(now*2+1,t[now].kb,t[now].bb);
		t[now].adda1=t[now].addab=t[now].bb=0;
		t[now].kb=1;
	}
	inline void changea(int now,int l,int r,int k)
	{
		if(t[now].l==l&&t[now].r==r)
		{
			givea(now,k,0);
			return ;
		}
		pd(now);
		if(t[now*2].r>=r) changea(now*2,l,r,k);
		else if(t[now*2+1].l<=l) changea(now*2+1,l,r,k);
		else changea(now*2,l,t[now*2].r,k),changea(now*2+1,t[now*2+1].l,r,k);
		t[now].sa=(t[now*2].sa+t[now*2+1].sa);
		t[now].sb=(t[now*2].sb+t[now*2+1].sb);
	}
	inline void changeb(int now,int l,int r,int k,int b)
	{
		if(t[now].l==l&&t[now].r==r)
		{
			giveb(now,k,b);
			return ;
		}
		pd(now);
		if(t[now*2].r>=r) changeb(now*2,l,r,k,b);
		else if(t[now*2+1].l<=l) changeb(now*2+1,l,r,k,b);
		else changeb(now*2,l,t[now*2].r,k,b),changeb(now*2+1,t[now*2+1].l,r,k,b);
		t[now].sa=(t[now*2].sa+t[now*2+1].sa);
		t[now].sb=(t[now*2].sb+t[now*2+1].sb);
	}
	inline int askb(int now,int l,int r)
	{
		if(t[now].l==l&&t[now].r==r) return t[now].sb;
		pd(now);
		if(t[now*2].r>=r) return askb(now*2,l,r);
		else if(t[now*2+1].l<=l) return askb(now*2+1,l,r);
		else return (askb(now*2,l,t[now*2].r)+askb(now*2+1,t[now*2+1].l,r));
	}
	inline int aska(int now,int l,int r)
	{
		if(t[now].l==l&&t[now].r==r) return t[now].sa;
		pd(now);
		if(t[now*2].r>=r) return aska(now*2,l,r);
		else if(t[now*2+1].l<=l) return aska(now*2+1,l,r);
		else return (aska(now*2,l,t[now*2].r)+aska(now*2+1,t[now*2+1].l,r));
	}
}T;
int out[1000005];
struct query
{
	int l,r,id;
}b[1000005];
int a[200005],pos[200005];
inline bool cmp(query x,query y)
{
	return x.r<y.r;
}
int l[200005],r[200005],s[200005],ssz;
int n,q;
vector <int> F[200005];
inline void INS(int i)
{
	while(ssz&&a[s[ssz]]<a[i])
	{
		T.changeb(1,l[a[s[ssz]]],r[a[s[ssz]]],0,0);
		l[a[s[ssz]]]=r[a[s[ssz]]]=0;
		--ssz;
	}
	for(int j=a[i]+a[i];j<=n;j+=a[i])
	{
		if(a[i]*a[i]==j) continue;
		if(l[j])
		{
			int p=pos[j/a[i]];
			if(p<l[j]||p>=i) continue;
			T.changeb(1,l[j],min(p,r[j]),0,1);
		}
	}
	l[a[i]]=s[ssz]+1,r[a[i]]=i,s[++ssz]=i;
	int mx=l[a[i]]-1;
	for(auto t:F[a[i]])
	{
		int p1=pos[t],p2=pos[a[i]/t];
		if(p1==p2) continue;
	/*	if(i==2)
		{
			cout << p1 << " " << p2 << "**\n";
		}*/
		if(p1>i||p2>i) continue;
		mx=max(mx,min(p1,p2));
	}
//	if(i==7) cout << l[a[i]] << " " << r[a[i]] << "!!!!\n";
	if(mx>=l[a[i]]) T.changeb(1,l[a[i]],mx,0,1);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i) F[j].push_back(i);
	T.build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		pos[a[i]]=i;
	}
	for(int i=1;i<=q;i++)
	{
		cin >> b[i].l >> b[i].r;
		b[i].id=i;
	}
	sort(b+1,b+q+1,cmp);
	int now=0;
	for(int i=1;i<=q;i++)
	{
		while(now<b[i].r)
		{
			++now;
			INS(now);
			T.changea(1,1,n,1);
	/*		for(int i=1;i<=n;i++)
				cout << T.sb(1,i,i) << " ";
			cout << "\n";
			for(int i=1;i<=n;i++)
				cout << T.sa(1,i,i) << " ";
			cout << "\n";
			cout << "\n";*/
		}
		out[b[i].id]=T.aska(1,b[i].l,b[i].r);
	}
	for(int i=1;i<=q;i++)
		cout << out[i] << "\n";
	return 0;
}
/*
5 1
4 2 5 1 3
2 4
*/