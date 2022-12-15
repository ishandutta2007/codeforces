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
const int maxn = 1e6 + 10;
const int inf = 1e9 + 10;

int a[maxn], f[maxn], s[maxn], t[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < m; i++)
		cin >> t[i];
	for (int i = 0; i < n - 1; i++)
		s[i] = s[i + 1] - s[i];
	for (int i = 0; i < m - 1; i++)
		t[i] = t[i + 1] - t[i];
	
	for (int i = 0; i < m - 1; i++)
		a[i] = t[i];
	a[m - 1] = inf;
	for (int i = m; i < m + n - 1; i++)
		a[i] = s[i - m];
	
	int k = 0, cnt = 0;
	for (int i = 2; i <= m + n - 1; i++) {
		while (k != 0 and a[i - 1] != a[k])
			k = f[k];
		if (a[i - 1] == a[k])
			k ++;
		f[i] = k;
		if (f[i] == m - 1)
			cnt ++;
	}
	cout << cnt + (m == 1) << endl;
}