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

struct point {
	int x, y;
	void scan() {
		cin >> x >> y;
	}
	point(){}
	point(int x, int y) :x(x), y(y){}
};

int dist(point a, point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void solve() {
	int n;
	cin >> n;
	vector <point> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].scan();
	}

	int ans = 1;
	for (int j = 1; j < n; ++j) {
		if (dist(a[0], a[j]) < dist(a[0], a[ans])) {
			ans = j;
		}
	}

	int A = a[0].y - a[ans].y;
	int B = a[ans].x - a[0].x;
	int C = -A * a[0].x - B * a[0].y;

	int ans2 = 1;
	int tmp = 0;

	for (int j = 1; j < n; ++j) {
		int tmp1 = abs(A * a[j].x + B * a[j].y + C);
		
		if (tmp1 != 0) {
			if (tmp == 0 || tmp1 < tmp) {
				tmp = tmp1;
				ans2 = j;
			}
		}
	}

	cout << 1 << " " << ans + 1 << " " << ans2 + 1;
}