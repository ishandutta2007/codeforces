#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const long long INF = 1e18 + 1;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
   	int n, m, k, q;
   	cin >> n >> m >> k >> q;
   	vector <vector<int>> a(n + 1);
   	int max_row = -1;
   	int min_row = n + 1;
   	vector <int> rows;
   	for (int i = 0; i < k; i++) {
   		int r, c;
   		cin >> r >> c;
   		a[r].pb(c);
   		max_row = max(max_row, r);
   		min_row = min(min_row, r);
   		rows.pb(r);
   	}
   	sort(rows.begin(), rows.end());
   	vector <int> b(q);
   	for (auto &c : b) {
   		cin >> c;
   	}
   	sort(b.begin(), b.end());
   	long long up = max_row - 1;
   	for (auto &c : a) {
   		sort(c.begin(), c.end());
   	}
   	vector <int> left(n + 1, -1), right(n + 1, -1);
   	for (int i = 1; i <= n; i++) {
   		if (a[i].size() == 0) {
   			continue;
   		}
   		left[i] = a[i][0];
   		right[i] = a[i].back();
   	}
   	vector <vector<pair<long long, int>>> pos(n + 1, vector <pair<long long, int>>(4));
   	for (auto &c : pos) {
   		for (auto &l : c) {
   			l = {INF, -1};
   		}
   	}
   	for (auto &r : rows) {
   		int left_left = lower_bound(b.begin(), b.end(), left[r]) - b.begin() - 1;
   		int left_right = lower_bound(b.begin(), b.end(), left[r]) - b.begin();
   		int right_left = lower_bound(b.begin(), b.end(), right[r]) - b.begin() - 1;
   		int right_right = lower_bound(b.begin(), b.end(), right[r]) - b.begin();
   		if (left_left != -1) {
   			pos[r][0] = {INF, b[left_left]};
   		}
   		if (left_right != b.size()) {
   			pos[r][1] = {INF, b[left_right]};
   		}
   		if (right_left != -1) {
   			pos[r][2] = {INF, b[right_left]};
   		}
   		if (right_right != b.size()) {
   			pos[r][3] = {INF, b[right_right]};
   		}
   	}
   	vector <long long> min_to_right(n + 1, INF), min_to_left(n + 1, INF);
   	
   	if (min_row != 1) {
   		min_to_right[rows[0]] = b[0] - 1 + abs(left[rows[0]] - b[0]) + right[rows[0]] - left[rows[0]];
   		min_to_left[rows[0]] = b[0] - 1 + abs(right[rows[0]] - b[0]) + right[rows[0]] - left[rows[0]];
   	} else {
   		min_to_left[1] = right[1] - 1 + (right[1] - left[1]);
   		min_to_right[1] = right[1] - 1;
   	}
   	for (int i = 0; i < rows.size() - 1; i++) {
   		int r = rows[i];
   		if (pos[r][0].second != -1) {
   			pos[r][0].first = min_to_left[r] + left[r] - pos[r][0].second;
   		}
   		if (pos[r][1].second != -1) {
   			pos[r][1].first = min_to_left[r] + pos[r][1].second - left[r];
   		}
   		if (pos[r][2].second != -1) {
   			pos[r][2].first = min_to_right[r] + right[r] - pos[r][2].second;
   		}
   		if (pos[r][3].second != -1) {
   			pos[r][3].first = min_to_right[r] + pos[r][3].second - right[r];
   		}
   		for (int j = 0; j < 4; j++) {
   			if (pos[r][j].second == -1) {
   				continue;
   			}
   			int r1 = rows[i + 1];
   			min_to_left[r1] = min(min_to_left[r1], pos[r][j].first + abs(right[r1] - pos[r][j].second) + right[r1] - left[r1]);
   			min_to_right[r1] = min(min_to_right[r1], pos[r][j].first + abs(left[r1] - pos[r][j].second) + right[r1] - left[r1]);
   		}
   	}
   	cout << up + min(min_to_right[max_row], min_to_left[max_row]);
    return 0;
}