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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		queue<int> o;
		stack<int> z;

		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			if (x == 0) z.push(i);
			else o.push(i);
		}

		int ans = 0;
		while (!o.empty() && !z.empty() && z.top() > o.front()) {
			ans++;
			o.pop();
			z.pop();
		}

		cout << ans << endl;
	}
	return 0;
}