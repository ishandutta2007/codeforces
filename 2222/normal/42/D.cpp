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

int n, p[20], c[1000];

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n;
	FOR (i, 1, n) {
		for (p[i] = p[i - 1] + 1; ; ++p[i]) {
			bool ok = true;
			REP (j, i) ++c[p[i] + p[j]];
			REP (j, i) if (c[p[i] + p[j]] != 1) ok = false;
			if (ok) break;
			REP (j, i) --c[p[i] + p[j]];
		}
	}
	
	REP (i, n) {
		REP (j, n) {
			if (j) putchar(' ');
			printf("%d", i != j ? p[i] + p[j] + 1 : 0);
		}
		puts("");
	}
	return 0;
}