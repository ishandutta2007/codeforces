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
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
typedef unsigned long long ull;
const int maxn = 3e5 + 5;
const int mod = 1e9 + 7;
const ll inf = (1ll << 62);
const int sq = 500;

int a[maxn];

inline int block (int x) { return x / sq; }

struct query {
	int l, r, k, ind;
};

query Q[maxn];

bool mo (query fi, query se) {
	if (block (fi.l) != block (se.l))
		return fi.l < se.l;
	return (fi.r < se.r);
}

int occ[maxn], ans[maxn];

int main() {	
	ios_base::sync_with_stdio (false);
	srand (time (NULL));
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < q; i++) {
		cin >> Q[i].l >> Q[i].r >> Q[i].k;
		Q[i].ind = i;
		Q[i].l --;
	}
	sort (Q, Q + q, mo); 
	int L = 0, R = 0;
	for (int i = 0; i < q; i++) {

		int lef = Q[i].l, rig = Q[i].r;
		while (R < rig) {
			occ[a[R]] ++;
			R ++;
		}
		while (L > lef) {
			L --;
			occ[a[L]] ++;
		}
		while (R > rig) {
			R --;
			occ[a[R]] --;
		}
		while (L < lef) {
			occ[a[L]] --;
			L ++;
		}
	
		int Min = n + 1;
		for (int poss = 0; poss < 300; poss ++) {
			int p = (rand() % (R - L)) + L;
			if (occ[a[p]] * Q[i].k > R - L)
				Min = min (Min, a[p]);		
		}
		for (int p = 1; p <= 10; p++)
			if (occ[p] * Q[i].k > R - L)
				Min = min (Min, p);
		if (Min == n + 1)
			Min = -1;
		ans[Q[i].ind] = Min;
	}
	for (int i = 0; i < q; i++)
		cout << ans[i] << '\n';
}