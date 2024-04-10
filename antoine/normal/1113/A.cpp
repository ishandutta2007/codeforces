#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, V;
	cin >> n >> V;

	int curr = 0, ans = 0;
	for (int i = 1; i < n; ++i) {
		while (curr < min(V, n - i)) {
			curr++;
			ans += i;
		}
		curr--;
	}
	cout << ans;
	return 0;
}