#pragma comment (linker, "/STACK:128000000")
#include <iostream> 
#include <cstdio> 
#include <fstream>
#include <functional>
#include <set> 
#include <map> 
#include <vector> 
#include <queue> 
#include <stack> 
#include <cmath> 
#include <algorithm> 
#include <cstring> 
#include <bitset> 
#include <ctime> 
#include <sstream>
#include <stack> 
#include <cassert> 
#include <list> 
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long long i64;
typedef pair <int, int> pi;
typedef vector <int> vi;
typedef double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

//int timer = 0;
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
	int t = 1;

	//cin >> t;
	for (int i = 1; i <= t; ++i) {
		//++timer;
		//cout << "Case #" << i << ": ";
		solve();
	}
#ifdef YA
	cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
	return 0;
}

#define int li

vector <vector <int> > g;
int n;
int X, Y;

void solve1() {
	vector <int> color(n, -1);

	queue <int> q;
	q.push(0);
	color[0] = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int to : g[v]) {
			if (color[to] == -1) {
				q.push(to);
				color[to] = !color[v];
			}
		}
	}

	int k[2];
	k[0] = k[1] = 0;

	for (int x : color) {
		++k[x];
	}

	if (k[0] * k[1] > n - 1) {
		cout << (n - 1) * Y;
	}
	else {
		cout << (n - 2) * Y + X;
	}
}

vector <vector <int> > dp;

void dfs(int v, int p=-1) {
	if (p != -1) {
		g[v].erase(find(g[v].begin(), g[v].end(), p));
	}

	if (g[v].size() == 0) {
		dp[v][0] = dp[v][1] = 1;
		return;
	}

	int sumall = 0;

	set <pair <int, int> > q;

	for (int to : g[v]) {
		dfs(to, v);

		sumall += dp[to][1];

		q.insert(mp(dp[to][0] - dp[to][1], to));
	}

	dp[v][0] = dp[v][1] = sumall + 1;

	if (q.begin()->first <= 0) {
		dp[v][0] = sumall + q.begin()->first;
	}

	dp[v][1] = dp[v][0];

	if (q.size() >= 2) {
		int tmp = 0;
		for (int i = 0; i < 2; ++i) {
			tmp += q.begin()->first;
			q.erase(q.begin());
		}
		dp[v][1] = min(dp[v][1], sumall + tmp - 1);
	}
}

void solve() {
	cin >> n >> X >> Y;
	g.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >>  x >> y;
		--x;
		--y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	if (X >= Y) {
		solve1();
		return;
	}
	dp.resize(n, vector <int>(2));
	dfs(0);
	int tmp = dp[0][1] - 1;

	cout << Y * tmp + X * (n - 1 - tmp);
}