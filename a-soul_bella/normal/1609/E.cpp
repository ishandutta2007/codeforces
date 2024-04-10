#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
struct stree
{
	int l,r,aa,ab,ac,bb,bc,cc;
}t[300005];
inline stree mer(stree x,stree y)
{
	stree rtn;
	rtn.l=x.l,rtn.r=y.r;
	rtn.aa=x.aa+y.aa;
	rtn.bb=x.bb+y.bb;
	rtn.cc=x.cc+y.cc;
	rtn.ab=max(x.aa+y.ab,x.ab+y.bb);
	rtn.bc=max(x.bb+y.bc,x.bc+y.cc);
	rtn.ac=max(max(x.aa+y.ac,x.ab+y.bc),x.ac+y.cc);
	return rtn;
}
inline void build(int now,int l,int r)
{
	t[now].l=l,t[now].r=r;
	if(l==r)
	{
		if(s[l]=='a')
		{
			t[now].ab=1;
			t[now].bb=1;
			t[now].cc=1;
			t[now].ac=1;
			t[now].bc=1;
		}
		else if(s[l]=='b')
		{
			t[now].aa=1;
			t[now].bc=1;
			t[now].cc=1;
			t[now].ac=1;
			t[now].ab=1;
		}
		else t[now].aa=t[now].ab=t[now].ac=t[now].bb=t[now].bc=1;
		return ;
	}
	int mid=(l+r)/2;
	build(now*2,l,mid),build(now*2+1,mid+1,r);
	t[now]=mer(t[now*2],t[now*2+1]);
}
inline void change(int now,int x,char c)
{
	if(t[now].l==t[now].r)
	{
		t[now].ab=t[now].bc=t[now].cc=0;
		t[now].ac=t[now].bb=t[now].aa=0;
		if(c=='a')
		{
			t[now].ab=1;
			t[now].bb=1;
			t[now].cc=1;
			t[now].ac=1;
			t[now].bc=1;
		}
		else if(c=='b')
		{
			t[now].aa=1;
			t[now].bc=1;
			t[now].cc=1;
			t[now].ac=1;
			t[now].ab=1;
		}
		else t[now].aa=t[now].ab=t[now].ac=t[now].bb=t[now].bc=1;
		return ;
	}
	if(t[now*2].r>=x) change(now*2,x,c);
	else change(now*2+1,x,c);
	t[now]=mer(t[now*2],t[now*2+1]);
}
inline int query()
{
	return t[1].ac;
}
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,T;
	cin >> n >> T >> s;
	s=' '+s;
	build(1,1,n);
	while(T--)
	{
		int pos;
		char c;
		cin >> pos >> c;
		change(1,pos,c);
		s[pos]=c;
		cout << n-query() << "\n";
	}
	return 0;
}