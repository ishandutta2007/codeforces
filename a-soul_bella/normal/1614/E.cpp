#include <bits/stdc++.h>
using namespace std;
struct stree
{
	int l,r,add,tag,ls,rs,radd,ladd;
}t[18000005];
int cnt=0;
inline void build(int l,int r)
{
	t[++cnt].l=l,t[cnt].r=r;
}
inline void give(int now,int x)
{
	t[now].add+=x,t[now].tag+=x;
	t[now].ladd+=x,t[now].radd+=x;
}
inline void pd(int now)
{
	if(t[now].l==t[now].r)
	{
		t[now].radd=t[now].ladd=t[now].add;
		return ;
	}
	if(!t[now].ls)
	{
		t[now].ls=++cnt;
		int mid=(t[now].l+t[now].r)/2;
		if(t[now].l+t[now].r<0) mid=-1;
		t[cnt]={t[now].l,mid,0,0,0,0};
	}
	if(!t[now].rs)
	{
		t[now].rs=++cnt;
		int mid=(t[now].l+t[now].r)/2;
		if(t[now].l+t[now].r<0) mid=-1;
		t[cnt]={mid+1,t[now].r,0,0,0,0};
	}
//	cout << t[now].l << " " << t[now].r << " " << t[now].add << " " << t[now].tag << "*\n"; 
	give(t[now].ls,t[now].tag);
	give(t[now].rs,t[now].tag);
	t[now].tag=0;
}
inline void add(int now,int l,int r,int x)
{
	if(t[now].l==l&&t[now].r==r)
	{
		give(now,x);
		return ;
	}
	pd(now);
	if(t[t[now].ls].r>=r) add(t[now].ls,l,r,x);
	else if(t[t[now].rs].l<=l) add(t[now].rs,l,r,x);
	else add(t[now].ls,l,t[t[now].ls].r,x),add(t[now].rs,t[t[now].rs].l,r,x);
	t[now].radd=t[t[now].rs].radd;
	t[now].ladd=t[t[now].ls].ladd;
}
inline int qwql(int now,int x)
{
	if(t[now].r==t[now].l) return t[now].l;
	pd(now);
	if(t[t[now].ls].r+t[t[now].ls].radd>=x) return qwql(t[now].ls,x);
	return qwql(t[now].rs,x);
}
inline int qwqr(int now,int x)
{
	if(t[now].r==t[now].l) return t[now].l;
	pd(now);
	if(t[t[now].rs].l+t[t[now].rs].ladd<=x) return qwqr(t[now].rs,x);
	return qwqr(t[now].ls,x);
}
inline int query(int now,int x)
{
//	cout << t[now].l << " " << t[now].r << " " << t[now].add << "*\n";
	if(t[now].l==x&&t[now].r==x)return t[now].add+x;
	pd(now);
	if(t[t[now].rs].l<=x) return query(t[now].rs,x);
	return query(t[now].ls,x);
}
int lans=0;
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	build(-1,1000000001);
	for(int i=1;i<=n;i++)
	{
		int T;
		cin >> T;
		int p=qwqr(1,T-1);
		if(p>=0) add(1,0,p,1);
		p=qwql(1,T+1);
		//cout << p << "*\n";
		if(p<=1000000000) add(1,p,1000000000,-1);
		int q;
		cin >> q;
		while(q--)
		{
			int x;
			cin >> x;
			x=(x+lans)%1000000001;
			cout << (lans=query(1,x)) << '\n';
		}
	}
	return 0;
}
/*
3
4 0
2 0
0 1 0
*/