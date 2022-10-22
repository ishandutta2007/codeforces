//MIPT Cryptozoology
//Room 202
#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:128000000")
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <bitset>
#include <set>
#include <map>
#include <cassert>
#include <memory.h>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define itn int

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

typedef long long li;
typedef long long i64;
typedef double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

void precalc();

int TESTNUM = 0;
#define FILENAME ""

int main() {
	string s = FILENAME;
#ifdef YA
	//assert(!s.empty());
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//cerr<<FILENAME<<endl;
	//assert (s != "change me please");
	clock_t start = clock();
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(FILENAME ".in", "r", stdin);
	//freopen(FILENAME ".out", "w", stdout);
	cin.tie(0);
#endif
	cout.sync_with_stdio(0);
	cout.precision(10);
	cout << fixed;
	precalc();
	int t = 1;
	//cin >> t;
	while (t--) {
		++TESTNUM;
		solve();
	}
#ifdef YA
	cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
	return 0;
}

//#define int li

/*int pr[] = { 97, 2011 };
int mods[] = { 1000000007, 1000000009 };

const int C = 100500;
int powers[2][C];*/

//int MOD = 1000000007;

//int c[5010][5010];

template<typename T>
T binpow(T q, T w, T mod) {
	if (!w)
		return 1 % mod;
	if (w & 1)
		return q * 1LL * binpow(q, w - 1, mod) % mod;
	return binpow(q * 1LL * q % mod, w / 2, mod);
}

void precalc() {

	/*for (int w = 0; w < 2; ++w) {
	powers[w][0] = 1;
	for (int j = 1; j < C; ++j) {
	powers[w][j] = (powers[w][j - 1] * 1LL * pr[w]) % mods[w];
	}
	}*/

	/*for (int i = 0; i < 5010; ++i) {
	c[i][i] = c[i][0] = 1;
	for (int j = 1; j < i; ++j) {
	c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	}
	}*/
}

template<typename T>
T gcd(T q, T w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}
template<typename T>
T lcm(T q, T w) {
	return q / gcd(q, w) * w;
}

inline int nxt(){
	int x;
	cin >> x;
	return x;
}

//#define int li

struct shop
{
	int city;
	li numItems;
	li cost;
};

int n;
const int maxN = 5005;
vector<int> e[maxN];
vector<int> bfsd[maxN];

vector<int> bfs(int v)
{
	vector<int> d(n, -1);
	d[v] = 0;

	deque<int> bfsQueue;
	bfsQueue.push_back(v);

	while (!bfsQueue.empty())
	{
		int v = bfsQueue.front();
		bfsQueue.pop_front();

		for (int u: e[v])
			if (d[u] == -1)
			{
				d[u] = d[v] + 1;
				bfsQueue.push_back(u);
			}
	}

	return d;
}

int deliverTo;
li needAmount;
li maxCost;
vector<shop> shops;

bool can(int d)
{
	li need = needAmount;
	li cost = 0;

	for (int i = 0; i < shops.size(); i++)
		if (bfsd[deliverTo][shops[i].city] != -1 && bfsd[deliverTo][shops[i].city] <= d)
		{
			li take = min(need, shops[i].numItems);
			cost += take * (li)shops[i].cost;
			need -= take;

			if (need == 0) break;
			if (cost > maxCost) return false;
		}

	if (need != 0) return false;

	return cost <= maxCost;
}

void solve() {
	int m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;

		e[u].push_back(v);
		e[v].push_back(u);
	}

	int nShops;
	cin >> nShops;

	shops.resize(nShops);
	for (int i = 0; i < nShops; i++)
	{
		cin >> shops[i].city >> shops[i].numItems >> shops[i].cost;
		shops[i].city--;
	}

	sort(shops.begin(), shops.end(), [](const shop& a, const shop& b) { return a.cost < b.cost; });

	for (int i = 0; i < n; i++)
		bfsd[i] = bfs(i);

	int nq;
	cin >> nq;

	for (int i = 0; i < nq; i++)
	{
		cin >> deliverTo >> needAmount >> maxCost;
    	deliverTo--;

		if (can(0))
		{
			cout << 0 << "\n";
			continue;
		}

		if (!can(n))
		{
			cout << -1 << "\n";
			continue;
		}

        // low can't, high can
		int low = 0, high = n;
		
        while (low + 1 != high)
		{
			int m = (low + high) / 2;

			if (can(m))
				high = m;
			else
				low = m;
		}

		cout << high << "\n";
	}
}