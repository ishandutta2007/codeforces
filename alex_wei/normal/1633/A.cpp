#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	if(n % 7 == 0) cout << n << endl;
	else {
		n -= n % 10;
		for(int j = 0; j < 10; j++)
			if((n + j) % 7 == 0) 
				return cout << n + j << endl, void();
	}
}
int main() {
	int T; cin >> T;
	while(T--) solve();
	return 0;
}