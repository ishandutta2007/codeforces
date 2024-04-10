#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000 + 5;

void solve(){
	int n;
	cin >> n;
	ll m = 0;
	while (n >= 10){
		m += n - (n % 10);
		n = (n / 10) + (n % 10);
	}
	cout << m + n << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		solve();
	}
}