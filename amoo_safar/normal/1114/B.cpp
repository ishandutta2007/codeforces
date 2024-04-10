#include <bits/stdc++.h>
 
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
 
const ld PI = 3.14159265359;
 
const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;
 
ll a[MAXN];
ll b[MAXN];
ll g[MAXN];

bool CMP(ll i, ll j){
	return a[i] > a[j];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    for(int i = 0;i<n;i++){
		cin >> a[i];
		b[i] = i;
	}
	sort(b, b+ n, CMP);
	ll ans  =0;
	for(int i = 0;i<m*k;i++){
		ans += a[b[i]];
		g[b[i]] = 1;
    }
    cout << ans << '\n';
    ll cnt = m;
    ll t = k;
    for(int i = 0;i<n;i++){
		cnt -= g[i];
		//debug(t);
		if(cnt == 0){
			t--;
			if(t > 0) cout << i + 1 << " ";
			cnt = m;
		}
	}
	return 0;
}