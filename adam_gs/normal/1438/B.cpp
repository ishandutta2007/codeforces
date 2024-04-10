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
		bool a=false;
		rep(i, n-1) if(T[i]==T[i+1]) a=true;
		if(a==true) cout << "YES"; else cout << "NO";
		cout << '\n';
	}
}