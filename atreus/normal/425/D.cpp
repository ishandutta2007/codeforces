#include <iostream>
#include <sstream>
#include <queue>
#include <stack>
#include <deque>
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
const int maxn = 2e5 + 100;
const ll inf = 1e18;

vector <int> vx[maxn], vy[maxn];
unordered_map <int, int> mp[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	int n, N = 100 * 1001;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		vx[x].PB (y);
		vy[y].PB (x);
		mp[x][y] = 1;
	}
	
	for (int i = 0; i < N; i++) {
		sort (vx[i].begin(), vx[i].end());
		sort (vy[i].begin(), vy[i].end());
	}

	ll ans = 0;
	for (int x = 0; x < N; x++) {
		for (int j = 0; j < vx[x].size(); j++) {
			int y = vx[x][j];
			int idx = lower_bound (vy[y].begin(), vy[y].end(), x) - vy[y].begin();
			if (vx[x].size() - j <= vy[y].size() - idx) {
				for (int k = j + 1; k < vx[x].size(); k++) {
					int xp = vx[x][k] - vx[x][j];
					if (xp + y < N and mp[x + xp].count (y + xp) and mp[x + xp].count (y))
						ans ++;
				}
			}
			else {
				for (int k = idx + 1; k < vy[y].size(); k++) {
					int xp = vy[y][k] - vy[y][idx];
					if (xp + x < N and mp[x].count (y + xp) and mp[x + xp].count (y + xp))
						ans ++;
				}
			}
		}
	}
	cout << ans << endl;
}