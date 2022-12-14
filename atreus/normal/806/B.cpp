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
const int maxn = 200 + 5;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 316;

int n, a[maxn][5], sum[10];

int point (int x) {
	if (n < 2 * x)
		return 500;
	if (n < 4 * x)
		return 1000;
	if (n < 8 * x)
		return 1500;
	if (n < 16 * x)
		return 2000;
	if (n < 32 * x)
		return 2500;
	return 3000;
}

int score (int idx) {
	int ret = 0;
	for (int i = 1; i <= 5; i++)
		if (a[idx][i] != -1)
			ret += point (sum[i]) / 250 * (250 - a[idx][i]);
	return ret;
}

int main () {
	cin >> n;
	for (int i = 1; i <= n; i++) { 
		for (int j = 1; j <= 5; j++) {
			cin >> a[i][j];
			sum[j] += (a[i][j] >= 0);
		}
	}
	for (int ans = 0; ans <= 1000000; ans ++) {
		if (score(1) > score (2))
			return cout << ans << endl, 0;
		for (int i = 1; i <= 5; i++)
			if (a[1][i] > a[2][i] and a[2][i] != -1)
				sum[i] ++;
		n ++;
	}
	cout << -1 << endl;
}