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
		int n, k;
		cin >> n >> k;
		vector<int> t(k);
		for (int &i : t) {
			cin >> i;
		}
		if (k == 1) {
			cout << "YES" << endl;
			continue;
		}
		bool odp = true;
		int last = t[1] - t[0];
		FOR (i, 1, k - 1) {
			if (t[i] - t[i - 1] < last) {
				odp = false;
			}
			last = t[i] - t[i - 1];
		}
		if ((LL)(t[1] - t[0]) * (n - k + 1) < t[0]) {
			odp = false;
		}
		if (odp) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}