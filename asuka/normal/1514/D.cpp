#include<bits/stdc++.h>
#define ll long long
#define N 300015
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
int n,q,a[N],cnt[N],rt[N];
VI ans,pos[N];
namespace seg{
	#define ls (p<<1)
	#define rs (p<<1|1)
	int cnt[N<<2],typ[N<<2];
	void pushup(int p,int l,int r){
		int cl,cr; cl = cr = 0;
		rep(i,l,r) {
			if(a[i] == typ[ls]) cl++;
			if(a[i] == typ[rs]) cr++;
		}
		cnt[p] = max(cl+cnt[ls],cr+cnt[rs]);
		typ[p] = (cl+cnt[ls]) > (cr+cnt[rs]) ? typ[ls] : typ[rs];
	}
	void build(int p,int l,int r){
		if(l == r){
			typ[p] = a[l]; cnt[p] = 1;
			return;
		}
		int mid = (l+r)>>1;
		build(ls,l,mid); build(rs,mid+1,r);
		pushup(p,l,r);
	}
	void query(int p,int l,int r,int x,int y){
		if(x <= l && r <= y){
			ans.pb(typ[ls]); ans.pb(typ[rs]); ans.pb(typ[p]);
			return;
		}
		int mid = (l+r)>>1;
		if(x <= mid) query(ls,l,mid,x,y);
		if(y > mid) query(rs,mid+1,r,x,y);
	}
}
int query(int l,int r,int x){
	return lower_bound(all(pos[x]),r+1)-lower_bound(all(pos[x]),l);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&q);
	rep(i,1,n) scanf("%d",&a[i]),pos[a[i]].pb(i);
	seg::build(1,1,n);
	while(q--){
		int l,r; scanf("%d%d",&l,&r);
		ans.clear();
		seg::query(1,1,n,l,r);
		int len = 0;
		for(auto u:ans){
			// printf(?"%d ***\n",u );
			len = max(len,query(l,r,u));
		}
		printf("%d\n",max(len-((r-l+1)-len),1));
	}
	return 0;
}