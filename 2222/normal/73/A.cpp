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

int X, Y, Z, K;

ll f(int n, int m, int k) {
	if (n + m <= k) return ll(n) * m;
	if (n > m) swap(n, m);
	int x = min(k / 2, n), y = k - x;
	return ll(x) * y;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> X >> Y >> Z >> K;
	K += 3;
	if (X + Y + Z <= K) 
		cout << (ll)X * Y * Z << endl;
	else {
		ll res = 0;
		for (int x = 1; x <= X && x <= K; ++x) 
			res = max(res, x * f(Y, Z, K - x));
		cout << res << endl;
	}
	return 0;
}