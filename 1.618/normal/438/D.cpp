#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
typedef long long ll;
int n,m,a[maxn];
ll val[maxn * 4],sum[maxn * 4];
void up(int id){
	val[id] = max(val[id << 1],val[id << 1 | 1]);
	sum[id] = sum[id << 1] + sum[id << 1 | 1];
}
void build(int id,int l,int r){
	if(l == r){
		val[id] = sum[id] = a[l];
	}else{
		int mid = (l + r) >> 1;
		build(id<<1,l,mid);
		build(id<<1|1,mid+1,r);
		up(id);
	}
}
void update(int id,int l,int r,int pos,int x){
	if(l == r){
		val[id] = sum[id] = x;
	}else{
		int mid = (l + r) >> 1;
		if(pos <= mid) update(id<<1,l,mid,pos,x);
		else update(id<<1|1,mid+1,r,pos,x);
		up(id);
	}
}
bool cut(int id,int mod){
	return val[id] < mod;
}
void modulo(int id,int l,int r,int x,int y,int mod){
	if(cut(id,mod)) return;
	if(l == r){
		val[id] %= mod;
		sum[id] %= mod;
	}else{
		int mid = (l + r) >> 1;
		if(x <= mid) modulo(id<<1,l,mid,x,y,mod);
		if(y > mid) modulo(id<<1|1,mid+1,r,x,y,mod);
		up(id);
	}
}
ll query(int id,int l,int r,int x,int y){
	if(x <= l && r <= y) return sum[id];
	int mid = (l + r) >> 1;
	ll res = 0;
	if(x <= mid) res += query(id<<1,l,mid,x,y);
	if(mid < y) res += query(id<<1|1,mid+1,r,x,y);
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int fl;
		scanf("%d",&fl);
		if(fl == 1){
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%I64d\n",query(1,1,n,l,r));
		}else if(fl == 2){
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			modulo(1,1,n,l,r,x);
	  }else{
	  	int k,x;
	  	scanf("%d%d",&k,&x);
	  	update(1,1,n,k,x);
	  }
	}
	return 0;
}