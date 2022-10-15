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
#define x first
#define y second
#define mod % 1000000007
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef map<int, int>::iterator mit;
const ll MAX = 1000;
typedef ll array[MAX][MAX];
const ld E = 1e-11;

struct t {
	ll minLen, maxLen, index;
	t(ll minLen, ll maxLen, ll index) {
		this->minLen = minLen;
		this->maxLen = maxLen;
		this->index = index;
	}
};

bool operator<(t a, t b) {
	if (a.minLen != b.minLen)
		return a.minLen < b.minLen;
	if (a.maxLen != b.maxLen)
		return a.maxLen < b.maxLen;
	return a.index < b.index;
}

int main() {

	sync;
	//input;
	int n, m;
	cin >> n >> m;

	ll l, r;
	cin >> l >> r;

	vector<t> v;
	v.reserve(n - 1);
	for(int i = 0; i < n - 1; i++) {
		ll _l, _r;
		cin >> _l >> _r;
		v.push_back(t(_r - l, _l - r, i));
		l = _l;
		r = _r;
	}

	sort(v.begin(), v.end());

	set<ii> s;
	for(int i = 1; i <= m; i++) {
		ll a;
		cin >> a;
		s.insert(make_pair(a, i));
	}

	int ans[n - 1];
	ms(ans);

	for(int i = 0; i < n - 1; i++) {
		set<ii>::iterator it = s.lower_bound(make_pair(v[i].maxLen, LONG_LONG_MIN));
		if(it == s.end() || it->x > v[i].minLen) {
			cout << "No";
			exit(0);
		}
		ans[v[i].index] = it->y;
		s.erase(it);
	}

	cout << "Yes\n";
	for(int i = 0; i < n - 1; i++)
		cout << ans[i] << " ";

}