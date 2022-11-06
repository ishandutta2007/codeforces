#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int occ[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++occ[x % k];
	}
	int ans = occ[0] / 2;
	for (int i = 1; i < k - i; ++i)
		ans += min(occ[i], occ[k - i]);
	if (!(k & 1))
		ans += occ[k / 2] / 2;
	cout << ans*2;
	return 0;
}