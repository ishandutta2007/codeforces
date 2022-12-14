#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;

int b[maxn];

void solve(){
	int n, k, m;
	cin >> n >> k >> m;
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	if ((n-m) % (k-1) != 0){
		cout << "NO\n";
		return;
	}
	if (n == m){
		cout << "YES\n";
		return;
	}
	for (int i = 1; i <= m; i++){
		if (b[i]-i >= k/2 and (n-b[i]+1)-(m-i+1) >= k/2){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--){
		solve();
	}
}