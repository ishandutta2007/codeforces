#include <bits/stdc++.h>
using namespace std;


const int N = 83, X = 6, inf = 1000 * 1000 * 1000 + 7;
int n, k, ans = inf;


bool mark1[N];
bool mark2[N];
int a[N][N];
vector <int> vec;
vector <vector <int> > v;
int dp[N][N];
vector <pair <int, int> > b[N][N];
int c[N];

void bt(int x) {
//	cout << "73 " << vec.size() << endl;
	if (vec.size() == k / 2) {
		int s = 0;
		vec.push_back(1);
	//	for (auto x : vec) {
	//		cout << x << " ";
	//	}
		for (int i = 0; i + 1 < vec.size(); i++) {
			int x = 0;
			while (x < b[vec[i]][vec[i + 1]].size() && c[b[vec[i]][vec[i + 1]][x].second]) {
				x++;
			}
			if (x < b[vec[i]][vec[i + 1]].size()) {
				s += b[vec[i]][vec[i + 1]][x].first;
			}
			else {
				s = inf;
				break;
			}
		}
	//	cout << endl << s << endl;
		ans = min(ans, s);
		vec.pop_back();
		
		
		return;
	}
	for (int i = 1; i <= n; i++) {
		c[i]++;
		vec.push_back(i);
		bt(i);
		vec.pop_back();
		c[i]--;	
	}
	
}
int main() {
	ios :: sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

//	cout << v.size() << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (i != k && j != k) {
					b[i][j].push_back({a[i][k] + a[k][j], k});
				}
			}
			sort(b[i][j].begin(), b[i][j].end());
		}
	}
	c[1] = 1;
	vec.push_back(1);
	bt(1);
	cout << ans;
	return 0;
}