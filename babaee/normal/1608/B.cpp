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
		int a, b, n;
		cin >> n >> a >> b;

		vector<int> vec;
		bool flag = false;
		if (b > a) swap(a, b), flag = true;

		if (a + b > n - 2 || a > b + 1) {
			cout << -1 << endl;
			continue;
		}

		int l = 2, r = n;
		vec.push_back(1);
		for (int i = 2; i <= n && (a || b); i++) {
			if (i & 1) vec.push_back(l++), b--;
			else vec.push_back(r--), a--;
		}
		
		if (vec.back() < l)
			for (int i = l; i <= r; i++)
				vec.push_back(i);
		else
			for (int i = r; i >= l; i--)
				vec.push_back(i);

		if (flag)
			for (int& e : vec)
				e = n + 1 - e;
		for (int e : vec) cout << e << sep;
		cout << endl;
	}
	return 0;
}