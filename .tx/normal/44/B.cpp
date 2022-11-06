#pragma comment(linker, "/stack:16000000")
#define _CRT_SECURE_NO_DEPRECATE
#define input_file "input.txt"
#define output_file "output.txt"

#include <iostream>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long int64;
const int INF = (int)2e9;
const int64 INF64 = (int64)1e18;
const double EPS = 1e-8;
const double PI = 3.1415926545;

typedef struct {
	int x, y;
} point;

#define sqr(x) ((x)*(x))
#define dist(a, b) sqrt((double)sqr(a.x - b.x) +sqr(a.y - b.y))
//#define dist(x1, y1, x2, y2) sqrt((double)(sqr(x1 - x2)) +sqr(y1 - y2))
#define bound(x, y, n, m) ((x) >= 0 && (y) >= 0 && (x) < (n) && (y) < (m))
#define all(c) c.begin(), c.end()
#define sz(c) (int)(c.size())
#define srt(a) sort(all(a))
#define srtc(a) sort(all(a), cmp)
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int, int>
#define vvi vector< vector<int> >
#define pb(a) push_back(a);
#define mp(a, b) make_pair(a, b);
#define forn(i, n) for (int i = 0; i < (n); i++)
#define ford(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forl(i, n) for (int i = 1; i <= (n); i++)

/* my functions ans structs */


/* main function */
int main() {
//	#if ONLINE_JUDGE
		//freopen(input_file, "r", stdin);
		//freopen(output_file, "w", stdout);
//	#endif
	ios_base::sync_with_stdio(0);
	/* code begin */

	/*int n;
	cin >> n;
	set<string> a;
	string s;
	getchar();
	forn (i, n) {
		getline(cin, s);
		a.insert(s);
	}
	cout << sz(a);
*/
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	int kol = 0;

	for (int i = 0; i <= a && i <= 2*n; i++) {
		double c1 = (n - i*0.5) + 0.0001;
		for (int j = 0; j <= b && j <= c1; j++) {
			double c2 = (n - i*0.5 - j); 
			double k = c2 / 2;
			// k = floor(k)    k <= c
			if (abs(k - floor(k)) <= 0.00001 && k < c + 0.00001)
				kol++;
		}
	}


	cout << kol;

	/* code end */
	return 0;
}//sftnzb