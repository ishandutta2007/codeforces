#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef long long ll;
typedef unsigned int ui;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef vector<int>::iterator vit;
const ld E = 1e-7;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 100;
#else
const ll MAX = 2e5 + 1;
#endif

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	int x[n];
	for(int i = 0; i < n; i++)
	cin >> x[i];

	bool ans = false;

	for(int i = 1; i < n; i++) {
		for(int j = 1; j < n; j++) {
			if(abs(i - j) >= 2) {
				for(int q = 0; q < 2; q++, swap(i, j)) {
					int f1 = min(x[i - 1], x[i]), f2 = min(x[j - 1], x[j]);
					int s1 = max(x[i - 1], x[i]), s2 = max(x[j - 1], x[j]);
					if(f1 < f2 && f2 < s1 && s1 < s2)
					ans = true;
				}
			}
		}
	}

	cout << (ans ? "yes" : "no");

}