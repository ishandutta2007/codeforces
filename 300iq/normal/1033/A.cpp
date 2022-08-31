#include <bits/stdc++.h>

using namespace std;

bool used[2000][2000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, x, y, fx, fy, cx, cy;
    cin >> t >> fx >> fy >> x >> y >> cx >> cy;
    while (true) {
    	int i = fx, j = fy;
    	while (j <= t) {
			used[i][j] = 1;
			j++;
    	}
    	i = fx; j = fy;
		while (j > 0) {
			used[i][j] = 1;
			j--;
    	}
		i = fx; j = fy;
    	while (i <= t) {
			used[i][j] = 1;
			i++;
    	}
		i = fx; j = fy;
    	while (i > 0) {
			used[i][j] = 1;
			i--;
    	}
		i = fx; j = fy;
    	while (j <= t && i <= t) {
			used[i][j] = 1;
			j++;
			i++;
    	}
		i = fx; j = fy;
    	while (j <= t && i > 0) {
			used[i][j] = 1;
			j++;
			i--;
    	}
    		i = fx; j = fy;
    	while (i <= t && j > 0) {
			used[i][j] = 1;
			j--; i++;
    	}
    		i = fx; j = fy;
    	while (j > 0 && i > 0) {
			used[i][j] = 1;
			j--; i--;
    	}
    	break;
    }
    queue <pair <int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
		auto to = q.front();
		//cout << to.first << ' ' << to.second << endl;
		if (to.first == cx && to.second == cy) {
			cout << "YES";
			return 0;
		}
		q.pop();
		used[to.first][to.second] = 1;
		if (to.first + 1 <= t && !used[to.first + 1][to.second]) {
			q.push({to.first + 1, to.second});
            used[to.first + 1][to.second] = 1;
		}
		if (to.first - 1 > 0 && !used[to.first - 1][to.second]) {
			q.push({to.first - 1, to.second});
            used[to.first - 1][to.second] = 1;
		}
		if (to.second + 1 <= t &&!used[to.first][to.second + 1]) {
			q.push({to.first, to.second + 1});
            used[to.first][to.second + 1] = 1;
		}
		if (to.second - 1 > 0 && !used[to.first][to.second - 1]) {
			q.push({to.first, to.second -1});
			used[to.first][to.second - 1] = 1;
		}
		if (to.first + 1 <= t && to.second + 1 <= t&& !used[to.first + 1][to.second + 1]) {
			q.push({to.first + 1, to.second + 1});
            used[to.first + 1][to.second + 1] = 1;
		}
		if (to.first - 1 > 0 && to.second + 1 <= t &&!used[to.first - 1][to.second + 1]) {
			q.push({to.first - 1, to.second + 1});
            used[to.first - 1][to.second + 1] = 1;
		}
		if (to.first + 1 <= t && to.second - 1 > 0 && !used[to.first + 1][to.second - 1]) {
			q.push({to.first + 1, to.second - 1});
            used[to.first + 1][to.second - 1] = 1;
		}
		if (to.first - 1 > 0 && to.second - 1 > 0 && !used[to.first - 1][to.second - 1]) {
			q.push({to.first - 1, to.second - 1});
            used[to.first - 1][to.second - 1] = 1;
		}
    }
    cout << "NO";

}