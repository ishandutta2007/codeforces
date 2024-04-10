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

vector<ii> vec;

int *pref_min, *pref_max, *suf_min, *suf_max, n;

void pre() {
	sort(vec.begin(), vec.end());
	pref_min = new int[n + 2], pref_max = new int[n + 2], suf_min = new int[n + 2], suf_max =
			new int[n + 2];
	pref_min++, pref_max++, suf_min++, suf_max++;
	pref_min[-1] = suf_min[-1] = pref_min[n] = suf_min[n] = INT_MAX;
	pref_max[-1] = suf_max[-1] = pref_max[n] = suf_max[n] = INT_MIN;
	//cout << "pref" << endl;
	for (int i = 0; i < n; i++) {
		pref_min[i] = min(vec[i].second, pref_min[i - 1]);
		pref_max[i] = max(vec[i].second, pref_max[i - 1]);
		//cout << i << " " << pref_min[i] << " " << pref_max[i] << endl;
	}
	for (int i = n - 1; i >= 0; i--) {
		suf_min[i] = min(vec[i].second, suf_min[i + 1]);
		suf_max[i] = max(vec[i].second, suf_max[i + 1]);
	}
}

bool check(ld c) {
	c *= 2;
	for(int l = 0, r = 0; l < n; l++){
		while(r != n - 1 && (r < l || ((ld) vec[r + 1].first - vec[l].first) <= c))
			r++;
		int y_min = min(pref_min[l - 1], suf_min[r + 1]);
		int y_max = max(pref_max[l - 1], suf_max[r + 1]);
		//cout << l << " " << r << " " << y_min << " " << y_max << endl;
		if(y_min >= y_max || ((ld) y_max - y_min) <= c)
			return true;
	}
	return false;
}

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	cin >> n;
	vec.reserve(n);

	int x_min = INT_MAX, y_min = INT_MAX, x_max = INT_MIN, y_max = INT_MIN;

	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		int x = a + b, y = a - b;
		x_min = min(x, x_min);
		y_min = min(y, y_min);
		x_max = max(x, x_max);
		y_max = max(y, y_max);
		//cout << x << " " << y << endl;
		vec.push_back(make_pair(x, y));
	}

	pre();

	ld l = 0, r = max(x_max - x_min, y_max - y_min);

	while(l + E < r) {
		ld x = (ld) (l + r) / 2;
		//cout << "!!! " << l << " " << r << " " << x << endl;
		if(check(x))
		r = x;
		else
		l = x;
	}

	cout.precision(10);
	cout << fixed << l;

}