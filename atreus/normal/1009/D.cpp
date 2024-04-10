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
const int maxn = 1e5 + 5;
vector <int> v[maxn];

int gcd (int u, int w) {
	if (u > w)
		swap (u, w);
	if (w % u == 0)
		return u;
	return gcd (u, w % u);
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	if (m < n - 1)
		return cout << "Impossible" << endl, 0;
	for (int i = 2; i <= n; i++)
		v[i].PB (1);
	int cnt = n - 1;
	for (int i = 2; cnt < m and i <= n; i++) {
		for (int j = 2; cnt < m and j < i; j++) {
			if (gcd (i, j) == 1) {
				v[i].PB (j);
				cnt ++;
			}
		}
	}
	if (cnt < m)
		return cout << "Impossible" << endl, 0;
	cout << "Possible" << endl;
	for (int i = 1; i <= n; i++)
		for (auto j : v[i])
			cout << i << " " << j << '\n';
}