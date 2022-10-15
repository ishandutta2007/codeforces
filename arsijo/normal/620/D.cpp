#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-11;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#define endl "\n"
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".dat"); _write(x ".sol")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int main() {

	sync;
	cout.precision(12);
	cout << fixed;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	ll a[n];
	for(int i = 0; i < n; i++)
	cin >> a[i];

	int m;
	cin >> m;

	ll b[m];
	for(int i = 0; i < m; i++)
	cin >> b[i];

	ll sum1 = 0, sum2 = 0;
	for(int i = 0; i < n; i++)
	sum1 += a[i];
	for(int i = 0; i < m; i++)
	sum2 += b[i];

	ll best_ans = abs(sum1 - sum2);
	vector<ii> r;

	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++) {
		ll res = abs((sum1 - a[i] + b[j]) - (sum2 - b[j] + a[i]));
		if(best_ans > res) {
			best_ans = res;
			r.clear();
			r.push_back(make_pair(i + 1, j + 1));
		}
	}

	map<ll, ii> mp;

	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			mp[a[i] + a[j]] = make_pair(i + 1, j + 1);
		}
	}

	for(int i = 0; i < m; i++) {
		for(int j = i + 1; j < m; j++) {
			ll q = sum1 - sum2 + 2 * (b[i] + b[j]);
			map<ll, ii>::iterator it = mp.lower_bound(q / 2);
			if(it != mp.end()) {
				ll res = abs((sum1 - it->first + b[i] + b[j]) - (sum2 - b[i] - b[j] + it->first));
				if(best_ans > res) {
					best_ans = res;
					r.clear();
					r.push_back(make_pair(it->second.first, i + 1));
					r.push_back(make_pair(it->second.second, j + 1));
				}
			}
			if(it != mp.begin()) {
				it--;
				ll res = abs((sum1 - it->first + b[i] + b[j]) - (sum2 - b[i] - b[j] + it->first));
				if(best_ans > res) {
					best_ans = res;
					r.clear();
					r.push_back(make_pair(it->second.first, i + 1));
					r.push_back(make_pair(it->second.second, j + 1));
				}
			}

		}
	}

	cout << best_ans << endl;
	cout << r.size() << endl;
	for(int i = 0; i < (int) r.size(); i++)
		cout << r[i].first << " " << r[i].second << endl;

}