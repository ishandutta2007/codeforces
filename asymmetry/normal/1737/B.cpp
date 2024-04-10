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
	REP (test, tests) {
		LL l, r;
		cin >> l >> r;
		LL sl = (LL)sqrtl(l);
		LL sr = (LL)sqrtl(r);
		while (sl * sl > l) {
			--sl;
		}
		while (sr * sr > r) {
			--sr;
		}
		debug(l, r);
		debug(sl, sr);
		LL odp = (sr - sl - 1) * 3;
		auto good = [&](LL x) {
			return l <= x && x <= r;
		};
		odp += good(sl * sl) + good(sl * (sl + 1)) + good(sl * (sl + 2));
		if (sl != sr) {
			odp += good(sr * sr) + good(sr * (sr + 1)) + good(sr * (sr + 2));
		}
		else {
			odp += 3;
		}
		cout << odp << endl;
	}
}