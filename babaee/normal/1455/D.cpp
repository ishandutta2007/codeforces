#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, x;
int A[MAXN];

int solve() {
	cin >> n >> x;
	int cnt = 0;
	for (int i = 0; i < n; i++) cin >> A[i];
	while (!is_sorted(A, A + n)) {
		int ind = INF;
		for (int i = 0; i < n; i++)
			if (A[i] > x) ind = min(ind, i);
		if (ind == INF) return cout << -1 << endl, 0;
		swap(A[ind], x);
		cnt++;
	}

	cout << cnt << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}