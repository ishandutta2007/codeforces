#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back
#define min(a, b) (a < b ? a : b)
#define d(x1, x2) abs(x1 - x2)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
	int n, a;
	cin >> n >> a;
	if(n == 1) {
		cout << 0;
		return 0;
	}
	vector<int> x(n);
	for(int i = 0; i < n; i++)
		cin >> x[i];
	sort(all(x));
	cout << min(min(d(a, x[0]) + d(x[0], x[n-2]), d(a, x[n-2]) + d(x[n-2], x[0])),
				min(d(a, x[1]) + d(x[1], x[n-1]), d(a, x[n-1]) + d(x[n-1], x[1])));
}