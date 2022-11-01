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

template<class T> ll mod_pow(T a, T n, T mod) {
	ll ret = 1;
	ll p = a % mod;
	while (n) {
		if (n & 1) ret = ret * p % mod;
		p = p * p % mod;
		n >>= 1;
	}
	return ret;
}

// 1-indexed
template<class T>
class BIT {
	T bit[ten(7) + ten(6)];
	int n;

public:
	BIT() {
		clear(ten(7) + ten(6) - 10);
	}

	void clear(int N) {
		n = N;
		memset(bit, 0, sizeof(bit));
	}

	T sum(int i) {
		T s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}

	void add(int i, T x) {
		while (i <= n) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

int k, n[3], t[3];
BIT<int> b[3];

bool ok(int time) {
	FOR(i, 3) {
		if (b[i].sum(time + 1) >= n[i]) return false;
		time += t[i];
	}
	return true;
}

int main() {

	cin >> k;
	FOR(i, 3) cin >> n[i];
	FOR(i, 3) cin >> t[i];

	priority_queue<int, vector<int>, greater<int>> evt;
	evt.push(0);
	int last_time = 0;
	FOR(i, k) {
		while (true) {
			int time = evt.top();
			if (ok(time)) {

				int cur_time = time + 1;
				FOR(j, 3) {
					b[j].add(cur_time, 1);
					b[j].add(cur_time + t[j], -1);
					cur_time += t[j];
				}
				evt.push(time + t[0]);
				evt.push(time + t[1]);
				evt.push(time + t[2]);
				evt.push(time + t[0] + t[1]);
				evt.push(time + t[0] + t[2]);
				evt.push(time + t[1] + t[2]);
				evt.push(time + t[0] + t[1] + t[2]);
				last_time = time + t[0] + t[1] + t[2];
				break;
			} else {
				evt.pop();
			}
		}
	}

	cout << last_time << endl;

}