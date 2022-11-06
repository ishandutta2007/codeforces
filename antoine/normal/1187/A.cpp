#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	while(t--) {
		int n,s,t;
		cin >> n >> s >>t;
		cout << max(n-s, n-t) + 1 << '\n';
	}
	return 0;
}