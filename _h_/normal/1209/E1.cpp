#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

int solve(){
	int n, m;
	cin >> n >> m;
	vector<vi> a(n, vi(m));
	rep(i,0,n) rep(j,0,m) cin >> a[i][j];
	vi cmax(m);
	rep(i,0,n) rep(j,0,m) cmax[j] = max(cmax[j], a[i][j]);
	vi dp(1<<n, 0);
	vi perm(m);
	iota(all(perm),0);
	sort(all(perm),[&](int j1, int j2){
		return cmax[j1] > cmax[j2];
	});
	rep(x,0,min(n,m)){
		int j = perm[x];
		vi pre(1<<n);
		rep(msk,0,1<<n) rep(r,0,n){
			int cur = 0;
			rep(i,0,n) if(msk & (1<<i))
				cur += a[(i+r)%n][j];
			pre[msk] = max(pre[msk], cur);
		}
		rrep(a,0, (x==0 ? 1 : (1<<n)) ){
			int rem = (1<<n)-1-a;	
			for(int sub = rem; sub;){
				dp[sub+a] = max(dp[sub+a], dp[a] + pre[sub]);
				sub -= 1;
				sub &= rem;
			}
		}
	}
	return dp.back();
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	rep(_,0,n) cout << solve() << endl;
}