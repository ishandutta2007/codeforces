#include<bits/stdc++.h>
#define ll long long
#define N 200015
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
int n,q,a[N];
const int all = (1<<20)-1;
int ls[N<<5],rs[N<<5],lz[N<<5],t0[N<<5],t1[N<<5],tr[N<<5],rt,tot;
void pushup(int p){
	tr[p] = tr[ls[p]]+tr[rs[p]];
	t0[p] = t0[ls[p]]|t0[rs[p]];
	t1[p] = t1[ls[p]]|t1[rs[p]];
}
void Xor(int p,int dep,int x){
	if(!p) return;
	if(x>>(dep-1)&1) swap(ls[p],rs[p]);
	int v0 = (t1[p]&x)|(t0[p]&(~x)),v1 = (t0[p]&x)|(t1[p]&(~x));
	t0[p] = v0; t1[p] = v1; lz[p] ^= x;
}
void pushdown(int p,int dep){
	if(lz[p]){
		Xor(ls[p],dep-1,lz[p]);
		Xor(rs[p],dep-1,lz[p]);
		lz[p] = 0;
	}
}
void Split(int &u,int &v,int dep,int l,int r,int a,int b){
	if(a <= l && r <= b){
		v = u; u = 0;
		return;
	}
	pushdown(u,dep);
	v = ++tot;
	int mid = (l+r)>>1;
	if(a <= mid) Split(ls[u],ls[v],dep-1,l,mid,a,b);
	if(b > mid) Split(rs[u],rs[v],dep-1,mid+1,r,a,b);
	pushup(u); pushup(v);
}
void merge(int &u,int &v,int dep){
	if(!u) return u = v,void();
	if(!v || !dep) return;
	pushdown(u,dep); pushdown(v,dep);
	merge(ls[u],ls[v],dep-1); merge(rs[u],rs[v],dep-1);
	pushup(u);
}
void ins(int &p,int x,int dep){
	if(!p) p = ++tot;
	if(!dep){
		tr[p] = 1;
		t0[p] = x^all;
		t1[p] = x;
		return;
	}
	if(x>>(dep-1)&1) ins(rs[p],x,dep-1);
	else ins(ls[p],x,dep-1);
	pushup(p);
}
void Or(int p,int dep,int x){
	if(!p || !dep) return;
	if(!(x&t0[p]&t1[p])){
		Xor(p,dep,x&t0[p]);
		return;
	}
	pushdown(p,dep);
	if(x>>(dep-1)&1){
		Xor(ls[p],dep-1,1<<(dep-1));
		merge(rs[p],ls[p],dep-1);
		ls[p] = 0;
	}
	Or(ls[p],dep-1,x);
	Or(rs[p],dep-1,x);
	pushup(p);
}
int query(int p,int dep,int l,int r,int x,int y){
	if(x <= l && r <= y) return tr[p];
	int mid = (l+r)>>1;
	pushdown(p,dep);
	int res = 0;
	if(x <= mid) res += query(ls[p],dep-1,l,mid,x,y);
	if(y > mid) res += query(rs[p],dep-1,mid+1,r,x,y);
	return res;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&q);
	rep(i,1,n){
		int x; scanf("%d",&x);
		ins(rt,x,20);
	}
	while(q--){
		int typ,l,r,x;
		scanf("%d%d%d",&typ,&l,&r);
		if(typ <= 3){
			int v;
			scanf("%d",&x);
			Split(rt,v,20,0,all,l,r);
			if(typ == 1) Xor(v,20,all),Or(v,20,x^all),Xor(v,20,all);
			if(typ == 2) Or(v,20,x);
			if(typ == 3) Xor(v,20,x);
			merge(rt,v,20);
		}else{
			printf("%d\n",query(rt,20,0,all,l,r));
		}
	}
	return 0;
}