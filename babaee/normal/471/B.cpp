/*
    Soheil Mohammadkhani
    OK, im back :)
*/
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;


vector<pll> v;

void dojob() {
	for (pll e : v) cout << e.Y << sep;
	cout << endl;
}

int main() {
	fast_io;
	ll n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		v.push_back({x, i});
	}

	sort(all(v));
	pair<pll, pll> v1;
	ll x = 0;
	vector<ll> v2;
	ll cnt = 0;
	bool f1 = false;
	ll prv = -1;
	for (ll i = 0; i < n; i++) {	
		if (v[i].X != prv) {
			prv = v[i].X;
			if (cnt > 2) {
				v2.push_back(i - 3);
				v2.push_back(i - 1);
				v2.push_back(i - 2);
				break;
			} else if (cnt == 2) {
				if (x == 0) v1.X = {i - 2, i - 1};
				else v1.Y = {i - 2, i - 1};
				x++;
				if (x == 2) break; 
			}


			cnt = 1;
		} else cnt++;
	}

	ll i = n - 1;
	if (cnt > 2) {
                 v2.push_back(i);
                 v2.push_back(i - 1);
                 v2.push_back(i - 2);
        } else if (cnt == 2 && x < 2) { 
                 if (x == 0) v1.X = {i, i - 1};
                 else v1.Y = {i, i - 1};
                 x++;
                 //if (x == 2) break; 
        }

	if (x >= 2) {
		cout << "YES" << endl;
		dojob();
		swap(v[v1.X.X], v[v1.X.Y]);
		dojob();
		swap(v[v1.Y.X], v[v1.Y.Y]);
		dojob();
		return 0;
	}
	
	if (!v2.empty()) {
		//cout << v2[0] << sep << v2[1] << sep << v2[2] << endl;
		cout << "YES" << endl;
		dojob();
		swap(v[v2[0]], v[v2[1]]);
		dojob();
		swap(v[v2[1]], v[v2[2]]);
		dojob();
		return 0;
	}

	cout << "NO" << endl;
	return 0;



}