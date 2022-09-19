#include <bits/stdc++.h>

#define pb push_back

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " " << x << '\n'
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 5e2 + 10;
const ll INF = (ll) 92233720368545;
const ld EPS = (ld) 1e-8;
const ll LOG = 20;

ll r[MAXN], c[MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, m, x;
	cin >> n >> m;
	for(int i = 0; i < n + n; i++){
		for(int j = 0; j< m; j++){
			cin >> x;
			r[i % n] ^= x;
			c[j] ^= x;
		}
	}
	for(int i = 0; i < max(n, m); i++) if(r[i] != 0 or c[i] != 0) return cout << "No", 0 ;
	cout << "Yes";
	return 0;
}