#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
#define min(a, b) a<b?a:b
#define max(a, b) a>b?a:b

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0);
	int n, d, h;
	cin >> n >> d >> h;
	if(h < (d + 1) / 2 || d == 1 && n > 2) {
		cout << -1;
		return 0;
	}
	for(int i = 1; i < h; i++)
		cout << i + 1 << ' ' << i + 2 << "\n";
	cout << h + 1 << ' ' << 1 << "\n";
	bool one = false;
	if(h < d) {
		cout << 1 << ' ' << h + 2 << "\n";
		one = true;
	}
	for(int i = h + 1; i < d; i++)
		cout << i + 1 << ' ' << i + 2 << "\n";
	for(int i = d + 1; i < n; i++)
		cout << i + 1 << ' ' << (one ? 1 : h + 1) << "\n";
}