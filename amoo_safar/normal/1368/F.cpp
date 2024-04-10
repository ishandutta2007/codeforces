// Amsal Shoma Ro Gaedan Ye Amal Pasandidas !
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
const int N = 1e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll n;

int mk[N];
ll k;

void Op(){
	ll x;
	cin >> x;
	int wh = x;
	for(int i = 0; i < k; i++){
		mk[wh] = 0;
		wh ++;
		if(wh == n + 1) wh = 1;
	}
}

vector<ll> V, Gd;
ll K;
void Move(){
	V.clear();
	for(auto i : Gd){
		if(!mk[i]) V.pb(i);
	}
	k = V.size();
	if(k <= K){
		cout << "0" << endl;
		exit(0);
	}
	cout << k << '\n';
	for(auto x : V){
		cout << x << ' ';
		mk[x] = 1;
	}
	cout << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	if(n < 4){
		cout << "0" << endl;
		return 0;
	}
	ll ans = n/2 - 1;
	K = 1;
	for(int i = 2; i <= n; i++){
		ll t = n / (i + 1);
		if(t <= 1) continue;
		ll C = ((t - 1) * i) + max(0ll, (n % (i + 1)) - 1);
		if(C > ans){
			K = i;
			ans = C;
		}
	}
	for(int i = 1; i <= n; i += K + 1){
		for(int j = i; j < i + K; j++){
			if(j >= n) break;
			Gd.pb(j);
		}
	}
	while(true){
		Move();
		Op();
	}
	
	return 0;
}