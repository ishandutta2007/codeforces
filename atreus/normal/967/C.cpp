#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 5e5 + 10;
const ll mod = 998244353;

int l[maxn], e[maxn];

int goEle(int x1, int y1, int x2, int y2, int p, int sp) {
	return abs(y1 - p) + (abs(x1 - x2) + sp - 1) / sp + abs(y2 - p);
}

int goStairs(int x1, int y1, int x2, int y2, int p) {
	return abs(y1 - p) + abs(x1 - x2) + abs(y2 - p);
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, st, el, sp;
	cin >> n >> m >> st >> el >> sp;
	for (int i = 1; i <= st; i++)
		cin >> l[i];
	for (int i = 1; i <= el; i++)
		cin >> e[i];
	int q;
	cin >> q;
	while (q --) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2) {
			cout << abs(y2 - y1) << '\n';
			continue;
		}
		int idx = lower_bound(l + 1, l + st + 1, y1) - l;
		int optSt = 2 * (n + m);
		if (idx <= st)
			optSt = min(optSt, goStairs(x1, y1, x2, y2, l[idx]));
		if (idx > 1)
			optSt = min(optSt, goStairs(x1, y1, x2, y2, l[idx-1]));
		
			idx = lower_bound(e + 1, e + el + 1, y1) - e;
		int optEl = 2 * (n + m);
		if (idx <= el)
			optEl = min(optEl, goEle(x1, y1, x2, y2, e[idx], sp));
		if (idx > 1)
			optEl = min(optEl, goEle(x1, y1, x2, y2, e[idx-1], sp));
		
		cout << min(optEl, optSt) << '\n';
	}
}