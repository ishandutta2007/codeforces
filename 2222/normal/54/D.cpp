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

int n, k, p;
char a[128], b[128];
char r[256];

void put(int i, char c) {
	if (r[i] == 0) r[i] = c;
	if (r[i] != c) {
		puts("No solution");
		exit(0);
	}
}

bool check() {
	for (int i = 0; i + p <= n; ++i) {
		bool ok = true;
		REP (j, p) if (r[i + j] != a[j]) {
			ok = false;
			break;
		}
		if (ok != (b[i] == '1')) return false;
	}
	return true;
}


int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n >> k >> a >> b;
	p = strlen(a);
	for (int i = 0; i + p <= n; ++i)
		if (b[i] == '1') 
			REP (j, p) put(i + j, a[j]);
	if (!check()) {
		puts("No solution");
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		if (r[i] == 0) {
			for (int q = 0; ; ++q) {
				if (q == k) {
					puts("No solution");
					return 0;
				}
				r[i] = 'a' + q;
				if (check()) break;
			}
		}
	}
	puts(r);
	return 0;
}