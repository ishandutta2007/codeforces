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
	if (i < j)swap(i, j);
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
const ll INF = 1e9;
const int mod = 1000000007;
const ld eps = 1e-4, pi = acos(-1);
const int maxN = 100010, maxT = 50010, A = 179;
ll bp(ll et, ll b) {
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
void panic() {
	cout << "No\n";
	exit(0);
}
void succes(vector<int>a) {
	cout << "Yes\n";
	for (auto x : a) {
		cout << x << " ";
	}
	exit(0);
}
vector<int>inter;
vector<int>ct;
vector<vector<int>>a;
int n, sz;
vector<vector<int>>run(vector<int>pos) {
	vector<vector<int>>res(3);
	for (int i = 0; i < n; ++i) {
		int tmp =  ct[i];
		for (auto x : pos)if (a[i][x] != a[0][x])--tmp;
		if (tmp >= 3) {
			res.push_back({});
			return res;
		}
		res[2 - tmp].push_back(i);
	}
	return res;
}
pair<int, int> f(int p1, int p2) {
	vector<vector<int>>tmp = run({ inter[p1],inter[p2] });
	if (tmp.size() >= 4)return { -1,-1 };
	if (!tmp[0].empty()) {
		int id = tmp[0][0];
		int d = inter[p1], s = inter[p2];
		for (auto x : tmp[0]) {
			if (a[x][d] != a[id][d] || a[x][s] != a[id][s])return { -1,-1 };
		}
		for (auto x : tmp[1]) {
			if (a[x][d] != a[id][d] && a[x][s] != a[id][s])return { -1,-1 };
		}
		return { a[id][d],a[id][s] };
	}
	if (!tmp[1].empty()) {
		int id = tmp[1][0];
		int d = a[id][inter[p1]];
		int s = -1;
		bool good = true;
		for (auto x : tmp[1]) {
			if (a[x][inter[p1]] == d || a[x][inter[p2]] == s) {
				continue;
			}
			else {
				if (s == -1)s = a[x][inter[p2]];
				else good = false;
			}
		}
		if (!good) {
			good = true;
			d = -1;
			s = a[id][inter[p2]];
			for (auto x : tmp[1]) {
				if (a[x][inter[p1]] == d || a[x][inter[p2]] == s) {
					continue;
				}
				else {
					if (d == -1)d = a[x][inter[p1]];
					else good = false;
				}
			}
		}
		if (!good)return { -1,-1 };
		return { max(1,d),max(1,s) };
	}
	return { 1,1 };
}
void solve() {
	int m;
	cin >> n >> m;
	ct.assign(n, 0);
	a.assign(n, vector<int>(m));
	vector<set<int>>can(m);
	for (auto& vec : a) {
		for (int j = 0; j < vec.size(); ++j) {
			cin >> vec[j];
			can[j].insert(vec[j]);
		}
	}
	vector<int>ans(m, -1);
	for (int j = 0; j < m; ++j) {
		if (can[j].size() == 1) {
			ans[j] = *(can[j].begin());
		}
		else inter.push_back(j);
	}
	for (int i = 0; i < n; ++i) {
		for (auto x : inter)
			if (a[i][x] != a[0][x])++ct[i];
	}
	if (inter.size() > 2 * n)panic();
	if (inter.size() <= 2)succes(a[0]);
	sz = inter.size();
	for (int i = 0; i < sz; ++i) {
		for (int j = i + 1; j < sz; ++j) {
			int d, s;
			tie(d, s) = f(i, j);
			if (d != -1) {
				ans = a[0];
				ans[inter[i]] = d;
				ans[inter[j]] = s;
				succes(ans);
			}
		}
	}
	panic();
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(3);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("labyrinth.in", "r", stdin); freopen("labyrinth.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}