#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll p[N];

map<ll, vector<ll>> mp;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = 2; i < N; i++){
		for(int j = i; j < N; j+=i) if(p[j] == 0) p[j] = i;
	}
	ll n;
	cin >> n;
	ll v, d;
	for(int i = 0; i < n; i++){
		cin >> v;
		while(v > 1){
			d = p[v];
			ll cnt = 0;
			while(v % d == 0){
				v /= d;
				cnt ++;
			}
			mp[d].pb(cnt);
		}
	}
	ll ans = 1;
	for(auto x : mp){
		if(x.S.size() <= n - 2) continue;
		sort(all(x.S));
		ll pw = 0;
		if(x.S.size() == n - 1) pw = x.S[0];
		else pw = x.S[1];
		for(int i = 0; i < pw; i++) ans *= x.F;
	}
	cout << ans << '\n';
	return 0;
}