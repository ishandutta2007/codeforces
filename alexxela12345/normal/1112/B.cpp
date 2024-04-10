#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
	cin >> a[i];
    }
    vector<pair<int, pair<int, int>>> workers(k, {-1, {-1, -1}});
    int cur_test_ind = 0;
    int cur_time = 0;
    int ended = 0;
    vector<int> is_interesting(n, 0);
    int working = 0;
    while (cur_test_ind < n || working > 0) {
	int will_end = 0;
	for (int i = 0; i < k; i++) {
	    if (workers[i].first == -1 && cur_test_ind < n) {
		workers[i].first = cur_test_ind;
		workers[i].second.first = cur_time + a[cur_test_ind++];
		workers[i].second.second = 1;
		working++;
	    }
	    if (workers[i].second.first == cur_time + 1) {
		will_end++;
	    }
	}
	int cur_p = (200 * ended + n) / (2 * n);
	for (int i = 0; i < k; i++) {
	    if (workers[i].first != - 1 && cur_p == workers[i].second.second) {
		is_interesting[workers[i].first] = 1;
	    }
	}
	cur_time++;
	for (int i = 0; i < k; i++) {
	    workers[i].second.second++;
	    if (workers[i].second.first == cur_time) {
		workers[i] = {-1, {-1, -1}};
		working--;
		ended++;
	    }
	}
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
	ans += is_interesting[i];
    }
    cout << ans << endl;
    return 0;
}