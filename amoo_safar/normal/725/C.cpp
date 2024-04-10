#include <bits/stdc++.h>

#define pb push_back

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " " << x 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll cnt[30];
char ans[2][13];

pll nx(ll i, ll j){
	if(i == 0){
		if(j != 12) return {0, j + 1};
		return {1, j};
	}
	if(j > 0) return {1, j - 1};
	return {0,0};
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	str s;
	cin >> s;
	memset(cnt, -1, sizeof cnt);
	ll len = -1;
	ll ind = -1;
	ll i2 = -1;
	ll n = 27;
	for(int i = 0; i < n; i++){
		if(cnt[s[i] - 'A'] != -1){
			ind = cnt[s[i] - 'A'];
			len = i - cnt[s[i] - 'A'] - 1;
			i2 = i;
		}
		cnt[s[i] - 'A'] = i;
	}
	if(len == 0) return cout << "Impossible", 0;
	ll x = 0;
	ll y = 12 - ((len) / 2);
	for(int i = 0; i < 27; i++){
		ind %= n;
		if(ind == i2){
			ind ++;
			continue;
		}
		ans[x][y] = s[ind];
		pll res = nx(x, y);
		x = res.F;
		y = res.S;
		ind ++;
	}
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 13; j++) cout << ans[i][j];
		cout << '\n';
	}
	return 0;
}