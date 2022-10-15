#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define endl "\n"
#define def(f) make(#f);
typedef long long ll;
typedef unsigned int ui;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef double ld;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-8;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

int main() {

	sync;
#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	int a[n - 1], b[n - 1];
	for(int i = 0; i < n - 1; i++)
		cin >> a[i];
	for(int i = 0; i < n - 1; i++)
		cin >> b[i];

	int c[n];
	for(int i = 0; i < n; i++)
		cin >> c[i];

	int s1[n];
	s1[0] = 0;
	for(int i = 1; i < n; i++){
		s1[i] = s1[i - 1] + a[i - 1];
	}
	int s2[n + 1];
	s2[n - 1] = 0;
	for(int i = n - 2; i >= 0; i--){
		s2[i] = s2[i + 1] + b[i];
	}

	int ans = INT_MAX;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			ans = min(ans, s1[i] + s1[j] + s2[i] + s2[j] + c[i] + c[j]);
		}
	}

	cout << ans;

}