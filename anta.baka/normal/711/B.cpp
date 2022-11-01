#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

int main() {
	int n, ia, ja;
	cin >> n;
	ll tsum;
	vector<vector<ll>> a(n, vector<ll>(n));
	for(int i = 0; i < n; i++) {
		bool here = false;
		ll sum = 0;
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
			sum += a[i][j];
			if(a[i][j] == 0) {
				ia = i; ja = j;
				here = true;
			}
		}
		if(!here)
			tsum = sum;
	}
	if(n == 1) {
		cout << 1;
		return 0;
	}
	ll asum = 0;
	for(int j = 0; j < n; j++)
		asum += a[ia][j];
	a[ia][ja] = tsum - asum;
	if(a[ia][ja] < 1) {
		cout << -1;
		return 0;
	}
	ll d1 = 0, d2 = 0;
	for(int i = 0; i < n; i++) {
		d1 += a[i][i]; d2 += a[i][n-i-1];
		ll row = 0, col = 0;
		for(int j = 0; j < n; j++) {
			row += a[i][j];
			col += a[j][i];
		}
		if(row != tsum || col != tsum) {
		cout << -1;
		return 0;
	}
	}
	if(d1 != tsum || d2 != tsum) {
		cout << -1;
		return 0;
	}
	cout << a[ia][ja];
}