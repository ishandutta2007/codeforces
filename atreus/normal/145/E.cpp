#include <iostream>
#include <sstream>
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
const int maxn = 1e6 + 100;

class node {
	public:
		int l47;
		int l44;
		int l77;
		int l74;
		int lazy;
};

node seg[4 * maxn];

string s;

void cal (int id) {
	int L = 2 * id + 0, R = 2 * id + 1;
	seg[id].l44 = seg[L].l44 + seg[R].l44;
	seg[id].l77 = seg[L].l77 + seg[R].l77;
	seg[id].l47 = max (seg[L].l44 + seg[R].l47, seg[L].l47 + seg[R].l77);
	seg[id].l74 = max (seg[L].l77 + seg[R].l74, seg[L].l74 + seg[R].l44);
	seg[id].l47 = max (seg[id].l47, max (seg[id].l44, seg[id].l77));
	seg[id].l74 = max (seg[id].l74, max (seg[id].l44, seg[id].l77));
}

void propagate (int, int, int);

void change (int id, int L, int R, int l, int r) {
	if (L == l and R == r) {
		swap (seg[id].l47, seg[id].l74);
		swap (seg[id].l44, seg[id].l77);
		seg[id].lazy ^= 1;
		return;
	}
	propagate (id, L, R);
	int mid = (L + R) >> 1;
	if (mid > l)
		change (2 * id + 0, L, mid, l, min (mid, r));
	if (mid < r)
		change (2 * id + 1, mid, R, max (l, mid), r);
	cal (id);
}	

void propagate (int id, int L, int R) {
	if (seg[id].lazy == 0)
		return;
	int mid = (L + R) >> 1;
	change (2 * id + 0, L, mid, L, mid);
	change (2 * id + 1, mid, R, mid, R);
	seg[id].lazy = 0;
}

void build (int id, int L, int R) {
	if (L + 1 == R) {
		seg[id].l47 = 1;
		seg[id].l74 = 1;
		seg[id].l44 = (s[L] == '4');
		seg[id].l77 = (s[L] == '7');
		return;
	}
	int mid = (L + R) >> 1;
	build (2 * id + 0, L, mid);
	build (2 * id + 1, mid, R);
	cal (id);
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m >> s;
	build (1, 0, n);
	for (int i = 0; i < m; i++) {
		string type;
		int l, r;
		cin >> type;
		if (type == "count") {
			cout << seg[1].l47 << '\n';
			continue;
		}
		cin >> l >> r;
		l --;
		change (1, 0, n, l, r);	
	}
}