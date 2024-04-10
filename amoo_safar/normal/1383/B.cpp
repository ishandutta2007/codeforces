// Null
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

ll a[N];

void Main(){
	ll n;
	cin >> n;
	ll x = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		x ^= a[i];
	}
	if(x == 0){
		cout << "DRAW\n";
		return ;
	}
	ll idx = -1;
	for(int i = 60; i >= 0; i--){
		if(x >> i & 1){
			idx = i;
			break;
		}
	}
	ll c1 = 0, c0 = 0;
	for(int i = 0; i < n; i++){
		if(a[i] >> idx & 1) c1 ++;
		else c0 ++;
	}
	if(n % 2 == 0) cout << "WIN\n";
	else {
		ll q = (c1 + 1) /2;
		if(q & 1) cout << "WIN\n";
		else cout << "LOSE\n";
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --) Main();
	return 0;
}