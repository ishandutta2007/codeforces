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

int sqr(int n) {
	if (n == 0) return 0;
	int x, y = n;
	do {
		x = y;
		y = (x + n / x) / 2;
	} while (x > y);
	return x;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	int x, y, r;
	cin >> x >> y;
	r = sqr(x * x + y * y);
	if (x == 0 || y == 0 || r * r == x * x + y * y)
		puts("black");
	else {
		if (x * y < 0) r ^= 1;
		puts(r & 1 ? "white" : "black");
	}
	return 0;
}