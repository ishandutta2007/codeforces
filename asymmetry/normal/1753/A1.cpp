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
		int sum = 0;
		cin >> n;
		vector<int> t(n), nxt(n);
		vector s(2, vector<int>());
		REP (i, n) {
			cin >> t[i];
			if (t[i] == -1) {
				s[1].emplace_back(i);
			}
			else if (t[i] == 1) {
				s[0].emplace_back(i);
			}
			sum += t[i];
			nxt[i] = i + 1;
		}
		vector odw(n, 0);
		if (sum < 0) {
			sum = abs(sum);
			swap(s[0], s[1]);
		}
		if (sum & 1) {
			cout << -1 << endl;
			continue;
		}
		sum /= 2;
		debug(s[0]);
		debug(sum);
		for (int i : s[0]) {
			if (sum == 0 || i == 0 || odw[i - 1]) {
				continue;
			}
			debug("USD", i);
			odw[i - 1] = odw[i] = 1;
			nxt[i - 1] = i + 1;
			--sum;
		}
		if (sum != 0) {
			cout << -1 << endl;
		}
		else {
			vector<pair<int, int>> ans;
			int x = 0;
			while (x < n) {
				ans.emplace_back(x, nxt[x] - 1);
				x = nxt[x];
			}
			cout << ssize(ans) << endl;
			for (auto [a, b] : ans) {
				cout << a + 1 << ' ' << b + 1 << '\n';
			}
		}
	}
}