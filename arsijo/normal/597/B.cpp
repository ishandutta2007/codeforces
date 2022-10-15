#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define endl "\n"
typedef long long ll;
typedef unsigned int ui;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-10;
const ll MOD = 1e9 + 9;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

#ifdef LOCAL
const int MAX = 1000;
#else
const int MAX = 2e5 + 1;
#endif

int main() {

	sync;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	vector<ii> vec;
	vec.reserve(n);

	for(int i = 0; i < n; i++){
		int l, r;
		cin >> l >> r;
		vec.push_back(make_pair(r, l));
	}

	sort(vec.begin(), vec.end());

	int ans = 1, r = vec[0].first;
	for(int i = 1; i < n; i++)
		if(vec[i].second > r){
			r = vec[i].first;
			ans++;
		}

	cout << ans;

}