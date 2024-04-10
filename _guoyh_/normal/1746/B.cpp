# include <bits/stdc++.h>
using namespace std;
const int MAXN = 100051;
int T, n, k;
int a[MAXN], b[MAXN], s[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--){
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			s[i] = s[i - 1] + a[i];
		}
		if (s[n] == 0){
			cout << "0\n";
			continue;
		}
		int ans = s[n];
		for (int i = 0; i < n; i++){
			int c1 = s[i], c2 = (n - i) - (s[n] - s[i]);
			ans = min(ans, c1 + max(0, c2 - c1));
		}
		cout << ans << '\n';
	}
	return 0;
}