#include <iostream>
#include <algorithm>
using namespace std;

pair <pair <int, int>, int> edg[100005];
pair <int, int> ans[100005];

int main() {
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> edg[i].first.first;
		cin >> edg[i].first.second;
		edg[i].second = i + 1;
		edg[i].first.second *= -1;
	}
	sort(edg, edg + m);
	if (m == 1) {
		cout << 1 << " " << 2;
		return 0;
	}
	if (edg[0].first.second == 0 || edg[1].first.second == 0) {
		cout << -1;
		return 0;
	}
	ans[edg[0].second] = {1, 2};
	ans[edg[1].second] = {1, 3};
	int x = 3, y = 2, q = 3;
	for (int i = 2; i < m; i++) {
		if (edg[i].first.second == -1) {
			q++;
			ans[edg[i].second] = {1, q};
		}
		else {
			if (y == 1) {
				x++;
				y = x - 1;	
				if (x > q) {
					cout << -1;
					return 0;
				}
			}
			ans[edg[i].second] = {x, y};
			y--;
			
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;
}