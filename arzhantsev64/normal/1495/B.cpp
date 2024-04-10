#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long

int max_up = 0;
int max_down = 0;
int max_up_cnt = 0;
int max_down_cnt = 0;

int max_up_i = 0;
int max_down_i = 0;

int x;
int last = 0;
int len = 0;

void update(int i) {
	// cout << "UPDATE " << i << ' ' << last << endl;
	if (last == 1) {
		if (len > max_up) {
			max_up = len;
			max_up_cnt = 1;
			max_up_i = i;
		} else if (len == max_up) {
			max_up_cnt++;
		}
	}
	if (last == 2) {
		if (len > max_down) {
			max_down = len;
			max_down_cnt = 1;
			max_down_i = i;
		} else if (len == max_down) {
			max_down_cnt++;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	cin >> x;
	for (int i = 0; i < n - 1; ++i) {
		int x0 = x;
		cin >> x;
		if (x > x0) {
			if (last == 1) {
				len++;
			} else {
				update(i);
				last = 1;
				len = 1;
			}
		} else if (x < x0) {
			if (last == 2) {
				len++;
			} else {
				update(i);
				last = 2;
				len = 1;
			}
		}
	}
	update(n - 1);

	// cout << max_up << endl;
	// cout << max_up_cnt << endl;
	// cout << max_up_i << endl;

	// cout << max_down << endl;
	// cout << max_down_cnt << endl;
	// cout << max_down_i << endl;

	if (max_up == max_down && max_up % 2 == 0 && max_down_i - max_up_i == max_up && max_up_cnt == 1 && max_down_cnt == 1) {
		cout << "1\n";
	} else {
		cout << "0\n";
	}

	return 0;
}