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

bool isPrime(int n) {
	for (int y = 2; y * y <= n; ++y)
		if (n % y == 0) 
			return false;
	return true;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	int n;
	cin >> n;
	if (n == 2) {
		puts("-1");
		return 0;
	}
	int z[] = {2 * 3, 2 * 5, 3 * 5}, x = 6;
	REP (i, n) {
		for (; !isPrime(++x); );
		cout << z[i % 3] * x << endl;
	}
	return 0;
}