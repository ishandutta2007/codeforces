#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 4000 + 10;
const int inf = 2e9;

void solve(){
	string a, b, c;
	cin >> a >> b >> c;
	int n = a.size();
	for (int i = 0; i < n; i++){
		if (a[i] == c[i] or b[i] == c[i])
			continue;
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		solve();
	}
}