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
const int mod[2] = { 998244353, 1000000007 };
const ld eps = 1e-4, pi = acos(-1);
const int maxN = 100010, maxT = 10010, A = 179;
/*ll bp(ll et, ll b) {
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}*/
void panic() {
	cout << "NO\n";
	exit(0);
}
vector<vector<pair<int, int>>>G;
vector<int>sz;
int cnt1 = 0;
void del(int a, int b, int nm) {
	G[a].erase(find(G[a].begin(), G[a].end(), make_pair(b, nm)));
	G[b].erase(find(G[b].begin(), G[b].end(), make_pair(a, nm)));
	if (--sz[a] % 2 == 0)--cnt1;
	else ++cnt1;
	if (--sz[b] % 2 == 0)--cnt1;
	else ++cnt1;
}
void add(int a, int b, int nm) {
	G[a].push_back({ b,nm });
	G[b].push_back({ a,nm });
	if (++sz[a] % 2 == 1)++cnt1;
	else --cnt1;
	if (++sz[b] % 2 == 1)++cnt1;
	else --cnt1;
}
vector<int>used;
vector<int>cnt;
vector<int>way;
void eler(int v) {
	for (; cnt[v] < sz[v]; ++cnt[v]) {
		if (used[G[v][cnt[v]].second])continue;
		used[G[v][cnt[v]].second] = 1;
		eler(G[v][cnt[v]].first);
	}
	way.push_back(v);
}
int n, m;
void to_start() {
	way.clear();
	cnt.assign(n, 0);
	used.assign(m, 0);
}
void build_ans(int mid, vector < pair<int, int>>delited) {
	//reverse(way.begin(), way.end());
	cout << way.size() + 1 + 2 * delited.size() << "\n";
	for (auto x : way)cout << x + 1 << " ";
	cout << -1 << " ";
	for (auto x : delited) {
		cout << x.first + 1 << " " << mid + 1 << " ";
	}
	cout << "\n";
	exit(0);
}
void solve() {
	cin >> n >> m;
	sz.assign(n, 0);
	G.resize(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		add(a, b, i);
	}
	int ct = m;
	for (int mid = 0; mid < n; ++mid) {
		vector<pair<int, int>>delited;
		for (int i = 0; i < sz[mid]; ++i) {
			pair<int, int>x = G[mid][i];
			if (sz[x.first] % 2 == 1) {
				del(mid, x.first, x.second);
				delited.push_back(x);
				--ct;
				--i;
			}
		}
		to_start();
		eler(mid);
		if (way.size() == ct + 1 && (cnt1 == 0 || (cnt1 == 2 && sz[mid] % 2 == 1))) {
			build_ans(mid, delited);
		}
		for (int i = 0; i < delited.size(); ++i) {
			pair<int, int>x = delited[i];
			++ct;
			add(mid, x.first, x.second);
			to_start();
			eler(mid);
			if (way.size() == ct + 1 && (cnt1 == 0 || (cnt1 == 2 && sz[mid] % 2 == 1))) {
				delited.erase(find(delited.begin(), delited.end(), x));
				build_ans(mid, delited);
			}
			--ct;
			del(mid, x.first, x.second);
		}
		for (auto x : delited) {
			add(mid, x.first, x.second);
			++ct;
		}
	}
	cout << "0\n";
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
/*
abbbbbbd
3
1 2
7 8
2 7
*/