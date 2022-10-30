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

int n;
int p[111], f[111];

int F(int i) { return f[i] == i ? i : f[i] = F(f[i]); }

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n;
	REP (i, n) cin >> p[i], --p[i], f[i] = i;
	REP (i, n) {
		int d;
		cin >> d;
		if (i - d >= 0) f[F(i - d)] = F(i);
		if (i + d < n) f[F(i + d)] = F(i);
	}
	REP (i, n) if (F(i) != F(p[i])) {
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}