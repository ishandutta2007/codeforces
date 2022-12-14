#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 2;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
int x[maxn];

int main() {	
	ios_base::sync_with_stdio (false);
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i == 1)
			ans ++;
		else {
			int k = x[i] - d;
			if (k - x[i - 1] > d)
				ans ++;
		}
		if (i == n)
			ans ++;
		else {
			int k = x[i] + d;
			if (x[i + 1] - k >= d)
				ans ++;
		}
	}
	cout << ans << endl;
}