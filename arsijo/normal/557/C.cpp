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
const ll MAX = 201;
typedef ll array[MAX][MAX];
const ld E = 1e-11;

inline void update(ll &a, ll b) {
	a = min(a, b);
}

ll sumFirstK(int *ar, int k) {
	ll sum = 0;
	for (int i = 1; i < MAX; i++) {
		sum += min(ar[i], k) * i;
		k -= min(ar[i], k);
	}
	return sum;
}

int main() {

#ifdef LOCAL
	input;
#endif

	sync;

	int n;
	cin >> n;

	int ar[MAX];
	ms(ar);

	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<ii> vec;
	vec.reserve(n);
	for(int i = 0; i < n; i++) {
		int b;
		cin >> b;
		ar[b]++;
		vec.push_back(make_pair(a[i], b));
	}

	sort(vec.rbegin(), vec.rend());

	ll sum = 0, ans = LONG_LONG_MAX;

	for(int i = 0; i < n; i++) {
		ll a = vec[i].y;
		int b = 1;
		ar[vec[i].y]--;
		while( i < n - 1 && vec[i + 1].x == vec[i].x) {
			i++;
			a += vec[i].y;
			b++;
			ar[vec[i].y]--;
		}
		int left = n - i - 1;
		//cout << left << " " << b << endl;
		if(left < b) {
			//cout << "+" << sum << endl;
			update(ans, sum);
		} else {
			int need = left - b + 1;
			//cout << need << " " << sum << " " << sumFirstK(ar, need) << endl;
			if(need <= left)
			update(ans, sum + sumFirstK(ar, need));
		}
		//cout << "+ " << a << " of " << vec[i].x << " " << endl;
		sum += a;
	}

	cout << ans;

}