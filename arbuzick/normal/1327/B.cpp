#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
int sv1[100000], sv2[100000];
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		vector<vector<int>> p(n);
		for (int j = 0; j < n; ++j) {
			sv1[j] = 0;
			sv2[j] = 0;
			int a;
			cin >> a;
			for (int k = 0; k < a; ++k) {
				int pr;
				cin >> pr;
				p[j].push_back(pr);
			}
		}
		int ans1, ans2;
		ans1 = -1;
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < p[j].size(); ++k) {
				if (sv1[p[j][k] - 1] == 0) {
					sv1[p[j][k] - 1] = 1;
					sv2[j] = 1;
					break;
				}
			}
			if (sv2[j] == 0) 
				ans1 = j;
		}
		if (ans1 == -1)
			cout << "OPTIMAL" << endl;
		else {
			for(int j = 0; j < n; ++j)
				if (sv1[j] == 0) {
					ans2 = j;
					break;
				}
			cout << "IMPROVE" << endl;
			cout << ans1 + 1 << ' ' << ans2+1 << endl;
		}
	}
}