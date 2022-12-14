#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 3e5 + 10;
const ll mod = 998244353;

int a[maxn];

void solve() {
	int n;
	cin >> n;
	ll answer = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 2; i <= n - 1; i++)
		answer += a[i];
	if (n == 3 and a[2] % 2 == 1) {
		cout << -1 << '\n';
		return;
	}
	if (*max_element(a + 2, a + n) == 1) {
		cout << -1 << '\n';
		return;
	}
	int cnt = 0;
	for (int i = 2; i <= n - 1; i++)
		if (a[i] & 1)
			cnt++;
	answer = cnt;
	for (int i = 2; i <= n - 1; i++)
		answer += a[i]/2;
	cout << answer << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int tc;
	cin >> tc;
	while (tc --){
		solve();
	}
}