#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int T[n];
		rep(i, n) cin >> T[i];
		sort(T, T+n);
		long long ans=0, p=0, k=0;
		while(p<n) {
			while(k<n && T[k]-T[p]<=2) ++k;
			if(k-p>=3) ans+=(k-p-1)*(k-p-2)/2;
			++p;
		}
		cout << ans << '\n';
	}
}