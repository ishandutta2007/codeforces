# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100051;
int T, n, k;
ll a[MAXN], s[MAXN];
bool chk(){
	a[n + 1] = 1e9;
	for (int i = n - k + 2; i <= n; i++){
		a[i] = s[i] - s[i - 1];
		if (i > n - k + 2 && a[i] < a[i - 1]) return false;
	}
	return a[n - k + 2] * (n - k + 1) >= s[n - k + 1];
}
int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--){
		cin >> n >> k;
		for (int i = n - k + 1; i <= n; i++) cin >> s[i];
		if (chk()) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}