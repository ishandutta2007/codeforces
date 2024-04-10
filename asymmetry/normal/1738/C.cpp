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
		int even = 0, odd = 0;
		REP (i, n) {
			int a;
			cin >> a;
			if (a % 2) {
				++odd;
			}
			else {
				++even;
			}
		}
		if (even & 1) {
			if (odd % 4 == 2) {
				cout << "Bob" << endl;
			}
			else {
				cout << "Alice" << endl;
			}
		}
		else if (odd % 4 == 1 || odd % 4 == 2) {
			cout << "Bob" << endl;
		}
		else {
			cout << "Alice" << endl;
		}
	}
}