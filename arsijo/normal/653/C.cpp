#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-13;
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
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 15e4 + 1;
int ar[MAX];
bool ok[MAX];

inline int add(int n, int i) {
	if (i < 0 || i >= n)
		return 0;
	if (!ok[i]
			&& (i & 1 ?
					((i == n - 1 ? true : ar[i] > ar[i + 1])
							&& (ar[i] > ar[i - 1])) :
					(i == 0 ? true : ar[i] < ar[i - 1])
							&& (i == n - 1 ? true : ar[i] < ar[i + 1]))) {
		return 1;
	}
	return 0;
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

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> ar[i];
	for(int i = 0; i < n; i++) {
		if(i & 1) {
			ok[i] = (i == n - 1 ? true : ar[i] > ar[i + 1]) && (ar[i] > ar[i - 1]);
		} else {
			ok[i] = (i == 0 ? true : ar[i] < ar[i - 1]) && (i == n - 1 ? true : ar[i] < ar[i + 1]);
		}
	}

	int t = 0;
	for(int i = 0; i < n; i++) {
		if(ok[i])
		t++;
	}

	if(n - t > 10) {
		cout << 0;
		return 0;
	}

	int ans1 = 0, ans2 = 0;
	set<int> s;
	set<int>::iterator it;
	int q, e;
	bool pr;
	for(int i = 0; i < n; i++) {
		if(!ok[i]) {
			for(int j = 0; j < n; j++) {
				if(i == j)
				continue;
				q = t;
				pr = ok[j];
				if(ok[j]) {
					q--;
					ok[j] = false;
				}
				swap(ar[i], ar[j]);
				s.clear();
				for(e = -1; e <= 1; e++) {
					s.insert(i + e);
					s.insert(j + e);
				}
				for(it = s.begin(); it != s.end(); it++) {
					if(add(n, *it)) {
						q++;
					}
				}
				swap(ar[i], ar[j]);
				ok[j] = pr;
				if(q == n) {
					if(!ok[j])
					ans2++;
					else
					ans1++;
				}
			}
		}
	}

	cout << ans1 + ans2 / 2;

}