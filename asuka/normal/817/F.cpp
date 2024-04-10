#include<bits/stdc++.h>
#define int long long
#define N 800015
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
int n,m;
struct query{
	int opt,l,r;
	query(){}
	query(int a,int b,int c){opt = a;l = b;r = c;}
}q[N];
VI num;
void Add(int x){
	num.pb(x); num.pb(x+1);
	if(x-1 > 0) num.pb(x-1);
}
int len[N<<2],cnt[N<<2],lazy[N<<2],rev[N<<2];
#define ls (p<<1)
#define rs (p<<1|1)
void pushup(int p){
	cnt[p] = cnt[ls] + cnt[rs];
}
void build(int p,int l,int r){
	len[p] = r-l+1;
	if(l == r) return;
	int mid = (l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
}
void down(int p,int val){
	lazy[p] = val; rev[p] = 0;
	cnt[p] = val?len[p]:0;
}
void Rev(int p){
	rev[p] ^= 1;
	cnt[p] = len[p] - cnt[p];
}
void pushdown(int p){
	if(~lazy[p]){
		// printf("lazy: %lld %lld\n",p,lazy[p]);
		down(ls,lazy[p]);
		down(rs,lazy[p]);
		lazy[p] = -1;
	}
	if(rev[p]){
		// printf("rev: %lld\n",p);
		Rev(ls); Rev(rs);
		rev[p] = 0;
	}
}
void change(int p,int l,int r,int x,int y,int val){
	if(x <= l && r <= y)
		return down(p,val);
	pushdown(p);
	int mid = (l+r)>>1;
	if(x <= mid) change(ls,l,mid,x,y,val);
	if(y > mid) change(rs,mid+1,r,x,y,val);
	pushup(p);
}
void Rev(int p,int l,int r,int x,int y){
	if(x <= l && r <= y)
		return Rev(p);
	pushdown(p);
	int mid = (l+r)>>1;
	if(x <= mid) Rev(ls,l,mid,x,y);
	if(y > mid) Rev(rs,mid+1,r,x,y);
	pushup(p);
}
int query(int p,int l,int r){
	if(l == r) return l;
	pushdown(p);
	// printf("[%lld , %lld] , %lld %lld\n",l,r,cnt[ls],cnt[rs]);
	int mid = (l+r)>>1;
	if(len[ls] == cnt[ls]) return query(rs,mid+1,r);
	else return query(ls,l,mid);
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld",&n);
 	memset(lazy,-1,sizeof lazy);
 	rep(i,1,n){
 		scanf("%lld%lld%lld",&q[i].opt,&q[i].l,&q[i].r);
 		Add(q[i].l); Add(q[i].r);
 	}
 	num.pb(1); num.pb(1000000000000000001);
 	sort(all(num)); num.erase(unique(all(num)),num.end());
 	m = SZ(num);
 	// printf("%lld\n",m);
 	// rep(i,1,m) printf("%lld ",num[i-1]); printf("\n");
 	rep(i,1,n) q[i].l = lower_bound(all(num),q[i].l) - num.begin() + 1;
 	rep(i,1,n) q[i].r = lower_bound(all(num),q[i].r) - num.begin() + 1;
 	build(1,1,m);
 	rep(i,1,n){
 		// printf("[%lld , %lld]\n",q[i].l,q[i].r);
 		if(q[i].opt == 1) change(1,1,m,q[i].l,q[i].r,1);
 		if(q[i].opt == 2) change(1,1,m,q[i].l,q[i].r,0);
 		if(q[i].opt == 3) Rev(1,1,m,q[i].l,q[i].r);
 		printf("%lld\n",num[query(1,1,m)-1]);
 	}
	return 0;
}