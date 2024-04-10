#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	ll res = 0;
	for(int i = 2; i <= n; ++i)
		for(int k = 2; i*k <= n; ++k)
			res += k << 2;
	cout << res << endl;
	return 0;
}