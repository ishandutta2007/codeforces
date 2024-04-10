#include<bits/stdc++.h>
#define ll long long
#define N 500015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define ls (p<<1)
#define rs (p<<1|1)
using namespace std;
int n,a[N],pos[N];
VI o[N];
namespace seg{
	int lazy[N<<2],mx[N<<2],cnt[N<<2];
	void build(int p,int l,int r){
		mx[p] = 0;cnt[p] = r-l+1;
		if(l==r) return;
		int mid = (l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
	}
	void change(int p,int l,int r,int x,int y,int v){
		if(x <= l&&r <= y){
			lazy[p] += v;
			mx[p] += v;
			return;
		}
		int mid = (l+r)>>1;
		if(x <= mid) change(ls,l,mid,x,y,v);
		if(y > mid)  change(rs,mid+1,r,x,y,v);
		mx[p] = max(mx[ls],mx[rs]);cnt[p] = 0;
		if(mx[p] == mx[ls]) cnt[p] += cnt[ls];
		if(mx[p] == mx[rs]) cnt[p] += cnt[rs];
		mx[p] += lazy[p];
	}
}
using namespace seg;
void change(int x,int v){
	change(1,0,n,o[x][pos[x]],o[x][pos[x]+1]-1,v);
	if(pos[x]+3 < o[x].size()-1)
		change(1,0,n,o[x][pos[x]+3],o[x][pos[x]+4]-1,v);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&n);
 	rep(i,1,n) scanf("%d",&a[i]);
 	rep(i,1,n) o[i].pb(0);
 	rep(i,1,n) o[a[i]].pb(i);
 	rep(i,1,n) o[i].pb(n+1);
 	build(1,0,n);
 	rep(i,1,n) change(i,1);
 	ll ans = 0;
 	rep(i,1,n){
 		change(1,0,n,i-1,i-1,-inf);
 		if(mx[1] == n) ans += cnt[1];
 		change(a[i],-1);
 		pos[a[i]]++;
 		change(a[i],1);
 	}
 	printf("%lld\n",ans);
	return 0;
}