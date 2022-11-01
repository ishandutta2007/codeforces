#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for (int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(v)			sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)		memset(a, b, sizeof a)
#define pb				push_back
#define X				first
#define Y				second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int F, n, m, q;
vi f[111];
map <string, int> ans[111];

bool compare(const vi &p, const vi &q) {
	REP (i, n) if (q[i] > p[i]) return false;
	return true;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> F >> n >> m >> q;
	REP (i, F) f[i].resize(n);
	vector <string> a;
	REP (i, n) {
		string s;
		cin >> s;
		a.pb(s);
	}
	sort(all(a));
	vector <string> b;
	vector < vector <int> > ba;
	REP (i, m) {
		string w;
		cin >> w;
		b.pb(w.substr(0, sz(w) - 1));
		getline(cin, w);
		REP (j, sz(w)) if (w[j] == ',') w[j] = ' ';
		stringstream read(w);
		vector <int> c(n);
		for (int k; read >> w >> k; ) 
			c[lower_bound(all(a), w) - a.begin()] += k;
		ba.pb(c);
	}
	for (; q > 0; --q) {
		int i;
		string w;
		cin >> i >> w;
		--i;
		f[i][lower_bound(all(a), w) - a.begin()]++;
		REP (j, m) {
			if (compare(f[i], ba[j])) {
//				cout << i << ' ' << w << ' ' << f[i][0] << ' ' << f[i][1] << endl;
				REP (k, n) f[i][k] -= ba[j][k];
//				cout << i << ' ' << w << ' ' << f[i][0] << ' ' << f[i][1] << endl;
//				cout << endl;
				ans[i][b[j]]++;
			}
		}
	}
	REP (i, F) 
		REP (j, n)
			for (; f[i][j] > 0; --f[i][j])
				ans[i][a[j]]++;
	REP (i, F) {
		vector < pair <string, int> > z(all(ans[i]));
		cout << z.size() << endl;
		REP (j, sz(z)) cout << z[j].first << ' ' << z[j].second << endl;
	}
	return 0;
}