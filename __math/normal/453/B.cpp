#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>

using namespace std;
const int MOD = 1000000007; // check!!!
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ x; }
int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }
ll fastMin(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ x; }
ll fastMax(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

const int C = 16;
vector<int> pr;
int F[60];

//f
void init_prime() {
	bool prime[60];
	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i < sizeof(prime); i++) if (prime[i])
		for (int j = i * 2; j < sizeof(prime); j += i) prime[j] = false;
	for (int i = 2; i < sizeof(prime); i++) if (prime[i]) {
		for (int j = i; j < sizeof(prime); j += i) F[j] |= (1 << sz(pr));
		pr.push_back(i);
	}
}

int n;
int a[100];
int nxt[100][1 << C];
int dp[100][1 << C];
int cho[100][1 << C];

int dfs(int id, int S) {
	if (id == n) return 0;
	if (dp[id][S] != -1) return dp[id][S];
	int &ret = dp[id][S];

	for (int i = 1; i < 55; i++) {
		if (S & F[i]) continue;
		int x = dfs(id + 1, S | F[i]) + abs(a[id] - i);
		if (ret == -1 || ret > x) {
			ret = x;
			cho[id][S] = i;
			nxt[id][S] = (S | F[i]);
		}
	}
	return ret;
}

int main() {
	init_prime();

	cin >> n;
	FOR(i, n) cin >> a[i];

	memset(dp, -1, sizeof(dp));

	dfs(0, 0);

	vector<int> anses;
	int S = 0;
	FOR(i, n) {
		anses.push_back(cho[i][S]);
		S = nxt[i][S];
	}

	FOR(i, n) {
		printf("%d%c",anses[i],i==n-1?'\n':' ');
	}

}