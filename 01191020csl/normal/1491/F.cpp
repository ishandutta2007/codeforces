#include<bits/stdc++.h>
using namespace std;
int ans[2001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, p = 1, sum;
		cin >> n;
		while (p <= n) {
			cout << '?' << ' ' << 1 << ' ' << n-p << endl << p << endl;
			for (int i = p + 1; i <= n; i++) cout << i << ' ';
			cout << endl;
			cin >> sum;
			if (sum != 0) break;
			++p;
		}
		int l = 1, r = p, mid = (l + r) / 2;
		if (l == r) mid = 0;
		int res = 0;
		for (int i = p + 1; i <= n; i++) {
			cout << '?' << ' ' << 1 << ' ' << mid + 1 << endl << p << endl;
			for (int j = 1; j <= mid; j++) cout << j << ' ';
			cout << i << endl;
			cin >> ans[i], sum -= ans[i];
		}
		if (!sum) l = mid + 1;
		else {
			r = mid;
			for (int i = p + 1; i <= n; i++)
				if (sum > 0) ++ans[i];
				else --ans[i];
		}
		while (l < r) {
			int mid = (l + r) / 2;
			cout << '?' << ' ' << 1 << ' ' << mid-l+1 << endl << p << endl;
			for (int i = l; i <= mid; i++) cout << i << ' ';
			cout << endl;
			cin >> res;
			if (res) r = mid;
			else l = mid + 1;
		}
		vector<int> ret;
		for (int i = 1; i < p; i++)
			if (i != l) ret.push_back(i);
		for (int i = p + 1; i <= n; i++)
			if (!ans[i]) ret.push_back(i);
		cout << '!' << ' ' << ret.size();
		for (int i = 0; i < ret.size(); i++) cout << ' ' << ret[i];
		cout << endl;
	}
}