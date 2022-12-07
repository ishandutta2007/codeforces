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
		vector<int> lf, rg;
		vector type(n, 0);
		REP(i, n) {
			cin >> type[i];
		}
		LL odp = 0;
		REP (i, n) {
			int a;
			cin >> a;
			odp += a;
			if (type[i]) {
				lf.emplace_back(a);
			}
			else {
				rg.emplace_back(a);
			}
		}
		sort(lf.rbegin(), lf.rend());
		sort(rg.rbegin(), rg.rend());
		if (ssize(lf) == ssize(rg)) {
			cout << odp * 2 - min(lf.back(), rg.back()) << endl;
			continue;
		}
		int m = min(ssize(lf), ssize(rg));
		REP (i, m) {
			odp += lf[i] + rg[i];
		}
		cout << odp << endl;
	}
}