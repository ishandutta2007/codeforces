#include<bits/stdc++.h>
#define ll long long
#define N 500015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n,q;
char s[N];
namespace seg{
	#define ls (p<<1)
	#define rs (p<<1|1)
	struct info{
		int pl,pr,sl,sr,val,len;
		void print(){
			printf("pre: %d %d,suf: %d %d,val: %d\n",pl,pr,sl,sr,val);
		}
		info(){}
		info(int a,int b,int c,int d,int e,int f){pl = a;pr = b;sl = c;sr = d;val = e;len = f;}
	}cur[N<<2],rev[N<<2];
	int lazy[N<<2];
	info uni(info l,info r){
		if(l.pl+l.pr == l.len && r.pl == 0) l.pr += r.pr;
		if(r.sl+r.sr == r.len && l.sr == 0) r.sl += l.sl;
		if(l.pl == l.len) l.pr = r.pr,l.pl += r.pl;
		if(r.sr == r.len) r.sl = l.sl,r.sr += l.sr;
		l.val = max({l.val,l.pl+l.pr,l.sl+l.sr});
		r.val = max({r.val,r.pl+r.pr,r.sl+r.sr});
		info tmp = info(l.pl,l.pr,r.sl,r.sr,max({l.val,r.val,(r.pl==0)?(l.sl+l.sr+r.pr):0,(l.sr==0)?(l.sl+r.pl+r.pr):0}),l.len+r.len);
		return tmp;
	}
	void pushup(int p){
		cur[p] = uni(cur[ls],cur[rs]);
		rev[p] = uni(rev[ls],rev[rs]);
	}
	void down(int p){
		lazy[p] ^= 1; swap(cur[p],rev[p]);
	}
	void pushdown(int p){
		if(lazy[p]){
			lazy[p] = 0;
			down(ls); down(rs);
		}
	}
	void build(int p,int l,int r){
		if(l == r){
			int u = (s[l]=='>'),v = (s[l]=='<');
			cur[p] = info(u,v,u,v,u+v,1);
			rev[p] = info(v,u,v,u,v+u,1);
			// printf("[l,r]: [%d,%d]\n",l,r);
			// rev[p].print();
			return;
		}
		int mid = (l+r)>>1;
		build(ls,l,mid); build(rs,mid+1,r);
		pushup(p);
		// printf("[l,r]: [%d,%d]\n",l,r);
		// rev[p].print();
	}
	void change(int p,int l,int r,int x,int y){
		if(x <= l && r <= y){
			down(p);
			return;
		}
		int mid = (l+r)>>1;
		pushdown(p);
		if(x <= mid) change(ls,l,mid,x,y);
		if(y > mid) change(rs,mid+1,r,x,y);
		pushup(p);
	}
	info query(int p,int l,int r,int x,int y){
		if(x <= l && r <= y){
			// printf("[l,r]: [%d,%d]\n",l,r);
			// cur[p].print();
			return cur[p];
		}
		int mid = (l+r)>>1,fl,fr; fl = fr = 0;
		pushdown(p);
		info il,ir;
		if(x <= mid) il = query(ls,l,mid,x,y),fl = 1;
		if(y > mid)  ir = query(rs,mid+1,r,x,y),fr = 1;
		pushup(p);
		info res;
		if(fl && fr) res = uni(il,ir);
		else if(fl) res = il;
		else if(fr) res = ir;
		// printf("[l,r]: [%d,%d]\n",l,r);
		// res.print(); 
		return res;
		// return info(0,0,0,0,0,0);
	}
}
using namespace seg;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	build(1,1,n);
	// rep(l,1,n) rep(r,l,n){
	// 	printf("[l,r]: [%d,%d]\n",l,r);
	// 	printf("%d\n",query(1,1,n,l,r).val);
	// }
	while(q--){
		int l,r; scanf("%d%d",&l,&r);
		change(1,1,n,l,r);
		// rep(i,l,r) if(s[i]=='<') s[i] = '>';
		// else s[i] = '<';
		// printf("%s\n",s+1);
		info x = query(1,1,n,l,r);
		printf("%d\n",x.val);
	}
	return 0;
}
/*
10 10
><>>>>>>><
1 10

<><<<<<<<>
[l,r]: [1,1]
pre: 0 1,suf: 0 1,val: 1
[l,r]: [2,2]
pre: 1 0,suf: 1 0,val: 1
[l,r]: [1,2]
pre: 0 1,suf: 1 0,val: 1
[l,r]: [3,3]
pre: 0 1,suf: 0 1,val: 1
[l,r]: [1,3]
pre: 0 1,suf: 2 1,val: 3
[l,r]: [4,4]
pre: 0 1,suf: 0 1,val: 1
[l,r]: [5,5]
pre: 0 1,suf: 0 1,val: 1
[l,r]: [4,5]
pre: 0 2,suf: 0 2,val: 2
[l,r]: [1,5]
pre: 0 1,suf: 2 3,val: 5
[l,r]: [6,6]
pre: 0 1,suf: 0 1,val: 1
[l,r]: [7,7]
pre: 0 1,suf: 0 1,val: 1
[l,r]: [6,7]
pre: 0 2,suf: 0 2,val: 2
[l,r]: [8,8]
pre: 0 1,suf: 0 1,val: 1
[l,r]: [6,8]
pre: 0 3,suf: 0 3,val: 3
[l,r]: [9,9]
pre: 0 1,suf: 0 1,val: 1
[l,r]: [10,10]
pre: 1 0,suf: 1 0,val: 1
[l,r]: [9,10]
pre: 0 1,suf: 1 0,val: 1
[l,r]: [6,10]
pre: 0 4,suf: 1 0,val: 4
[l,r]: [1,10]
pre: 0 1,suf: 1 0,val: 9
*/