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

void solve() {
	int n, k;
	cin >> n >> k;

	vector <int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	
	vector <li> psum(n);
	
	for (int i = 1; i < psum.size(); ++i) {
		psum[i] = psum[i - 1] + a[i] - a[i - 1];
	}

	li ans = 0;
	
	int l[2];
	l[0] = n / k;
	l[1] = n / k + 1;
	int t[2];
	t[0] = k - (n % k);
	t[1] = n % k;

	vector < pair <int, pair <int, int> > > ps;
	for (int i = 0; i <= t[0]; ++i) {
		for (int j = 0; j <= t[1]; ++j) {
			ps.push_back(mp(i * l[0] + j * l[1], mp(i, j)));
		}
	}
	
	sort(ps.begin(), ps.end());

	vector <vector <li> > dp(t[0] + 1, vector <li> (t[1] + 1, -1));
	dp[0][0] = 0;

	for (auto h: ps) {
		int curpos = h.first;
		int p[2];
		p[0] = h.second.first;
		p[1] = h.second.second;
		if (p[0] + 1 <= t[0]) {
			if (dp[p[0] + 1][p[1]] == -1 || dp[p[0] + 1][p[1]] > dp[p[0]][p[1]] + psum[curpos + l[0] - 1] - psum[curpos]) {
				dp[p[0] + 1][p[1]] = dp[p[0]][p[1]] + psum[curpos + l[0] - 1] - psum[curpos];
			}
		}
		if (p[1] + 1 <= t[1]) {
			if (dp[p[0]][p[1] + 1] == -1 || dp[p[0]][p[1] + 1] > dp[p[0]][p[1]] + psum[curpos + l[1] - 1] - psum[curpos]) {
				dp[p[0]][p[1] + 1] = dp[p[0]][p[1]] + psum[curpos + l[1] - 1] - psum[curpos];
			}
		}
	}
	cout << dp[t[0]][t[1]] << endl;
}