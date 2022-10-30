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

map<string, int> score;
map<string, vi> places;

int S[64] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	int T;
	vector <string> names;
	for (cin >> T; T --> 0; ) {
		int n;
		cin >> n;
		for (int p = 0; n --> 0; ++p) {
			string s;
			cin >> s;
			score[s] += S[p];
			vi &t = places[s];
			if (t.size() < 64) t.resize(64);
			t[p + 1]++;
			names.pb(s);
		}
	}
	UN(names);
	pair <vi, string> r1, r2;
	for (int i = 0; i < sz(names); ++i) {
		string s = names[i];
		pair <vi, string> t(places[s], s);
		t.first[0] = score[s];
		if (r1.first.size() == 0 || t > r1) r1 = t;
		swap(t.first[0], t.first[1]);
		if (r2.first.size() == 0 || t > r2) r2 = t;
	}
	cout << r1.Y << endl;
	cout << r2.Y << endl;
	return 0;
}