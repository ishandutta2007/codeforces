#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <ctime>
#include <utility>

#pragma GCC optimize("O3")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi1;
typedef vector<vi1> vi2;
typedef vector<ll> vll1;
typedef vector<vll1> vll2;

const int inf = 1e9;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define all(v) v.begin(), v.end()

char a[50][50], b[50][50];
int n, m;
vector<pair<int, int>> ans;

void changeD(int x, int y);
void changeL(int x, int y);

int main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> b[i][j];
	for (int i = n - 1; i + 1; --i)
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == b[i][j]) continue;
			if (a[i][j] == 'D') changeD(i, j);
			else changeL(i, j);
		}
	if (ans.size() > 100'000) return cout << -1, 0;
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i].first << ' ' << ans[i].second << '\n';
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}

void changeD(int x, int y) {
	if (!(a[x][y + 1] == 'D'))
		changeL(x, y + 1);
	ans.push_back({ x, y + 1 });
	a[x - 1][y] = a[x][y] = 'L';
	a[x - 1][y + 1] = a[x][y + 1] = 'R';
}

void changeL(int x, int y) {
	if (a[x - 1][y] == 'R')
		changeL(x - 1, y - 1);
	if (a[x - 1][y] == 'D')
		changeD(x - 1, y);
	ans.push_back({ x, y + 1 });
	a[x][y] = a[x][y + 1] = 'D';
	a[x - 1][y] = a[x - 1][y + 1] = 'U';
}