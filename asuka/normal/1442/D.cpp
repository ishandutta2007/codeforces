#include<bits/stdc++.h>
#define int long long
#define N 3015
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
int n,k,t[N],f[20][N],ans;
VI a[N];
void solve(int l,int r,int d){
	if(l == r){
		rep(i,0,min(k,t[l])) ans = max(ans,f[d][k-i]+a[l][i]);
		return;
	}
	int mid = (l+r)>>1;
	memcpy(f[d+1],f[d],sizeof f[d]);
	rep(i,mid+1,r) {
		per(j,0,k-t[i]) f[d+1][j+t[i]] = max(f[d+1][j+t[i]],f[d+1][j]+a[i][t[i]]);
	}
	solve(l,mid,d+1);
	memcpy(f[d+1],f[d],sizeof f[d]);
	rep(i,l,mid) {
		per(j,0,k-t[i]) f[d+1][j+t[i]] = max(f[d+1][j+t[i]],f[d+1][j]+a[i][t[i]]);
	}
	solve(mid+1,r,d+1);
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld%lld",&n,&k);
	rep(i,1,n){
		scanf("%lld",&t[i]); a[i].resize(t[i]+1);
		rep(j,1,t[i]) scanf("%lld",&a[i][j]),a[i][j] += a[i][j-1];
	}
	solve(1,n,0);
	printf("%lld\n",ans);
	return 0;
}