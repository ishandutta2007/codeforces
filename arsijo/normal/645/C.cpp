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
#ifndef LOCAL
#define endl "\n"
#endif
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

inline bool in(int a, int b, int c) {
	return a <= b && b <= c;
}

int main() {

	sync;
	cout.precision(12);
	cout << fixed;
	srand(time(NULL));

#ifdef LOCAL
	input;
	//output;
#else

#endif

	int n, m;
	cin >> n >> m;

	string s;
	cin >> s;

	int left[n];
	for(int i = 0; i < n; i++) {
		left[i] = (s[i] == '0' ? i : (i == 0 ? -1 : left[i - 1]));
	}
	int right[n];
	for(int i = n - 1; i >= 0; i--) {
		right[i] = (s[i] == '0' ? i : (i == n - 1 ? n : right[i + 1]));
	}
	int ans = INT_MAX;
	for(int sum = 0, l = 0, r = 0; r < n; r++) {
		if(s[r] == '0')
		sum++;
		while(sum >= m + 2) {
			if(s[l++] == '0')
			sum--;
		}
		while(l < r && s[l] == '1')
			l++;
		if(sum == m + 1) {
			int p = (l + r) >> 1;
			for(int i = -1; i < 2; i++) {
				int pos = p + i;
				if(in(l, pos, r)) {
					int t = left[pos];
					if(in(l, t, r)) {
						ans = min(ans, max(t - l, r - t));
					}
					t = right[pos];
					if(in(l, t, r)){
						ans = min(ans, max(t - l, r - t));
					}
				}
			}
		}
	}

	cout << ans;

}