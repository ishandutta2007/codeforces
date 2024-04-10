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
		rep(i, n/2) {
			cout << T[i] << " " << T[n-i-1] << " ";
		}
		if(n%2==1) cout << T[n/2] << " ";
		cout << '\n';
	}
}