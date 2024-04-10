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
const int maxn = 2e5 + 10;
const int Maxn = 1e6 + 5;
const int mod = 1e9 + 7;
const int block = 420;
int n, m, a[maxn], ted[Maxn];
ll tmp, ans[maxn];
pair <pair <int, int>, int> q[maxn];

bool cmp (pair <pii, int> Fi, pair <pii, int> Se) {
	int x = Fi.F.F / block, y = Se.F.F / block;
	if (x != y)
		return x < y;
	return Fi.F.S < Se.F.S;
}

void add (int R, int r) { // (...]
	while (R < r) {
		R ++;
		int x = a[R];
		ted[x] ++;
		int num = ted[x];
		tmp += (1ll * num * num - 1ll * (num - 1) * (num - 1)) * x;
	}
}

void del (int R, int r) { // [...)
	while (R < r) {
		int x = a[R];
		ted[x] --;
		int num = ted[x];
		tmp += (1ll * num * num - 1ll * (num + 1) * (num + 1)) * x;
		R ++;
	}
}

int main() {
//	ios_base::sync_with_stdio(false);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &a[i]);
	for (int i = 1; i <= m; i++) {
		q[i].S = i;
		scanf ("%d%d", &q[i].F.F, &q[i].F.S);
	}
	sort (q + 1, q + m + 1, cmp);
	
	int L = 0, R = 0;
	for (int i = 1; i <= m; i++) {
		int l = q[i].F.F, r = q[i].F.S;
		if (R < r) {
			add (R, r);
			R = r;
		}
		if (R > r) {
			del (r + 1, R + 1);
			R = r;
		}
		if (L < l) {
			del (L, l);
			L = l;
		}
		if (L > l) {
			add (l - 1, L - 1);
			L = l;
		}
		ans[q[i].S] = tmp;
	}
	
	for (int i = 1; i <= m; i++)
		printf ("%lld\n", ans[i]);
}