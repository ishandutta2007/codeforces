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

const ld PI = acos(-1.0);
ld pol(int x, int y) {
	if(x == 0){
		if(y > 0)
			return PI / 2;
		if(y < 0)
			return PI * 3 / 2;
		if(y == 0)
			return -1;
	}
	ld e = (ld) y / x;
	ld ans = (ld) atan(e);
	if (x > 0 && y >= 0)
		return ans;
	if (x > 0 && y < 0)
		return ans + PI + PI;
	if (x < 0)
		return ans + PI;
	return -111;
}

ld min_dist(ld a, ld b){
	if(a > b)
		swap(a, b);
	ld q = b - a;
	return min(q, PI * 2 - q);
}

int main() {

	sync;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	vector<pair<ld, int> > v;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(pol(a, b), i + 1));
	}

	sort(v.begin(), v.end());

	vector<pair<ld, int> > vec;
	vec.insert(vec.end(), v.begin(), v.end());
	vec.insert(vec.end(), v.begin(), v.end());

	ld m = 10000;
	int a, b;
	for(int i = 0; i < (int) vec.size() - 1; i++){
		ld k = min_dist(vec[i].first, vec[i + 1].first);
		if(k < m){
			m = k;
			a = vec[i].second;
			b = vec[i + 1].second;
		}
	}

	cout << a << " " << b << endl;

}