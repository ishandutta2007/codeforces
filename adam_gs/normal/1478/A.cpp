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
		int n;
		cin >> n;
		int T[n];
		rep(i, n) cin >> T[i];
		int l=1, ans=1;
		rep(i, n-1) {
			if(T[i+1]!=T[i]) {
				l=0;
			}
			++l;
			ans=max(ans, l);
		}
		cout << ans << '\n';
	}
}