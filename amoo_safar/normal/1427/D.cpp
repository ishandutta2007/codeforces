// I'll Crush you !
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
ll b[N], pos[N];
ll n;
vector< vector<ll> > V;

void Per(vector<ll> x){
	if(x.size() == 1) return ;
	V.pb(x);
	int p = n, p2 = 0;
	for(auto el : x){
		p -= el;
		for(int i = 0; i < el; i++){
			b[p] = a[p2];
			p2 ++;
			p ++;
		}
		p -= el;
	}
	swap(a, b);
	for(int i = 0; i < n; i++) pos[a[i]] = i;
}



int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(int i = 0; i < n; i++) pos[a[i]] = i;

	int st = 0;
	if(pos[1] == 0){
		st = 1;
	} else if(pos[1] == n - 1) {
		st = 0;
	} else {
		Per({pos[1], n - pos[1]});
		st = 1;
	}

	vector<ll> mv;
	for(int i = 2; i < n; i++){
		ll rm = n;
		mv.clear();
		for(int j = 1; j < i; j++) {
			mv.pb(1);
			rm --;
		}
		if(st == 1){
			mv.pb(pos[i] - (i - 1) + 1);
			rm -= mv.back();
			if(rm) mv.pb(rm);
		} else {
			mv.pb((n - pos[i]) - (i - 1));
			rm -= mv.back();
			if(rm) mv.pb(rm);
			reverse(all(mv));
		}
		Per(mv);
		st ^= 1;
	}

	debug(st);
	if(st == 0){
		st = 0;
		mv.clear();
		for(int i = 0; i < n; i++){
			mv.pb(1);
		}
		Per(mv);
	}



	cout << V.size() << '\n';
	for(auto X  : V){
		cout << X.size();
		for(auto el : X) cout << ' ' << el;
		cout << '\n';
	}
	return 0;
}