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
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

const int size = (int) 2e6 + 1;

int main() {

	sync;
#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	int ar[size];
	ms(ar, 0);

	int ans = 0;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		ar[a]++;
	}

	for(int i = 0; i < size; i++){
		if(i != 0)
			ar[i] += (ar[i - 1] >> 1);
		ans += ar[i] % 2;
	}

	cout << ans;

}