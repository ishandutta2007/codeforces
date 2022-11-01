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

int n, k;
int b[1024];
int r[1024];

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n >> k;
	REP (i, n) {
		cin >> b[i];
		r[i] = i;
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = i; b[i] > 0; ++j) {
			if (r[j + 1] >= r[j] + k) --b[i];
			swap(r[j], r[j + 1]);
		}
	}
	REP (i, n) {
		if (i) putchar(' ');
		printf("%d", r[i] + 1);
	}
	puts("");
	return 0;
}