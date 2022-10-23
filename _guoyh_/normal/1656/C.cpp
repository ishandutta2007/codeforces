# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100005;
int t, n;
int a[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1);
		bool flag1 = false, flag2 = false;
		for (int i = 1; i <= n; i++){
			flag1 |= (a[i] == 1);
			flag2 |= (i - 1 >= 1 && a[i] == a[i - 1] + 1);
		}
		if (!flag1 || !flag2) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}