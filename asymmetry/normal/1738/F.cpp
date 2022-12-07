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
		#ifdef LOCAL
		/*int N, M;
		cin >> N >> M;
		vector<int> G(N + 1);
		vector<pair<int, int>> P;
		REP (i, M) {
			int a = r*/
		auto ask = [&](int x) {
			cout << "? " << x << endl;
			int ret;
			cin >> ret;
			return ret;
		};
		#else
		auto ask = [&](int x) {
			cout << "? " << x << endl;
			int ret;
			cin >> ret;
			return ret;
		};
		#endif
		int n;
		cin >> n;
		vector<int> t(n + 1);
		FOR (i, 1, n) {
			cin >> t[i];
		}
		vector<vector<int>> v(n + 1);
		vector<int> dead(n + 1, 0);
		vector<pair<int, int>> sr;
		FOR (i, 1, n) {
			sr.emplace_back(t[i], i);
		}
		sort(sr.rbegin(), sr.rend());
		for (auto [a, b] : sr) {
			if (dead[b]) {
				continue;
			}
			dead[b] = 1;
			REP (j, t[b]) {
				int x = ask(b);
				v[b].emplace_back(x);
				v[x].emplace_back(b);
				if (dead[x]) {
					break;
				}
				dead[x] = 1;
			}
		}
		vector<int> odp(n + 1, 0);
		int k = 0;
		function<void(int)> dfs = [&](int x) {
			for (int i : v[x]) {
				if (!odp[i]) {
					odp[i] = odp[x];
					dfs(i);
				}
			}
		};
		FOR (i, 1, n) {
			if (!odp[i]) {
				++k;
				odp[i] = k;
				dfs(i);
			}
		}
		cout << "!";
		FOR (i, 1, n) {
			cout << " " << odp[i];
		}
		cout << endl;
	}
}