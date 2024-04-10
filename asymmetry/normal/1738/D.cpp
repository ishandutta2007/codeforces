#include<bits/stdc++.h>
using namespace std;
using LL=long long;
#define FOR(i,l,r) for(int i=(l);i<=(r);++i)
#define REP(i,n) FOR(i,0,(n)-1)
#define ssize(x) int(x.size())
template<class A,class B>auto&operator<<(ostream&o,pair<A,B>p){return o<<'('<<p.first<<", "<<p.second<<')';}
template<class T>auto operator<<(ostream&o,T x)->decltype(x.end(),o){o<<'{';int i=0;for(auto e:x)o<<(", ")+2*!i++<<e;return o<<'}';}
#ifdef DEBUG
#define debug(x...) cerr<<"["#x"]: ",[](auto...$){((cerr<<$<<"; "),...)<<'\n';}(x)
#else
#define debug(...) {}
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int tests;
	cin >> tests;
	FOR (test, 1, tests) {
		int n;
		cin >> n;
		int k = 0;
		vector<vector<int>> v(n + 2);
		FOR (i, 1, n) {
			int a;
			cin >> a;
			if (a >= i) {
				k = i;
			}
			v[a].emplace_back(i);
		}
		int rot = 0;
		if (v[0].empty()) {
			rot = n + 1;
		}
		vector<int> odp(n);
		int p = 0;
		debug(v);
		while (true) {
			debug(rot);
			int nxt = -1;
			for (int i : v[rot]) {
				if (v[i].empty()) {
					odp[p] = i;
					++p;
				}
				else {
					nxt = i;
				}
			}
			if (nxt != -1) {
				odp[p] = nxt;
				++p;
				rot = nxt;
				continue;
			}
			else {
				break;
			}
		}
		cout << k << endl;
		REP (i, n) {
			cout << odp[i] << ' ';
		}
		cout << endl;
	}
}