#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll a[5009];

bool f(const int k) {
	for(int i = 1; i + k <= n; ++i)
		if(a[i] - a[i-1] != a[i+k] - a[i+k-1])
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	vector<int> res;

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for(int k = 1; k <= n; ++k) {
		if(f(k))
			res.push_back(k);
	}

	cout << res.size() << endl;
	for (auto &&x : res)
		cout << x << ' ';
	return 0;
}