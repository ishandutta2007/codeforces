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
int t,n,p[N],L[N],R[N],f[N],from[N];
namespace Min{
	#define ls (p<<1)
	#define rs (p<<1|1)
	int val[N<<2];
	void pushup(int p){val[p] = min(val[ls],val[rs]);}
	void build(int p,int l,int r){
		if(l==r) return val[p] = inf,void();
		int mid = (l+r)>>1;
		build(ls,l,mid); build(rs,mid+1,r);
		pushup(p);
	}
	void change(int p,int l,int r,int pos,int v){
		if(l == r) return val[p] = min(val[p],v),void();
		int mid = (l+r)>>1;
		if(pos <= mid) change(ls,l,mid,pos,v);
		else change(rs,mid+1,r,pos,v);
		pushup(p);
	}
	int query(int p,int l,int r,int x,int y){
		if(x <= l && r <= y) return val[p];
		int mid = (l+r)>>1;
		int res = inf;
		if(x <= mid) res = min(res,query(ls,l,mid,x,y));
		if(y > mid) res = min(res,query(rs,mid+1,r,x,y));
		return res;
	}
}
namespace Max{
	int f[N][22],Log[N];
	void init(){
		Log[0] = -1;
		rep(i,2,300000) Log[i] = Log[(i>>1)]+1;
	}
	void build(){
		rep(i,1,n) f[i][0] = R[i];
		rep(j,1,19) rep(i,1,n) if(i+(1<<j)-1 <= n){
			f[i][j] = max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
	}
	int query(int l,int r){
		if(l > r) return 0;
		int len = Log[r-l+1];
		return max(f[l][len],f[r-(1<<len)+1][len]);
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&t); Max::init();
 	while(t--){
 		scanf("%d",&n);
 		rep(i,1,n) scanf("%d",&p[i]);
 		rep(i,0,n) f[i] = 0,from[i] = 0;
 		rep(i,1,n) L[i] = max(1,i-p[i]);
 		rep(i,1,n) R[i] = min(n,i+p[i]);
 		Max::build();
 		// cerr << "test " << query
 		Min::build(1,0,n);
 		Min::change(1,0,n,0,0);
 		rep(i,1,n){
 			int l = L[i]-1;
 			int pos = Min::query(1,0,n,l,n);
 			// printf("i: %d pos: %d\n",i,pos);
 			if(pos != inf){
 				int r = Max::query(pos+1,i-1);
 				r = max(r,i-1);
 				if(r > f[i]) f[i] = r,from[i] = pos;
 			}
 			if(f[i-1] >= i && max(f[i-1],R[i]) > f[i]) f[i] = max(f[i-1],R[i]),from[i] = -1;
 			if(f[i-1] > f[i]) f[i] = f[i-1],from[i] = -1;
 			// printf("dp: %d\n",f[i]);
 			Min::change(1,0,n,f[i],i);
 		}
 		if(f[n] != n) puts("NO");
 		else{
 			puts("YES");
 			int u = n; string ans = "";
 			while(u > 0){
 				if(from[u] == -1) ans += 'R',u--;
 				else{
 					ans += 'L';
 					rep(i,from[u]+1,u-1) ans += 'R';
 					u = from[u];
 				}
 			}
 			reverse(all(ans)); cout << ans << endl;
 		}
 	}
	return 0;
}
/*
1
7
2 1 1 1 1 1 0
*/