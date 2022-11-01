#include <iostream> 
#include <cstdio> 
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
//#include <unordered_set> 
using namespace std;
typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define mp make_pair 
#define pb push_back
#define y1 botva
#define all(s) s.begin(), s.end() 
void solve();

#define NAME "changemeplease"
int main() {
#ifdef YA 
	//cerr << NAME << endl;
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	clock_t start = clock();
#else 
	//freopen("input.txt", "r", stdin); 
	//freopen("output.txt", "w", stdout); 
#endif 
	ios_base::sync_with_stdio(false);
	cout << fixed;
	cout.precision(10);
	int t = 1;
	//cin >> t;	 
	for (int i = 1; i <= t; ++i) {
		//cout << "Case #" << i << ": ";
		solve();
	}
#ifdef YA 
	//cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif 
	return 0;
}

int n, m, q;
vector <li> a;
vector < vector <int> > b;
vector <int> heavy;
vector <vector <bool> > heavyBool;
vector < vector <int> > inter;

vector <li> val;
vector <li> add;

void solve() {
	cin >> n >> m >> q;
	a.resize(n);

	val.resize(n);
	add.resize(n);
	
	for (int i = 0; i < n ;++i) {
		cin >> a[i];
	}
	b.resize(m);
	for (int i = 0; i < m; ++i) {
		int sz;
		cin >> sz;
		b[i].resize(sz);
		for (int j = 0; j < sz; ++j) {
			cin >> b[i][j];
			--b[i][j];
			val[i] += a[b[i][j]];
		}
	}
	
	for (int i = 0; i < m; ++i) {
		if (b[i].size() > sqrt(ld(n))) {
			heavy.push_back(i);
			heavyBool.push_back(vector <bool> (n));
			for (int j = 0; j < b[i].size(); ++j) {
				heavyBool[heavy.size() - 1][b[i][j]] = true;	
			}
		}
	}

	inter.assign(m, vector <int> (heavy.size()));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < heavy.size(); ++j) {
			for (int t = 0; t < b[i].size(); ++t) {
				if (heavyBool[j][b[i][t]]) {
					++inter[i][j];
				}
			}
		}
	}

	for (int t = 0; t < q; ++t) {
		char c;
		int id;
		cin >> c >> id;
		--id;
		if (c == '+') {
			li x;
			cin >> x;
			if (b[id].size() > sqrtl(ld(n))) {
				add[id] += x;
			}
			else {
				for (int j = 0; j < b[id].size(); ++j) {
					a[b[id][j]] += x;
				}
				for (int j = 0; j < heavy.size(); ++j) {
					val[heavy[j]] += x * inter[id][j];
				}
			}
		}
		if (c == '?') {
			li ans = 0;
			if (b[id].size() > sqrtl(ld(n))) {
				ans = val[id];
				for (int i = 0; i < heavy.size(); ++i) {
					ans += add[heavy[i]] * inter[id][i];
				}
			}
			else {
				for (int i = 0; i < b[id].size(); ++i) {
					ans += a[b[id][i]];
				}
				for (int i = 0; i < heavy.size(); ++i) {
					ans += add[heavy[i]] * inter[id][i];
				}
			}
			cout << ans << "\n";
		}
	}
}