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
const int Maxn = 1e5 + 1;
const int mod = 1e9 + 7;
const int block = 333;
int cnt, n, m, num[maxn], a[maxn], ans[maxn];
pair <pii, int> q[maxn];

void del (int L, int R) {
	while (L < R) {
		int x = a[L];
		if (x > Maxn or x == 0) {
			L ++;
			continue;
		}
		num[x] --;
		if (num[x] == x)
			cnt ++;
		if (num[x] == x - 1)
			cnt --;
		L ++;
	}
}

void add (int L, int R) {
	while (L < R) {
		int x = a[L];
		if (x > Maxn or x == 0) {
			L ++;
			continue;
		}
		num[x] ++;
		if (num[x] == x)
			cnt ++;
		if (num[x] == x + 1)
			cnt --;
		L ++;
	}
}

bool cmp (pair <pii, int> Fi, pair <pii, int> Se) {
	int x = Fi.F.F / block, y = Se.F.F / block;
	if (x != y)
		return x < y;
	return Fi.F.S < Se.F.S;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= m; i++) {
		cin >> q[i].F.F >> q[i].F.S;
		q[i].S = i;
	}

	sort (q + 1, q + m + 1, cmp);
	
	int L = 0, R = 0;
	for (int i = 1; i <= m; i++) {
		int l = q[i].F.F, r = q[i].F.S;
		
		if (L < l) {
			del (L, l);
			L = l;
		}
		
		if (L > l) {
			add (l, L);
			L = l;
		}
		
		if (R < r) {
			add (R + 1, r + 1);
			R = r;
		}

		if (R > r) {
			del (r + 1, R + 1);
			R = r;
		}

		ans[q[i].S] = cnt;
	}

	for (int i = 1; i <= m; i++)
		cout << ans[i] << '\n';
}