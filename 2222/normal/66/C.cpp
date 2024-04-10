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

int getMax(map< string, set<string> > &f) {
	int r = 0;
	for (map< string, set<string> > :: iterator i = f.begin(); i != f.end(); ++i)
		r = max(r, sz(i->Y));
	return r;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	map <string, set<string> > F, G;
	for (string s; getline(cin, s); ) {
		s.erase(1, 2);
		int i = s.find('\\');
		string f = s.substr(i + 1);
		s = s.substr(0, i);
		G[s].insert(f);
		for (int j = sz(f); ; ) {
			for (; j >= 0 && f[j] != '\\'; --j);
			if (j < 0) break;
			f.resize(j);
			F[s].insert(f);
		}
	}
	cout << getMax(F) << ' ' << getMax(G) << endl;
	return 0;
}