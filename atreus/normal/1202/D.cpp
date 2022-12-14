#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 15000;

void solve(){
	int n;
	cin >> n;
	if (n <= 100000 - 3){		
		for (int i = 1; i <= n; i++)
			cout << 1;
		cout << 337 << endl;
		return;
	}
//	cout << N + 2 + (n - (7 * N)) / N + (n % N) + 3 << endl;
//	return;
	for (int i = 1; i <= N; i++)
		cout << 1;
	cout << 33;
	while (n >= 7 * N){
		cout << 7;
		n -= N;
	}
	for (int i = 1; i <= n - 6 * N; i++)
		cout << 1;
	cout << 337 << endl;
}

int main(){
	ios_base::sync_with_stdio (false);
	int t;
	cin >> t;
	while (t --){
		solve();
	}
}