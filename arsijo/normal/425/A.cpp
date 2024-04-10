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
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
const ld E = 1e-7;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 100;
#else
const ll MAX = 1e6 + 1;
#endif

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int n, k;
	cin >> n >> k;

	int ar[n];
	for(int i = 0; i < n; i++)
		cin >> ar[i];

	int ans = INT_MIN;

	int a[n], b[n];

	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++){
			int A = j - i + 1;
			int B = n - A;
			copy(ar + i, ar + j + 1, a);
			copy(ar, ar + i, b);
			copy(ar + j + 1, ar + n, b + i);
			sort(a, a + A);
			sort(b, b + B);
			for(int l = 0, r = B - 1, q = k; l < A && r >= 0 && a[l] < b[r] && q; l++, r--, --q)
				swap(a[l], b[r]);
			int sum = 0;
			for(int i = 0; i < A; i++)
				sum += a[i];
			ans = max(ans, sum);
		}

	cout << ans;

}