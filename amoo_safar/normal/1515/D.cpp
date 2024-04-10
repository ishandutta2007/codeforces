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
const int N = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int Main(){
	int n;
	cin >> n;
	vector<int> V(n + 1);
	int l, r;
	cin >> l >> r;
	int c;
	for(int i = 0; i < l; i++){
		cin >> c;
		V[c] ++;
	}

	for(int i = 0; i < r; i++){
		cin >> c;
		V[c] --;
	}
	ll ans = 0;
	for(auto x : V) ans += abs(x);
	ll sp = 0, op = 0, sn = 0, on = 0;
	for(auto x : V){
		// cout << "? " << x << '\n';
		if(x > 0){
			sp += x;
			op += (x % 2 == 1);
		} else {
			sn += abs(x);
			on += (abs(x) % 2 == 1);
		}
	}
	// cout << "! " << ans << '\n';
	if(op > sn) ans += op - sn;
	if(on > sp) ans += on - sp;
	cout << ans / 2 << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	cin >> tc;
	while(tc --) Main();
	return 0;
}