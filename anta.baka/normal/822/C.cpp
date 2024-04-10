#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9 + 1;

struct seg {
	int l, r, c;
};

int n, x;
seg a[200000];
map<int, int> opt;
int ans = INF;
auto cmp = [](seg a, seg b){ return a.r < b.r; };
multiset<seg, decltype(cmp)> add(cmp);

int main() {
	cin >> n >> x;
	for(int i = 0; i < n; i++)
		cin >> a[i].l >> a[i].r >> a[i].c;
	sort(a, a + n, [](seg a, seg b){ return a.l < b.l; });
	for(int i = 0; i < n; i++) {
		while(!add.empty() && add.begin()->r < a[i].l) {
			int y = add.begin()->r - add.begin()->l + 1;
			if(opt.count(y) == 0)
				opt[y] = INF;
			opt[y] = min(opt[y], add.begin()->c);
			add.erase(add.begin());
		}
		int y = x - a[i].r + a[i].l - 1;
		if(opt.count(y) != 0)
			ans = min(ans, opt[y] + a[i].c);
		add.insert(a[i]);
	}
	cout << (ans == INF ? -1 : ans);
}