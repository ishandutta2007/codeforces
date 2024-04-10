#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct quer {
	int a, t, x, vp;
};

int main() {
	int m;
	cin >> m;
	vector<quer> q(m);
	map<int, int> dif;
	for(int i = 0; i < m; i++) {
		cin >> q[i].a >> q[i].t >> q[i].x;
		dif[q[i].x];
	}
	int n = 0;
	for(auto &x : dif)
		x.second = n++;
	vector<vector<int>> tr(n), tim(n);
	for(int i = 0; i < m; i++) {
		q[i].vp = dif[q[i].x];
		tim[q[i].vp].pb(q[i].t);
	}
	for(int i = 0; i < n; i++) {
		sort(all(tim[i]));
		tr[i].resize(2*sz(tim[i]));
	}
	for(int i = 0; i < m; i++) {
		int p = q[i].vp;
		int len = sz(tim[p]);
		int bl = 0, br = len-1;
		while(bl < br) {
			int bm = (bl + br) >> 1;
			if(tim[p][bm] < q[i].t)
				bl = bm + 1;
			else
				br = bm;
		}
		if(q[i].a == 3) {
			int res = 0;
			for(int l = len, r = bl + len; l <= r; l = (l+1) >> 1, r = (r-1) >> 1) {
				if(l&1) res += tr[p][l];
				if(!(r&1)) res += tr[p][r];
			}
			cout << res << "\n";
		} else {
			int add = 1;
			if(q[i].a == 2)
				add = -1;
			int v = bl + len;
			for(; v > 0; v >>= 1)
				tr[p][v] += add;
		}
	}
}