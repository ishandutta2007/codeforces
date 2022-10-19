#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
const long long INF=1e18+7, ZERO=0;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, q;
		cin >> n >> q;
		long long T[n], dp[n][2], ma[2];
		rep(i, n) cin >> T[i];
		dp[0][0]=T[0]; ma[0]=T[0]; ma[1]=-INF;
		rep(i, n-1) {
			dp[i+1][0]=max(ma[1], ZERO)+T[i+1];
			dp[i+1][1]=ma[0]-T[i+1];
			ma[0]=max(ma[0], dp[i+1][0]);
			ma[1]=max(ma[1], dp[i+1][1]);
		}
		cout << max(ma[0], ma[1]) << '\n';
	}
}