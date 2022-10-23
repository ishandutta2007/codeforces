# include <bits/stdc++.h>
using namespace std;
int t, n, z;
int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--){
		cin >> n >> z;
		int mx = 0;
		for (int i = 1; i <= n; i++){
			int u;
			cin >> u;
			mx = max(mx, u | z);
		}
		cout << mx << '\n';
	}
	return 0;
}