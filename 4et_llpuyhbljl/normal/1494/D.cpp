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
const ll INF = 1e18;
const int mod = 998244353;
const ld eps = 1e-4, pi = acos(-1);
const int maxN = 100010, maxT = 10010, A = 179;
ll bp(ll et, ll b) {
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
void panic() {
	cout << "NO\n";
	exit(0);
}
vector<int>cst;
int f[maxN];
int p[maxN];
int find(int v) { return (f[v] == v ? v : f[v] = find(f[v])); }
void solve() {
	int n;
	cin >> n;
	cst.assign(n, 0);
	vector<vector<int>>a(n, vector<int>(n));
	vector<pair<int, int>>ans;
	vector<tuple<int, int, int>>t;
	for (int i = 0; i < n; ++i) {
		f[i] = i;
		p[i] = i;
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
			if (i == j)cst[i] = a[i][j];
			t.push_back(make_tuple(a[i][j], i, j));
		}
	}
	sort(t.begin(), t.end());
	for (int i = 0; i < t.size();) {
		int j = i;
		int a, b;
		int my_c, cnt = 0;
		tie(my_c, a, b) = t[i];
		while (j < t.size()) {
			int a, b, c;
			tie(a, b, c) = t[j];
			if (a == my_c) {
				++j;
				if (find(b) != find(c))++cnt;
			}
			else break;
		}
		if (cnt == 0) {
			i = j;
			continue;
		}
		vector<vector<int>>g(n);
		vector<int>used(n);
		for (int k = i; k < j; ++k) {
			int a, b, c;
			tie(a, b, c) = t[k];
			if (find(b) != find(c)) {
				++cnt;
				used[c] = used[b] = 1;
				g[b].push_back(c);
				g[c].push_back(b);
			}
		}
		for (int k = 0; k < used.size(); ++k) {
			if (used[k] == 1) {
				cst.push_back(my_c);
				queue<int>q1;
				queue<int>q;
				q.push(k);
				q1.push(k);
				used[k] = 2;
				while (!q.empty()) {
					int b = q.front();
					q.pop();
					int v = find(b);
					if (p[v] != n) {
						ans.push_back({ p[v],n });
						p[v] = n;
					}
					for (auto x : g[b]) {
						if (used[x] == 1) {
							++used[x];
							q.push(x);
							q1.push(x);
						}
					}
				}
				int v = q1.front();
				while (!q1.empty()) {
					int b = q1.front();
					q1.pop();
					if (find(b) != find(v))f[find(b)] = find(v);
					//q1.pop();

				}
				++n;
			}
		}
		i = j;
	}
	cout << n << "\n";
	for (auto x : cst)cout << x << " "; cout << "\n";
	cout << n << "\n";
	for (auto x : ans)cout << x.first + 1 << " " << x.second + 1 << "\n";

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