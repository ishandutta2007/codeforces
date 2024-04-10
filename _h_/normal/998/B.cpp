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

const int inf = 200;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, b;
	cin >> n >> b;

	vi a(n);

	trav(x, a) cin >> x;

	vi pre(n+1);
	rep(i,0,n) pre[i+1] = pre[i] + (a[i]%2 ? 1 : -1);

	vector<vi> dp(n+1, vi(n+1, inf));
	
	dp[0][0] = 0;

	rep(i,0,n){
		int cost = i==0 ? 0 : abs(a[i]-a[i-1]);
		rep(j,i+1,n+1){
			if(pre[i] == pre[j]){
				rep(k,0,n)
					dp[j][k+1] = min(dp[j][k+1],
						dp[i][k] + cost);
			}
		}
	}

	int ans = -1;

	rep(k,0,n+1) if(dp[n][k] <= b) ans = max(ans, k);

	cout << ans-1 << endl;
}