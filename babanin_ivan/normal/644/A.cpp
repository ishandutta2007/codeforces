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

void printerr() {
	cout << -1 << endl;
	exit(0);
}

void solve() {
	int n;
	int a, b;
	cin >> n >> a >> b;
	if (n > a * b) {
		printerr();
	}

	vector <vector <pair <int, int> >> poses(2);

	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			poses[(i + j) % 2].push_back(mp(i, j));
		}
	}

	vector <vector <int> > guys(2);
	for (int j = 1; j <= n; ++j) {
		guys[j % 2].push_back(j);
	}
	if (guys[0].size() > guys[1].size()) {
		swap(guys[0], guys[1]);
	}
	if (poses[0].size() > poses[1].size()) {
		swap(poses[0], poses[1]);
	}

	vector <vector <int> > ans(a, vector <int>(b));

	for (int i = 0; i < 2; ++i) {
		if (guys[i].size() > poses[i].size()) {
			printerr();
		}
		for (int j = 0; j < guys[i].size(); ++j) {
			ans[poses[i][j].first][poses[i][j].second] = guys[i][j];
		}
	}

	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}