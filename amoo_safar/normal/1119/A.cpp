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
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 92233720368545;
const ld EPS = (ld) 1e-8;
const ll LOG = 20;

ll a[MAXN];
ll l[MAXN];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 1;i<=n;i++) cin >> a[i];
	fill(l, l+ MAXN, n);
	for(int i = n; i > 0;i--){
		if(l[a[i]] == i) l[a[i]] --;
	}
	ll ans = 0;
	for(int i = 1; i<= n; i++){
		ans = max(ans, abs(i - l[a[i]]));
	}
	cout << ans;
	return 0;
}