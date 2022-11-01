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

int n, a[1111];
int F[1111][1111];

int f(int i, int j) {
	if (j >= n) return a[i];
	int &res = F[i][j];
	if (res < 0) {
		int k = j + 1;
		res = max(a[i], a[j]) + f(k, k + 1);
		res = min(res, max(a[i], a[k]) + f(j, k + 1));
		res = min(res, max(a[j], a[k]) + f(i, k + 1));
	}
	return res;
}

void go(int i, int j) {
	if (j >= n) {
		if (i < n) printf("%d\n", i + 1);
		return;
	}
	int res = f(i, j), k = j + 1;
	if (res == max(a[i], a[j]) + f(k, k + 1)) {
		printf("%d %d\n", i + 1, j + 1);
		go(k, k + 1);
		return;
	}
	if (res == max(a[i], a[k]) + f(j, k + 1)) {
		printf("%d %d\n", i + 1, k + 1);
		go(j, k + 1);
		return;
	}
	printf("%d %d\n", j + 1, k + 1);
	go(i, k + 1);
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n;
	REP (i, n) cin >> a[i];
	CL(F, -1);
	printf("%d\n", f(0, 1));
	go(0, 1);
	return 0;
}