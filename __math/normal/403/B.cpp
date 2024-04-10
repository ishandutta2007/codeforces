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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

bool prime[1000001];
vector<int> prs;
void init_prime() {
	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i < sizeof(prime); i++) if (prime[i])
		for (int j = i * 2; j < sizeof(prime); j += i) prime[j] = false;
	for (int i = 2; i < sizeof(prime); i++) if (prime[i]) prs.push_back(i);
}


int n, m;
ll a[5000], b[5000];

int get_score(ll g) {
	int score = 0;
	FOR(j, m) {
		while (g % b[j] == 0) {
			g /= b[j];
			score--;
		}
	}
	for (auto p : prs) {
		if (ll(p) * p > g) break;
		while (g % p == 0) {
			g /= p;
			score++;
		}
	}
	if (g != 1) score++;
	return score;
}

int main() {
	init_prime();

	cin >> n >> m;
	FOR(i, n) cin >> a[i];
	FOR(i, m) cin >> b[i];
	vector<ll> gcds;
	gcds.push_back(a[0]);
	for(int i = 1; i < n; i++){
		ll g = gcd(gcds[i - 1], a[i]);
		gcds.push_back(g);
	}

	ll used = 1;
	ll ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		ll g = gcds[i] / used;
		int score = get_score(g);
		if (score < 0) {
			used *= g;
		}
		ll x = a[i] / used;
		ans += get_score(x);
	}
	
	cout << ans << endl;

	return 0;
}