#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 9;
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

	int ar[n];
	for(int i = 0; i < n; i++)
	cin >> ar[i];

	for(int i = 0; i < (n << 2); i++){
		swap(ar[rand() % n], ar[rand() % n]);
	}

	ll tt[n];

	int ans = 0;

	set<pair<int, int> > ss;

	map<ll, int> m;
	for(int i = 0; i < n; i++)
	m[ar[i]]++;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j || ss.find(make_pair(ar[i], ar[j])) != ss.end())
			continue;
			ss.insert(make_pair(ar[i], ar[j]));
			m[ar[i]]--;
			m[ar[j]]--;
			tt[0] = ar[i];
			tt[1] = ar[j];
			int sz = 2;
			map<ll, int>::iterator it = m.find(tt[sz - 2] + tt[sz - 1]);
			while(true) {
				it = m.find(tt[sz - 2] + tt[sz - 1]);
				if(it == m.end() || it->second == 0)
					break;
				tt[sz] = tt[sz - 2] + tt[sz - 1];
				m[tt[sz]]--;
				sz++;
			}
			for(int i = 0; i < sz; i++)
			m[tt[i]]++;
			ans = max(ans, sz);
		}
	}

	cout << ans;

}