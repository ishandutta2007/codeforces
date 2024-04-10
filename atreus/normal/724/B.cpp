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

int n, m, p[30][30], a[30];

bool ok (int id, int fi, int se) {
	for (int i = 1; i <= m; i++)
		a[i] = p[id][i];
	swap (a[fi], a[se]);
	int cnt = 0;
	for (int i = 1; i <= m; i++)
		cnt += (i == a[i]);
	if (cnt >= m - 2)
		return 1;
	swap (a[fi], a[se]);
	
	cnt = 0;
	for (int i = 1; i <= m; i++) {
		if (i == fi or i == se)
			continue;
		cnt += (a[i] == i);
	}
	cnt += (a[fi] == se);
	if (fi != se) {
		cnt += (a[se] == fi);
	}
	return (cnt >= m - 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> p[i][j];
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = i; j <= m; j++) {
			bool found = 0;
			for (int z = 1; z <= n; z++) {
				if (!ok (z, i, j))
					found = 1;
			}
			if (!found)
				return cout << "YES" << endl, 0;
		}
	}
	cout << "NO" << endl;
}