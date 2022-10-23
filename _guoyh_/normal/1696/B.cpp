# include <bits/stdc++.h>
using namespace std;
int t, n, z;
int a[100005];
int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--){
		cin >> n;
		int cnt0 = 0;
		int cnt1 = 0;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			cnt0 += (a[i] == 0);
			cnt1 += (a[i - 1] == 0 && a[i] != 0);
		}
		if (cnt0 == n) cout << "0\n";
		else if (cnt1 <= 1) cout << "1\n";
		else cout << "2\n";
	}
	return 0;
}