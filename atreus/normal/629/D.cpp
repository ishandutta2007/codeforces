#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <bitset>
#include <set>
#include <algorithm>
#include <iomanip>
#include <fstream>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e5 + 10;

class Cake {
	public:
		ld radius;
		ld height;
		ld volume;
		int index;
		int per;
};

bool compare_cake (Cake fi, Cake se) { return fi.volume < se.volume; }

ld square (ld x) { return x * x; }

Cake cake[maxn], cpy[maxn];

ld seg[4 * maxn];

ld get (int id, int L, int R, int l, int r) {
	if (L == l and R == r)
		return seg[id];
	int mid = (L + R) >> 1;
	ld ret = 0;
	if (mid > l)
		ret = max (ret, get (2 * id + 0, L, mid, l, min (mid, r)));
	if (mid < r)
		ret = max (ret, get (2 * id + 1, mid, R, max (l, mid), r));
	return ret;
}

void change (int id, int L, int R, int idx, ld val) {
	if (L + 1 == R) {
		seg[id] = val;
		return;
	}
	int mid = (L + R) >> 1;
	if (mid > idx)
		change (2 * id + 0, L, mid, idx, val);
	else
		change (2 * id + 1, mid, R, idx, val);
	seg[id] = max (seg[2 * id + 0], seg[2 * id + 1]);
}

//ld pi = 3.1415926535897932;
ld pi = 3.141592653589793238462643;

int main () {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cake[i].radius >> cake[i].height;
		cake[i].index = i, cake[i].volume = square (cake[i].radius) * cake[i].height;
		cpy[i] = cake[i];
	}
	sort (cpy + 1, cpy + n + 1, compare_cake);
	int last = 1;
	for (int i = 1; i <= n; i++) {
		if (cpy[i].volume != cpy[i - 1].volume)
			last = i;
		cake[cpy[i].index].per = last;
	}
	ld ans = 0;
	for (int i = 1; i <= n; i++) {
		ld pre = 0;
		if (cake[i].per != 1)
			pre = get (1, 1, n + 1, 1, cake[i].per);
		ans = max (ans, pre + cake[i].volume);
		change (1, 1, n + 1, cake[i].per, pre + cake[i].volume);
	}
	cout << fixed << setprecision (6) << ans * pi << endl;
}