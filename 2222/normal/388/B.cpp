#include <algorithm>
#include <iostream>
#include <assert.h>
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

const int n = 30 + 29 + 30;

char adj[n][n + 1];

void put(int x, int y, bool z = true) {
	adj[x - 1][y - 1] = adj[y - 1][x - 1] = z ? 'Y' : 'N';
}

void turn(int i, bool z) {
	if (i == 0) {
		put(1, 61, z);
	} else if (i == 29) {
		put(31, 2, z);
		put(60, 2, z);
	} else {
		i += 2;
		put(i, i + 59, z);
		put(i + 29, i + 59, z);
	}
}

int main() {
	REP (i, n) REP (j, n) adj[i][j] = 'N';
	put(1, 3);
	put(1, 32);
	put(1, 61);
	FOR (i, 3, 31) {
		put(i, i + 1);
		put(i, i + 30);
		put(i + 29, i + 1);
		put(i + 29, i + 30);
	}
	FOR (i, 61, 89)
		put(i, i + 1);
	put(89, 2);
    int k;
	cin >> k;
	REP (i, 30) turn(i, (k & 1 << i) != 0);
	cout << n << endl;
	REP (i, n) puts(adj[i]);
    return 0;
}