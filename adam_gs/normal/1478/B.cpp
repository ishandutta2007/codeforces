#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
const int LIM=1e5+7, MOD=1e9+7;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int q, d;
		cin >> q >> d;
		int T[q], dp[100], p=d;
		rep(i, 100) dp[i]=0;
		rep(i, q) cin >> T[i];
		rep(i, 10) {
			dp[p]=1;
			p+=10;
		}
		for(int i=1; i<100; ++i) {
			if(!dp[i]) {
				for(int j=i-1; j; --j) {
					if(dp[j] && dp[i-j]) {
						dp[i]=1;
						break;
					}
				}
			}
		}
		rep(i, q) {
			if(T[i]>=10*d) {
				cout << "YES";
			} else {
				cout << (dp[T[i]]?"YES":"NO");
			}
			cout << '\n';
		}
	}
}