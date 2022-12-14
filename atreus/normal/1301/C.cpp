#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 1e5 + 10;
const int inf = 2e9;

int a[maxn];

void solve(){
	int n, m;
	cin >> n >> m;
	int sum = n - m;
	int t = m + 1;
	int A = sum / t, B = (sum + t - 1) / t;
	int nB = sum % t;
	int nA = t - nB;
	cout << 1ll * n * (n+1) / 2 - (1ll * nA * A * (A+1) / 2 + 1ll * nB * B * (B+1) / 2) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		solve();
	}
}