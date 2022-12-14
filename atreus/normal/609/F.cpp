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
#define position first
#define sizze second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 2e5 + 10;

struct frog {
	ll pos, len, andice;
};

frog a[maxn];

bool Compare (frog fi, frog se) {return fi.pos < se.pos;}

ll seg[4 * maxn];

ll get (int id, int L, int R, int l, int r, int x) {
	if (seg[id] < x)
		return -1;

	if (L + 1 == R) {
		return L;
	}

	int mid = (L + R) >> 1;
	ll ret = get (2 * id + 0, L, mid, l, min (mid, r), x);
	if (ret == -1 and mid < r)
		ret = get (2 * id + 1, mid, R, max (l, mid), r, x);

	return ret;
}

void change (int id, int L, int R, int idx) {
	if (L + 1 == R) {
		seg[id] = a[L].pos + a[L].len;
		return;
	}
	
	int mid = (L + R) >> 1;

	if (mid > idx)
		change (2 * id + 0, L, mid, idx);
	else
		change (2 * id + 1, mid, R, idx);
		
	seg[id] = max (seg[2 * id + 0], seg[2 * id + 1]);
}

void build (int id, int L, int R) {
	if (L + 1 == R) {
		seg[id] = a[L].pos + a[L].len;
		return;
	}
	int mid = (L + R) >> 1;

	build (2 * id + 0, L, mid);
	build (2 * id + 1, mid, R);
	
	seg[id] = max (seg[2 * id + 0], seg[2 * id + 1]);
}

int n, m;

int UpperBound (int x) {
	int lo = -1, hi = n;
	while (hi - lo > 1) {
		int mid = (lo + hi) >> 1;
		if (a[mid].pos <= x)
			lo = mid;
		else
			hi = mid;
	}
	return hi;
}

pair <ll, ll> ans[maxn];

ll num[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i].pos >> a[i].len;
		a[i].andice = i;
	}

	sort (a, a + n, Compare);
	build (1, 0, n);
	
	multiset <pair <ll, ll> > pashe;

	for (int i = 0; i < m; i++) {
		ll p, b;
		cin >> p >> b;
		int idx = UpperBound (p);
		
		
		int fr = -1;
		
		if (idx > 0)
			fr = get (1, 0, n, 0, idx, p);
		else
			continue;
	
		if (fr == -1) {
			pashe.insert ({p, b});
		}
		else {
			a[fr].len += b;
			num[fr] ++;
			while (!pashe.empty()) {
				auto q = pashe.lower_bound ({a[fr].pos, 0});
				if (q != pashe.end() and (*q).position <= a[fr].pos + a[fr].len) {
					a[fr].len += (*q).sizze;
					num[fr] ++;
					pashe.erase (q);
				}
				else {
					break;
				}
			}
			change (1, 0, n, fr);
		}
	}

	for (int i = 0; i < n; i++)
		ans[a[i].andice] = {num[i], a[i].len};
	for (int i = 0; i < n; i++)
		cout << ans[i].first << " " << ans[i].second << '\n';
}