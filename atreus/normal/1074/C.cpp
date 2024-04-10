#include <bits/stdc++.h>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int mod = (int)1e9 + 7;
const int maxn = 3e5 + 4;
const int inf = (int)1e9;

ll x[maxn], f[maxn], y[maxn];
pair <ll, ll> p[maxn];

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	ll mxx = -inf, mxy = -inf, mnx = inf, mny = inf;
	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		mxx = max (mxx, x);
		mnx = min (mnx, x);
		mxy = max (mxy, y);
		mny = min (mny, y);
		p[i] = {x, y};
	}
	sort (p, p + n);
	
	ll t = -inf, maxy = -inf, miny = inf;
	ll yx = -inf, xy = -inf;

	for (int i = 0; i < n; i++) {
		f[3] = max (f[3], 2ll * (p[i].F + p[i].S - p[0].F - miny));
		f[3] = max (f[3], 2ll * (p[i].F - p[i].S - p[0].F + maxy));
//		cout << t << " " << f[3] << " - ";
		f[3] = max (f[3], 2ll * (p[i].F + t));
//		cout << f[3] << endl;
		t = max (t, yx - p[i].S);
		t = max (t, p[i].S + xy);
		
		yx = max (yx, p[i].S - p[i].F);
		xy = max (xy, -p[i].S - p[i].F);
		
		miny = min (miny, p[i].S);
		maxy = max (maxy, p[i].S);
	
	}
	for (int i = 4; i <= n; i++)
		f[i] = 2 * (mxx - mnx + mxy - mny);
	for (int i = 3; i <= n; i++)
		cout << f[i] << " ";
}