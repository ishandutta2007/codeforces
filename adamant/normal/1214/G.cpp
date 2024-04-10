#include <bits/stdc++.h>

using namespace std;

const int maxn = 2002;

bitset<maxn> pref[maxn];
bitset<maxn> flipper(int l, int r) {
	return pref[r] ^ pref[l - 1];
}

bitset<maxn> tab[maxn];

set<int> nosub;
unordered_map<bitset<maxn>, int> repr[maxn];
set<int> in_use;
set<int> dist;

void upd(set<int>::iterator it) {	
	if(it != in_use.end() && it != in_use.begin()) {
		if(!dist.count(*it) && !dist.count(*prev(it))) {
			auto &A = repr[*prev(it)].begin()->first;
			auto &B = repr[*it].begin()->first;
			if((A & B) == A) {
				nosub.erase(*prev(it));
			} else {
				nosub.insert(*prev(it));
			}
		}
	} else if(it == in_use.end()) {
		if(it != in_use.begin()) {
			nosub.erase(*prev(it));
		}
	}
}

unordered_map<bitset<maxn>, set<int>> rev;

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i = 1; i < maxn; i++) {
		pref[i] = pref[i - 1];
		pref[i][i - 1] = 1;
	}
	int n, m, q;
	cin >> n >> m >> q;
	repr[0][0] = n;
	in_use.insert(0);
	while(q--) {
		int a, l, r;
		cin >> a >> l >> r;
		a--;
		{
			int k = tab[a].count();
			auto &it = repr[k][tab[a]];
			it--;
			rev[tab[a]].erase(a);
			if(it == 0) {
				repr[k].erase(tab[a]);
			}
			if(repr[k].empty()) {
				in_use.erase(k);
				nosub.erase(k);
			} else if(repr[k].size() == 1) {
				dist.erase(k);
			}
			upd(in_use.lower_bound(k));
			upd(in_use.upper_bound(k));
		}
		tab[a] ^= flipper(l, r);
		{
			int k = tab[a].count();
			auto &it = repr[k][tab[a]];
			it++;
			rev[tab[a]].insert(a);
			in_use.insert(k);
			if(repr[k].size() > 1) {
				dist.insert(k);
			}
			upd(in_use.lower_bound(k));
			upd(in_use.upper_bound(k));
		}
		if(dist.empty() && nosub.empty()) {
			cout << -1 << "\n";
		} else if(dist.size()) {
			int k = *dist.begin();
			auto A = *repr[k].begin();
			auto B = *next(repr[k].begin());
			int x1, y1, x2, y2;
			tie(x1, x2) = minmax(*begin(rev[A.first]), *begin(rev[B.first]));
			tie(y1, y2) = minmax(((A.first | B.first) ^ B.first)._Find_first(), ((A.first | B.first) ^ A.first)._Find_first());
			cout << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << "\n";
		} else {
			int k = *nosub.begin();
			int k2 = *in_use.upper_bound(k);
			auto A = *repr[k].begin();
			auto B = *repr[k2].begin();
			int x1, y1, x2, y2;
			tie(x1, x2) = minmax(*begin(rev[A.first]), *begin(rev[B.first]));
			tie(y1, y2) = minmax(((A.first | B.first) ^ B.first)._Find_first(), ((A.first | B.first) ^ A.first)._Find_first());
			cout << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << "\n";
		}
	}
    return 0;
}