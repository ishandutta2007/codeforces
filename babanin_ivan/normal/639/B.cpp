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

void print(vector <pair <int, int> >& a) {
	for (auto t : a) {
		cout << t.first + 1 << " " << t.second + 1<< "\n";
	}
	exit(0);
}

void solve() {
	int n, h, d;
	cin >> n >> d >> h;

	if (d > 2 * h) {
		printerr();
	}

	vector <pair <int, int> > result;

	if (h == 1) {
		if (d == 1) {
			if (n > 2) {
				printerr();
			}
			for (int i = 1; i < n; ++i) 
				result.push_back(mp(0, i));
			print(result);
		}
		
		//d == 2
		if (n == 2) {
			printerr();
		}

		for (int i = 1; i < n; ++i) {
			result.push_back(mp(0, i));
		}
		print(result);
	}


	if (n <= d) {
		printerr();
	}

	for (int i = 1; i <= h; ++i) {
		result.push_back(mp(i - 1, i));
	}

	int prev = 0;
	for (int j = 1; j <= d - h; ++j) {
		result.push_back(mp(prev, j + h));
		prev = j + h;
	}

	for (int i = d + 1; i < n; ++i) {
		result.push_back(mp(i, 1));
	}
	
	print(result);
}