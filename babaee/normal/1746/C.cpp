#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

ll d[MAXN], n, A[MAXN], f[MAXN];

inline int solve() {
	cin >> n;
	priority_queue<pll> pq;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		if (i > 1) {
			d[i] = A[i - 1] - A[i];
			pq.push({d[i], i});
		}
	}

	if (n == 1) return cout << 1 << endl, 0;
	for (int i = n; i > 0; i--) {
		int ind = pq.top().Y;
		pq.pop();
		d[ind] -= i;
		pq.push({d[ind], ind});
		f[i] = ind;
	}

	for (int i = 1; i <= n; i++)
		cout << f[i] << sep;
	cout << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}