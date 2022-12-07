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
		int n;
		cin >> n;
		set<pair<int, int>> S, s[2];
		map<int, int> zx, zy;
		int rim = 0;
		REP (i, 3) {
			int a, b;
			cin >> a >> b;
			++zx[a];
			++zy[b];
			rim += (a == 1) || (a == n) || (b == 1) || (b == n);
			S.insert({a, b});
			s[(a + b) & 1].insert({a, b});
		}
		int x, y;
		cin >> x >> y;
		if (S.count({x, y})) {
			cout << "YES\n";
			continue;
		}
		if (rim == 3) {
			if (zx[x] == 2 || zy[y] == 2) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
			continue;
		}
		if (ssize(s[(x + y) & 1]) == 1 && (x & 1) != (s[(x + y) & 1].begin()->first & 1)) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
	}
}