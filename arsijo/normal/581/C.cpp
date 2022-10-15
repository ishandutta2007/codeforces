#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef long long ll;
typedef unsigned int ui;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
#ifdef LOCAL
typedef double ld;
#else
typedef double ld;
#endif
typedef vector<int>::iterator vit;
typedef pair<ld, int> li;
const ld E = 1e-8;

#ifdef LOCAL
const int MAX = 2e6;
#else
const int MAX = 1e7;
#endif

int main() {

	sync;

#ifdef LOCAL
	input;
	//output;
#else

#endif

	int n, k;
	cin >> n >> k;

	int ar[101];
	ms(ar);

	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		ar[a]++;
	}

	for(int i = 9; i >= 0; i--){
		for(int j = 0; j <= 9; j++){
			int q = min((10 - i) * ar[j * 10 + i], k) / (10 - i);
			k -= q * (10 - i);
			ar[j * 10 + i] -= q;
			ar[(j + 1) * 10] += q;
		}
	}

	ll ans = 0;

	for(int i = 0; i <= 100; i++)
		ans += (i / 10) * ar[i];

	cout << ans;

}