#include<bits/stdc++.h>
 
using namespace std;

#define all(x) begin(x),end(x)

vector<int> apply(vector<int> a, vector<int> b) {
	int n = a.size();
	vector<int> c(n);
	for(int i = 0; i < n; i++) {
		c[i] = a[b[i]];
	}
	return c;
}

map<vector<int>, int> num;
vector<vector<int>> perms;
int tab[120][120];

bitset<120> add(bitset<120> g, int x) {
	if(g[x]) {
		return g;
	} else {		
		int whole[120];
		int sz = 0;
		for(int i = 0; i < 120; i++) {
			if(g[i]) {
				whole[sz++] = i;
			}
		}
		whole[sz++] = x;
		g[x] = 1;
		while(true) {
			bool rep = false;
			int bk = whole[sz - 1];
			for(int i = 0; i < sz; i++) {
				int it = whole[i];
				int cand = tab[it][bk];
				if(!g[cand]) {
					g[cand] = 1;
					whole[sz++] = cand;
					rep = true;
				}
				cand = tab[bk][it];
				if(!g[cand]) {
					g[cand] = 1;
					whole[sz++] = cand;
					rep = true;
				}
			}
			if(!rep) {
				break;
			}
		}
		return g;
	}
}

void solve() {
	vector<int> p(5);
	iota(all(p), 0);
	do {
		num[p];
		num[p] = num.size() - 1;
		perms.push_back(p);
	} while(next_permutation(all(p)));
	for(int i = 0; i < 120; i++) {
		for(int j = 0; j < 120; j++) {
			tab[i][j] = num[apply(perms[i], perms[j])];
		}
	}
	int64_t ans = 0;
	int n, k;
	n = 200000; k = 5;
	cin >> n >> k;
	vector<int> P[n];
	int nm[n];
	bitset<120> base;
	base[0] = 1;
	vector<int> gens(121);
	vector<bitset<120>> curs;
	for(int i = 0; i < n; i++) {
		P[i].resize(5);
		iota(all(P[i]), 1);
		random_shuffle(all(P[i]));
		for(int j = 0; j < k; j++) {
			cin >> P[i][j];
			P[i][j]--;
		}
		for(int j = k; j < 5; j++) {
			P[i][j] = j;
		}
		nm[i] = num[P[i]];
		vector<int> nw(121);
		vector<bitset<120>> crs = {add(base, nm[i])};
		nw[crs.back().count()] = 1;
		for(auto it: curs) {
			auto t = add(it, nm[i]);
			if(nw[t.count()] == 0) {
				crs.push_back(t);
			}
			nw[t.count()] = gens[it.count()] + 1;
		}
		gens = nw;
		curs = crs;
		int prv = 0;
		for(auto it: curs) {
			ans += (gens[it.count()] - prv) * it.count();
			prv = gens[it.count()];
		}
	}
	cout << ans << endl;
}

signed main() {
	//freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int t;
    t = 1;//cin >> t;
    while(t--) {
		solve();
	}
}