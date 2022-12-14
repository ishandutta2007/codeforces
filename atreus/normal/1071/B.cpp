#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 2e3 + 37;

int n, m;
int dp[maxn][maxn];
queue <pii> q;
bool mark[maxn][maxn];

string s[maxn];

void bfs () {
	int mn = 27;
	while (q.front() != MP (n, n)) {
		queue <pii> p;
		int mn2 = 27;
		while (!q.empty()) {
			auto it = q.front();
			q.pop();
			if ((int)(s[it.F][it.S] - 'a') > mn)
				continue;
			if (it.F != n and !mark[it.F + 1][it.S]) {
				p.push ({it.F + 1, it.S});
				mark[it.F + 1][it.S] = 1;
				mn2 = min (mn2, (int)(s[it.F + 1][it.S] - 'a'));
			}
			if (it.S != n and !mark[it.F][it.S + 1]) {
				p.push ({it.F, it.S + 1});
				mark[it.F][it.S + 1] = 1;
				mn2 = min (mn2, (int)(s[it.F][it.S + 1] - 'a'));
			}
		}
		mn = mn2;
		q = p;
		cout << (char)(mn2 + 'a');
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = " " + s[i];
	}
	
	if (m >= 2 * n - 1) {
		m = 2 * n - 1;
		while (m--) {
			cout << 'a';
		}
		cout << endl;
		return 0;
	}
	
	if (m == 0 and s[1][1] != 'a') {
		q.push ({1, 1});
		cout << s[1][1];
	}
	int sum = 0;
	memset (dp, 63, sizeof dp);
	dp[1][0] = 0;
	for (int i = 1; i <= n; i++) { 
		for (int j = 1; j <= n; j++) {
			dp[i][j] = min (dp[i - 1][j], dp[i][j - 1]) + 1 - (s[i][j] == 'a');
			if (dp[i][j] <= m)
				sum = max (sum, i + j);
		}
	}
	for (int i = 1; i <= sum - 1; i++)
		cout << 'a';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] <= m and sum == i + j) {
				q.push ({i, j});
			}
		}
	}
	bfs ();
	cout << endl;
}