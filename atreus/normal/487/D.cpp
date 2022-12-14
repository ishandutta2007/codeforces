#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <bitset>
#include <set>
#include <algorithm>
#include <iomanip>
#include <fstream>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e5 + 100;
const int SQRT = 400;

int n, m, q;

pii dp[maxn][12];
string s[maxn];

bool mark[20];
int move (int x, int y) {
	memset (mark, 0, sizeof mark);
	while (y != 0 and y != m + 1) {
		if (mark[y])
			return -1;
		mark[y] = 1;
		if (s[x][y] == '>')
			y ++;
		else if (s[x][y] == '<')
			y --;
		else
			return y;
	}
	return y;
}

void find_dp (int i, int j) {
	int x = move (i, j);
	if (x == 0)
		dp[i][j] = {i, 0};
	else if (x == m + 1)
		dp[i][j] = {i, m + 1};
	else if (x == -1)
		dp[i][j] = {-1, -1};
	else {
		if (i % SQRT == 0 or i == 1) 
			dp[i][j] = {i - 1, x};
		else
			dp[i][j] = dp[i - 1][x];
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = " " + s[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			find_dp (i, j);
		} 
	}
/*	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << dp[i][j].F << " " << dp[i][j].S << " - ";
		cout << endl;
	}
*/
	for (int i = 1; i <= q; i++) {
		char type;
		cin >> type;
		if (type == 'C') {
			int x, y;
			char c;
			cin >> x >> y >> c;
			s[x][y] = c;
			for (int i = x; i / SQRT == x / SQRT and i <= n; i++)
				for (int j = 1; j <= m; j++)
					find_dp (i, j);
//			for (int i = 1; i <= n; i++) {
//				for (int j = 1; j <= m; j++)
//					cout << dp[i][j].F << " " << dp[i][j].S << " - ";
//				cout << endl;
//			}
		}
		else {
			int x, y;
			cin >> x >> y;
			while (x > 0 and y > 0 and y <= m) {
				pii nex = dp[x][y];
				x = nex.F, y = nex.S;
			}
			cout << x << " " << y << endl;
		}
	}
}