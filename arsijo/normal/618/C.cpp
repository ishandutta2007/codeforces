#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
//#define endl "\n"
#define def(f) make(#f);
#define y1 dads
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
#ifdef LOCAL
typedef double ld;
#else
typedef long double ld;
#endif
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
typedef pair<string, string> ss;
const ld E = 1e-15;
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

ld dist(ii a, ii b){
	return (ld) sqrt(sqr(a.first - b.first) + sqr(a.second - b.second));
}

ld heron(ld a, ld b, ld c){
	ld p = (a + b + c) / 2;
	return p * (p - a) * (p - b) * (p - c);
}

#define x first
#define y second
bool check(ii a, ii b, ii c){
 	return ( a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) ) != 0;
}

int main() {

	cout.precision(11);

	cout << fixed;
	sync;
	srand(time(NULL));
#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	ii ar[n];
	for(int i = 0; i < n; i++){
		cin >> ar[i].first >> ar[i].second;
	}

	ld s = -1;

	int pos = 1;
	ld q = dist(ar[0], ar[1]);

	for(int i = 2; i < n; i++){
		ld w = dist(ar[0], ar[i]);
		if(w < q){
			q = w;
			pos = i;
		}
	}

	ld d1 = dist(ar[0], ar[pos]);

	int ans = -1;
	for(int i = 1; i < n; i++){
		if(pos == i)
			continue;
		if(!check(ar[0], ar[i], ar[pos]))
			continue;
		ld d2 = dist(ar[0], ar[i]);
		ld d3 = dist(ar[pos], ar[i]);
		ld ss = heron(d1, d2, d3);
		if(ss < s || s == -1){
			s = ss;
			ans = i + 1;
		}
	}

	cout << "1 " << pos + 1 << " " << ans << endl;

}