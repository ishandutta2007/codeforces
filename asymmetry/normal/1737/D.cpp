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
		int n, m;
		cin >> n >> m;
		vector v(n, vector(n, -1));
		const LL INF = 1e18;
		vector odl(n, vector(n, INF));
		REP (i, m) {
			int a, b, c;
			cin >> a >> b >> c;
			--a;
			--b;
			if (v[a][b] == -1) {
				v[a][b] = c;
			}
			v[a][b] = min(v[a][b], c);
			swap(a, b);
			if (v[a][b] == -1) {
				v[a][b] = c;
			}
			v[a][b] = min(v[a][b], c);
			odl[a][b] = odl[b][a] = 1;
		}
		REP (i, n) {
			odl[i][i] = 0;
		}
		REP (k, n) {
			REP (i, n) {
				REP (j, n) {
					odl[i][j] = min(odl[i][j], odl[i][k] + odl[k][j]);
				}
			}
		}
		LL odp = INF;
		REP (i, n) {
			REP (j, n) {
				if (v[i][j] != -1) {
					odp = min(odp, (LL)v[i][j] * (odl[0][i] + odl[j][n - 1] + 1));
					REP (k, n) {
						odp = min(odp, (LL)v[i][j] * (odl[0][k] + odl[k][n - 1] + max(odl[k][i], odl[k][j]) + 1));
					}
				}
			}
		}
		cout << odp << endl;
	}
}