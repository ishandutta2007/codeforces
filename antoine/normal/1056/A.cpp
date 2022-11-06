#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, r;
	cin >> n >> r;

vector<int> v;
	while (r--) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	for (int rep = 0; rep < n - 1; ++rep) {
		cin >> r;
		set<int> t;
		while(r--) {
			int x;
			cin >> x;
			t.insert(x);
		}
		v.erase(remove_if(v.begin(), v.end(), [&](const int &x) {
			return !t.count(x);
		}), v.end());
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(auto &&x : v)
		cout << x << ' ';
	return 0;
}