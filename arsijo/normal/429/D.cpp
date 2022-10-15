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
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
const ld E = 1e-4;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 100;
#else
const ll MAX = 1e5 + 1;
#endif

ll ans = LONG_LONG_MAX;
vector<ii> vec;

void update(ii a, ii b){
	ans = min(ans, sqr(a.first - b.first) + sqr(a.second - b.second));
}

bool check_y(ii a, ii b){
	return (a.second != b.second ? a.second < b.second : a.first < b.first);
}

void solve(int l, int r){
	if(r - l <= 3){
		for(int i = l; i < r; i++)
			for(int j = i + 1; j <= r; j++)
				update(vec[i], vec[j]);
		sort(&vec[l], &vec[r + 1], &check_y);
		return;
	}
	int m = (l + r) >> 1;
	int val = vec[m].first;
	solve(l, m);
	solve(m + 1, r);
	static ii t[MAX];
	merge(&vec[l], &vec[m + 1], &vec[m + 1], &vec[r + 1], t, &check_y);
	copy(t, &t[r - l + 1], &vec[l]);
	int size = 0;
	for(int i = l; i <= r; i++){
		if(sqr(vec[i].first - val) < ans){
			for(int j = size - 1; j >= 0 && sqr(vec[i].second - t[j].second) < ans; j--)
				update(vec[i], t[j]);
			t[size++] = vec[i];
		}
	}
}

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;
	vec.reserve(n);

	ll sum = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		sum += x;
		vec.push_back(make_pair(i, sum));
	}

	solve(0, n - 1);
	cout << ans << endl;

}