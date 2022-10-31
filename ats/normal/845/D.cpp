#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int t;
	int s;
	vector<int> sl(n + 5);
	vector<int> ol(n + 5);
	sl[0]=100000;
	int st = 0;
	ol[0] = 10000;
	int ot = 0;
	int cs = 0;
	int res = 0;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t == 1) {
			cin >> s;
		}
		if (t == 3) {
			cin >> s;
		}
		if (t == 1) {
			cs = s;
		}else if (t == 2) {
			while (ol[ot] == 0) {
				ot--;
				res++;
			}
		}
		else if (t == 3) {
			st++;
			sl[st] = s;
		}
		else if (t == 4) {
			ot++;
			ol[ot] = 1;
		}
		else if (t == 5) {
			st++;
			sl[st] = 10000000;
		}
		else if (t == 6) {
			ot++;
			ol[ot] = 0;
		}

		while (sl[st] < cs) {
			st--;
			res++;
		}

	}
	cout << res << endl;
	return 0;
}