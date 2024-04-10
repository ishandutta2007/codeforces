#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, l=0, a=0;
		cin >> n; n*=2;
		int T[n];
		rep(i, n) cin >> T[i];
		while(l<n && a<n/2-1) {
			while(l<n && T[l]%2==0) ++l;
			if(l==n) break;
			++l;
			int ans=l;
			while(l<n && T[l]%2==0) ++l;
			if(l==n) break;
			++l;
			++a;
			cout << ans << " " << l << '\n';
		}
		l=0;
		while(a<n/2-1) {
			while(l<n && T[l]%2) ++l;
			++l; ++a;
			int ans=l;
			while(l<n && T[l]%2) ++l;
			++l;
			cout << ans << " " << l << '\n';
		}
	}
}