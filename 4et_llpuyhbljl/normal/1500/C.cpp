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
//#include<complex>
#include<numeric>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
//typedef complex<double> base;
using namespace std;
ll gcd(ll i, ll j) {
	if (j == 0)return i;
	else return gcd(j, i % j);
}
#ifdef _DEBUG
int __builtin_popcount(int x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
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
const int INF = 181;
int mod = 1000000007;
const ld eps = 1e-4, pi = acos(-1);
const ll maxN = 1505, maxT = 10010, A = 179;
ll bp(ll et, ll b) {
	ll res = 1;
	for (int i = 16; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
void panic() {
	cout << "NO\n";
	exit(0);
}
bitset<maxN>ar[maxN];
vector<int>build_seq(vector<vector<int>>b){
	int n = b.size(), m = b[0].size();
	vector<int>res;
	set<int>tmp;
	for (int i = 0; i < m; ++i) {
		tmp.insert(i);
		for (int j = 0; j + 1 < n; ++j) {
			ar[i][j] = b[j][i] <= b[j + 1][i];
		}
	}
	bitset<maxN>msk;
	for (int i = 0; i + 1 < n; ++i) {
		msk[i] = 1;
	}
	int ct = msk.count();
	for (; ; ) {
		vector<int>to_del;
		for (auto x : tmp) {
			if ((ar[x] & msk).count() == ct) {
				to_del.push_back(x);
				for (int i = 0; i + 1 < n; ++i) {
					if (b[i][x] < b[i + 1][x])msk[i] = 0;
				}
				ct = msk.count();
			}
		}
		if (to_del.empty())break;
		for (auto x : to_del) {
			tmp.erase(x);
			res.push_back(x);
		}
	}
	//reverse(res.begin(), res.end());
	return res;
}
vector<int> sq;
bool cmp(const vector<int>& a, const vector<int>& b) {
	for (auto x : sq) {
		if (a[x] != b[x])return a[x] < b[x];
	}
	return false;
}
void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>>a(n, vector<int>(m)), b(n, vector<int>(m));
	for (auto& vec : a) {
		for (auto& x : vec)cin >> x;
	}
	for (auto& vec : b) {
		for (auto& x : vec)cin >> x;
	}
	sq = build_seq(b);
	sort(a.begin(), a.end(), cmp);
	reverse(sq.begin(), sq.end());
	if (a == b) {
		cout << sq.size() << "\n";
		for (auto x : sq)cout << x + 1 << " ";
	}
	else cout << "-1\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(12);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*
abbbbbbd
3
1 2
7 8
2 7
*/