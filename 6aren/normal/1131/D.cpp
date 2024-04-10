#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 5;

int n, m;

pair<int, int> val[N];

int ngay1[N], ngay2[N], ngay[2][N];

string s[N];

struct Dish {
	int val;
	pair <int, int> id;
};

vector <Dish> nen;

bool cmp(Dish a, Dish b) {
	return a.val < b.val;
}


int main() {
	//ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < n; i++) {
		int cntge = 0, cnte = 0, cntl = 0;
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '>') cntge++;
			else if (s[i][j] == '=') cnte++;
			else cntl++;
		}
		val[i].first = cntge * 1001 * 1001 + cnte * 1001 + cntl;
		val[i].second = i;
	}

	sort(val, val + n);
	int surplus = 0;
	ngay1[val[0].second] = 1 * 2000;
	for (int i = 0; i < n; i++) {
		if (val[i].first == val[i - 1].first) {
			surplus++;
		}
		ngay1[val[i].second] = (i + 1 - surplus) * 2000;
	}

	for (int i = 0; i < m; i++) {
		int maxi = 1e9, mini = 0, equa = 0;
		for (int j = 0; j < n; j++) {
			if (s[j][i] == '>') {
				maxi = min(maxi, ngay1[j] - 1);
			} else if (s[j][i] == '=') {
				if (equa != 0 && equa != ngay1[j]) {
					return cout << "No", 0;
				}
				maxi = min(maxi, ngay1[j]);
				mini = max(mini, ngay1[j]);
				equa = ngay1[j];
			} else {
				mini = max(mini, ngay1[j] + 1);
			}
		}
		if (maxi == equa && mini == equa) {
			ngay2[i] = equa;
		} else if (maxi >= equa && equa >= mini) {
			ngay2[i] = mini;
		} else if (equa == 0 && maxi >= mini) {
			ngay2[i] = mini;
		} else {
			return cout << "No", 0;
		}
	}
	for (int i = 0; i < n; i++) {
		Dish u;
		u.val = ngay1[i];
		u.id = make_pair(0, i);
		nen.push_back(u);
	}

	for (int i = 0; i < m; i++) {
		Dish u;
		u.val = ngay2[i];
		u.id = make_pair(1, i);
		nen.push_back(u);
	}

	sort(nen.begin(), nen.end(), cmp);

	ngay[nen[0].id.first][nen[0].id.second] = 1;
	surplus = 0;
	for (int i = 1; i < nen.size(); i++){
		if (nen[i].val == nen[i-1].val) {
			surplus++;
		}
		ngay[nen[i].id.first][nen[i].id.second] = i - surplus + 1;
	}
	cout << "Yes" << endl;
	for (int i = 0; i < n; i++) {
		cout << ngay[0][i] << " ";
	}
	cout << endl;
	for (int i = 0; i < m; i++) {
		cout << ngay[1][i] << " ";
	}
	return 0;
}