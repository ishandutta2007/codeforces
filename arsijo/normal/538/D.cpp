#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define ll long long
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define print(ar, n, m)	for(int i = 0; i < n; i++){ for(int j = 0; j < m; j++) cout << ar[i][j]; cout << endl; }
#define ld long double
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1e9+7
const int MAX = 1e9;
const ld E = 1e-7;
const char C = 'o', X = 'x', T = '.';

int n;
char ar[50][50], ans[101][101];
vector<pair<int, int> > v;
bool bol[50][50];
bool check(int x, int y) {
	for (int i = 0; i < (int) v.size(); i++) {
		int x1 = v[i].first + x, y1 = v[i].second + y;
		if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= n)
			continue;
		if (ar[x1][y1] == T)
			return false;
	}
	return true;
}

void make(int x, int y) {
	//cout << "tr " << x << " " << y << endl;
	//fflush(stdout);
	for (int i = 0; i < (int) v.size(); i++) {
		if (check(x - v[i].first, y - v[i].second)) {
			for (int j = 0; j < (int) v.size(); j++) {
				int x1 = v[j].first + (x - v[i].first), y1 = v[j].second + (y - v[i].second);
				if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= n)
					continue;
				//if (!bol[x1][y1])
				//	cout << "OK " << x1 << " " << y1 << endl;
				bol[x1][y1] = true;
			}
			//cout << -x + v[i].first + n << " " << -y + v[i].second + n << endl;
			//fflush(stdout);
			ans[x - v[i].first + n - 1][y - v[i].second + n - 1] = X;
			return;
		}
	}
	cout << "NO";
	exit(0);
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> ar[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (ar[i][j] == C)
				v.push_back(make_pair(i, j));

	for (int i = 0; i <= n * 2; i++)
		for (int j = 0; j <= n * 2; j++)
			ans[i][j] = T;
	ans[n - 1][n - 1] = C;

	ms(bol);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (ar[i][j] == X && !bol[i][j])
				make(i, j);

	cout << "YES" << endl;

	for (int i = 0; i < n * 2 - 1; i++) {
		for (int j = 0; j < n * 2 - 1; j++)
			cout << ans[i][j];
		cout << endl;
	}

}