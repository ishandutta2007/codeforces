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

string s[] = {
	"Gryffindor",
	"Ravenclaw",
	"Slytherin",
	"Hufflepuff"
};

int n;
char a[11111];

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	scanf("%d%s", &n, a);
	vector <vi> B(1, vi(4));
	REP (i, n) {
		if (a[i] == '?') {
			vector <vi> U;
			for (vector<vi> :: iterator q = B.begin(); q != B.end(); ++q) {
				vi &t = *q;
				int s = *min_element(all(t));
				REP (j, 4) if (t[j] == s) {
					++t[j];
					U.pb(t);
					--t[j];
				}
			}
			B.swap(U), UN(B);
		} else {
			int id;
			switch (a[i]) {
				case 'G': id = 0; break;
				case 'R': id = 1; break;
				case 'S': id = 2; break;
				case 'H': id = 3; break;
			}
			REP (j, sz(B)) B[j][id]++;
		}
	}
	bool r[4] = {false, false, false, false};
	for (vector<vi> :: iterator q = B.begin(); q != B.end(); ++q) {
		vi &t = *q;
		int s = *min_element(all(t));
		REP (j, 4) if (t[j] == s) 
			r[j] = true;
	}
	vector <string> res;
	REP (i, 4) if (r[i]) res.pb(s[i]);
	UN(res);
	REP (i, sz(res)) cout << res[i] << endl;
	return 0;
}