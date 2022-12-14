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
const int maxn = 4e5 + 5;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 316;

bool mark[maxn];

int main () {
	ios_base::sync_with_stdio (false);

	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		cout << 1 << endl;
		int x;
		cin >> x;
		if (x == 0)
			exit (0);
		else if (x == -1)
			mark[i] = 1;
	}
	
	int l = 0, r = m + 1, idx = 1;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		cout << mid << endl;
		int x;
		cin >> x;
		if (mark[idx])
			x *= -1;
		if (x == 0)
			exit (0);
		if (x == 1)
			l = mid;
		else
			r = mid;
		idx ++;
		if (idx == n + 1)
		    idx = 1;
	}
}