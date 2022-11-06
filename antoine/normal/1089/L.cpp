#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;
	unordered_map<int, vector<int>> mp;

	{
		vector<int> a(n), b(n);
		for (int &x : a)
			cin >> x;
		for (int &x : b)
			cin >> x;

		for (int i = 0; i < n; ++i) {
			mp[a[i]].push_back(b[i]);
		}
	}

	vector<int> v;
	for (auto &&x : mp) {
		nth_element(x.second.begin(), x.second.end() - 1, x.second.end());
		v.insert(v.end(), x.second.begin(), x.second.end() - 1);
	}

	const int m = k - (int) mp.size();

	cerr << m << endl;
	assert((int )v.size() >= m);
	nth_element(v.begin(), v.begin() + m, v.end());
	cout << accumulate(v.begin(), v.begin() + m, 0LL);

	return 0;
}