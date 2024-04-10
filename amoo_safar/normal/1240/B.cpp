#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1e9 + 7;
const int Maxn = 3e5 + 10;
const ll Inf = 1000000000000000LL;

ll a[Maxn], ind[Maxn];
bool CMP(ll i, ll j){
	if(a[i] == a[j]) return i < j;
	return a[i] < a[j];
}

ll v1[Maxn],v2[Maxn], dp[Maxn];

int MAIN(){
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	iota(ind, ind + n, 0);
	sort(ind, ind + n, CMP);
	v1[0] = 1;
	for(int i = 1; i < n; i++) v1[i] = v1[i - 1] + (a[ind[i - 1]] != a[ind[i]]);
	
	v2[n - 1] = 1;
	v2[n] = 0;
	for(int i = n - 2; i >= 0; i--) v2[i] = v2[i + 1] + (a[ind[i + 1]] != a[ind[i]]);
	dp[n - 1] = n - 1;
	
	for(int i = n - 2; i >= 0; i--) dp[i] = (ind[i] < ind[i + 1] ? dp[i + 1] : i);
	ll ans = v2[dp[0] + 1];
	for(int i = 0; i < n; i++){
		ans = min(ans, v1[i] + v2[dp[i + 1] + 1]);
	}
	cout << ans << '\n';
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T--) MAIN();
	return 0;
}