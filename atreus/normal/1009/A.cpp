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
int c[maxn], a[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int j = 1; j <= m; j++)
		cin >> a[j];
	int idx = 1, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (idx > m)
			continue;
		if (c[i] <= a[idx]) {
			cnt ++;
			idx ++;
		}
	}
	cout << cnt << endl;
}