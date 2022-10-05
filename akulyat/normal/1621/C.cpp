#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;


const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
#ifdef DEBUG
	mt19937 rng(1033);
#else
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());	
#endif
int rnd(int mod) { return uniform_int_distribution<int>(0, mod - 1)(rng); }


bool viv = false;
int n;
vector<int> v;

int cnt;


int ask(int pl) {
	cnt++;
	if (viv && cnt > kk) {
		cout << "BREAK" << endl;
		exit(1);
	}

	pl++;
	cout << "? " << pl << endl;
	int ans;
	cin >> ans;
	ans--;

	if (viv)
		cout << "\ti see " << ans << " at " << pl - 1 << endl;
	return ans;
}

void solve() {
	cin >> n;
	vector<bool> done(n, false);
	vector<int> ans(n, -1);

	cnt = 0;
	for (int i = 0; i < n; i++) {
		if (done[i] == false) {
			vector<int> seq;
			while (seq.size() < 2 || seq[0] != seq.back()) {
				seq.push_back(ask(i));
			}
			for (int i = 1; i < seq.size(); i++) {
				ans[seq[i - 1]] = seq[i];
				done[seq[i]] = true;
			}
			for (int j = 2; j < seq.size(); j++)
				ask(i);
		}
	}
	cout << "! ";
	for (auto i : ans)
		cout << i + 1 << ' ';
	cout << endl;
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	cin >> t;
	while (t--)
		solve();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}