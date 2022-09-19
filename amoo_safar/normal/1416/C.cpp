// That's How much we have in common
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
const int N = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;
const int N2 = N * Log + 20;

int sm[N2], nx[N2][2], la = 0;

int Get(int id, int v){
	if(nx[id][v] == -1){
		nx[id][0] = ++ la;
		nx[id][1] = ++ la;
	}
	return nx[id][v];
}

ll cnt[Log][2];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(nx, -1, sizeof nx);

	ll n;
	cin >> n;
	ll v;
	for(int i = 1; i <= n; i++){
		cin >> v;
		int nw, bt;
		nw = 0;
		for(int i = Log - 1; i >= 0; i--){
			bt = v >> i & 1;
			cnt[i][bt ^ 1] += sm[Get(nw, bt ^ 1)];
			nw = Get(nw, bt);
			sm[nw] ++;
		}
	}
	ll x = 0;
	ll ans = 0;
	for(int i = 0; i < Log; i++){
		if(cnt[i][0] >= cnt[i][1]){
			ans += cnt[i][1];
		} else {
			x |= (1ll << i);
			ans += cnt[i][0];
		}
		//if(i < 3)
		//	cout << cnt[i][0] << ' ' << cnt[i][1] << '\n';
	}
	cout << ans << ' ' << x << '\n';
	return 0;
}