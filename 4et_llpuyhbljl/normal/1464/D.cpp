#pragma comment(linker, "/STACK:9759095000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<unordered_map>
#include<random>
#include<ctime>
//#define double long double
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
long long gcd(long long i, long long j) {
	if (j == 0)return i;
	else return gcd(j, i % j);
}
#ifdef _DEBUG
ll __builtin_popcount(ll x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
#endif
template<typename T> inline T getint() {
	T val = 0;
	char c;

	bool neg = false;
	while ((c = getchar()) && !(c >= '0' && c <= '9')) {
		neg |= c == '-';
	}

	do {
		val = (val * 10) + c - '0';
	} while ((c = getchar()) && (c >= '0' && c <= '9'));

	return val * (neg ? -1 : 1);
}
//#define int long long
const long long INF = 1e18;
const int mod = 1000000007;
const ld eps = 1e-12, pi = acos(-1);
const int maxN = 500100, maxT = 100010;
void solve(int cs) {
	ll n;
	cin >> n;
	vector<ll>p(n);
	for (auto& x : p) {
		cin >> x;
		--x;
	}
	vector<int>used(n);
	vector<int>lens(max(5LL, n + 1));
	for (int i = 0; i < n; ++i) {
		if (used[i])continue;
		int j = i, ln = 0;
		while (!used[j]) {
			++ln;
			used[j] = 1;
			j = p[j];
		}
		++lens[ln];
	}
	/*if (cs == 25 && n == 10) {
		string s;
		for (int i = 0; i < lens.size(); ++i)s.push_back('0' + lens[i]);
		cout << "36 " << s << "\n";
		return;
	}*/
	int moves = 0;
	for (int i = n; i > 4; --i) {
		for (int j = 0; j < lens[i]; ++j) {
			int tmp = i;
			while (tmp > 4) {
				++lens[3];
				++moves;
				tmp -= 3;
			}
			++lens[tmp];
		}
	}
	while (lens[4] > (n % 3 == 1 ? 1 : 0)) {
		++moves;
		++lens[3];
		++lens[1];
		--lens[4];
	}
	while (lens[1] > 0 && lens[2] > 0) {
		if (lens[1] == 2 && lens[2] == 1)break;
		--lens[1];
		--lens[2];
		++lens[3];
		++moves;
	}
	while (lens[1] > 2 && lens[1] != 4) {
		++lens[3];
		lens[1] -= 3;
		moves += 2;
	}
	while (lens[2] > 2) {
		if (n % 3 == 1) {
			if (lens[4] == 1) {
				lens[3] += 2;
				moves += 2;
				lens[4] = 0;
				--lens[2];
				continue;
			}
		}
		lens[3] += 2;
		lens[2] -= 3;
		moves += 3;
	}
	if (lens[1] == 4) {
		lens[2] += 2;
		lens[1] = 0;
		moves += 2;
	}
	if (lens[1] == 2) {
		lens[2] += 1;
		lens[1] = 0;
		moves += 1;
	}
	if (lens[1] == 1 && lens[3] != 0) {
		++lens[4];
		--lens[1];
		--lens[3];
		++moves;
	}
	ll res = 1;
	for (int i = 2; i <= 4; ++i) {
		for (int j = 0; j < lens[i]; ++j) {
			res = (res * i) % mod;
		}
	}
	cout << res << " " << moves << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("epic.in", "r", stdin); freopen("epic.out", "w", stdout);
#endif
	int t = 1;
	int cs = 1;
	cin >> t;
	while (t--) {
		solve(cs++);
	}
	return 0;
}