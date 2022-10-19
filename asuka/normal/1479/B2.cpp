#include<bits/stdc++.h>
#define ll long long
#define N 114514
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
using namespace std;
int n,a[N];
namespace seg{
	#define ls (p<<1)
	#define rs (p<<1|1)
	int Min[N<<2],lazy[N<<2];
	void pushup(int p){
		Min[p] = min(Min[ls],Min[rs]);
	}
	void down(int p,int v){ Min[p]+=v; lazy[p]+=v;}
	void pushdown(int p){
		if(lazy[p]){ int v = lazy[p];
			down(ls,v); down(rs,v);
			lazy[p] = 0;
		}
	}
	void build(int p,int l,int r){
		if(l == r){return Min[p] = 0,void();}
		int mid = (l+r)>>1;
		build(ls,l,mid); build(rs,mid+1,r); pushup(p);
	}
	void add(int p,int l,int r,int x,int y,int v){
		if(x > y) return ;
		if(x <= l && r <= y){
			return down(p,v),void();
		}
		int mid = (l+r)>>1;
		pushdown(p);
		if(x <= mid) add(ls,l,mid,x,y,v);
		if(y > mid) add(rs,mid+1,r,x,y,v);
		pushup(p);
	}
	int query(int p,int l,int r,int x,int y){
		if(x > y) return inf;
		if(x <= l && r <= y){
			return Min[p];
		}
		int mid = (l+r)>>1;
		pushdown(p);
		int res = inf;
		if(x <= mid) res = min(res,query(ls,l,mid,x,y));
		if(y > mid) res = min(res,query(rs,mid+1,r,x,y));
		return res;
	}
	void change(int p,int l,int r,int pos,int v){
		if(l == r){
			lazy[p] = 0; Min[p] = v;
			return;
		}
		int mid = (l+r)>>1;
		pushdown(p);
		if(pos <= mid) change(ls,l,mid,pos,v);
		if(pos > mid) change(rs,mid+1,r,pos,v);
		pushup(p);
	}
}
using namespace seg;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&n);
 	rep(i,1,n) scanf("%d",&a[i]);
 	// build(1,0,n);
 	int len = unique(a+1,a+n+1)-a-1;
 	// rep(i,1,n) printf("%d\n",a[i]);
 	rep(i,1,len){
 		add(1,0,n,a[i],a[i],-1);
 		int res = query(1,0,n,0,n)+1;
 		add(1,0,n,a[i],a[i],1);
 		add(1,0,n,0,n,1);
 		change(1,0,n,a[i-1],res);//,puts("Yes");
 	}
 	printf("%d\n",query(1,0,n,0,n)+1);
	return 0;
}