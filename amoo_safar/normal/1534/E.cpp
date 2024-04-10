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
const int N = 4e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;


ll cnt[N];
vector<ll> V[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k;
	cin >> n >> k;
	if((n % 2 == 1) && (k % 2 == 0))
		return cout << "-1" << endl, 0;

	ll d = 0;
	while(true){
		// debug(d);
		if(( d < n ) || ((d % 2) != (n % 2))){
			d += k;
			continue;
		}
		ll d2 = d;
		ll Y = d2/k;
		cnt[0] = 1;
		d2 -= n;
		d2 /= 2;
		cnt[0] += 2 * (d2 / n);
		if(0 < d2 % n)
			cnt[0] += 2;
		if(cnt[0] > Y){
			d += k;
			continue;
		}
		break;
	}

	ll d2 = d;
	ll Y = d2/k;

	for(int i = 0; i < n; i++){
		cnt[i] = 1;
	}
	d2 -= n;
	d2 /= 2;
	
	for(int i = 0; i < n; i++){
		cnt[i] += 2 * (d2 / n);
		if(i < d2 % n)
			cnt[i] += 2;
		// debug(cnt[i]);
	}
	int po = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < cnt[i]; j++){
			V[po].pb(i + 1);
			po ++;
			if(po == Y) po = 0;
		}
	}
	ll tmp, res = 0;
	for(int i = 0; i < Y; i++){
		cout << "?";
		for(auto x : V[i]) cout << ' ' << x;
		cout << endl;
		cin >> tmp;
		res ^= tmp;
	}


	cout << "! " << res << endl;
	return 0;
}