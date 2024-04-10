// vaziat meshki-ghermeze !
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
const int N = 5e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 60;

ll w[N];

ll mul(ll a, ll b){
	a %= Mod;
	b %= Mod;
	return (a * b) % Mod;
}

int Main(){
	int n;
	cin >> n;
	vector<int> cnt(Log, 0);
	int u, v;
	for(int i = 1; i <= n; i++){
		cin >> w[i];
		for(int j = 0; j < Log; j++){
			if(w[i] >> j & 1)
				cnt[j] ++;
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		ll S1 = 0;
		ll S2 = 0;
		for(int j = 0; j < Log; j++){
			if(w[i] >> j & 1){
				S1 += mul(1ll << j, cnt[j]);
				S2 += mul(1ll << j, n);
			} else {
				S2 += mul(1ll << j, cnt[j]);
			}
		}
		ans += mul(S1, S2);
	}
	cout << ans % Mod << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T --) Main();
	return 0;
}