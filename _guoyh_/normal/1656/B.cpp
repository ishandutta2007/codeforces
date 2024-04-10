# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200005;
int t, n, k;
int a[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--){
		cin >> n >> k;
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1);
		bool flag = false;
		for (int i = 1; i <= n; i++){
			int pos = lower_bound(a + i + 1, a + n + 1, k + a[i]) - a;
			flag |= (pos <= n && a[pos] == k + a[i]);
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}