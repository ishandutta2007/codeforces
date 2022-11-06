#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int res = 0;
	for(int i = 1; i + 1 < n; ++i) {
		if(a[i-1] && !a[i] && a[i+1]) {
			a[i+1] = 0;
			++res;
		}
	}
	cout << res ;
	return 0;
}