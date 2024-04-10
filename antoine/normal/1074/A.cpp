#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// http://codeforces.com/contest/1074/problem/A

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v1(n);
	for(int i = 0; i < n; ++i)
		cin >> v1[i];

	sort(v1.begin(), v1.end());
	v1.push_back((int)1e9);


	vector<int> v2;
	for(int i = 0; i < m; ++i) {
		int x1, x2, y;
		cin >> x1 >> x2 >> y;
		if(x1 != 1) continue;
		v2.push_back(x2);
	}

	sort(v2.begin(), v2.end());

	int ans = (int)1e8;
	for(int i = 0, j = 0; i < (int)v1.size(); ++i) {
		while(j < (int)v2.size() && v2[j] < v1[i])
			++j;
		ans = min(ans, i + (int)v2.size() - j);
	}
	cout << ans << endl;
	return 0;
}