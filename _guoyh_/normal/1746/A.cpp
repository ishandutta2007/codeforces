# include <bits/stdc++.h>
using namespace std;
const int MAXN = 100051;
int T, n, k;
int a[MAXN], b[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--){
		cin >> n >> k;
		bool flg = false;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			flg |= a[i];
		}
		if (flg) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}