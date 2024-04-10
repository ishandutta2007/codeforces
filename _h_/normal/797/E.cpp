#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int chunk = 250;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vi a(n);
	trav(x, a) cin >> x;

	auto next = [&](int p, int k){
		return p + a[p] + k;
	};

	vector<vi> dp(chunk, vi(n));
	rep(k,1,chunk) rrep(i,0,n){
		int j = next(i,k);
		dp[k][i] = j>=n ? 1 : 1 + dp[k][j];
	}

	int q;
	cin >> q;
	rep(_,0,q){
		int p,k;
		cin >> p >> k;
		--p;
		if(k < chunk) cout << dp[k][p] << endl;
		else {
			int ans = 0;
			while(p < n){
				++ans;
				p = next(p,k);
			}
			cout << ans << endl;
		}
	}
}