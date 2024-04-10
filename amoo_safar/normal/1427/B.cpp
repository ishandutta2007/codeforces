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
void Main(){
	ll n, k;
	cin >> n >> k;
	str s;
	cin >> s;
	ll w = 0, l = 0;
	
	ll cnt = 0;
	vector<int> V;
	for(auto x : s){
		if(x == 'L') l ++;
		if(x == 'W') w ++;
		if(x == 'L') cnt ++;
		else {
			V.pb(cnt);
			cnt = 0;
		}
	}
	k = min(k, l);
	//cout << "! " << l << ' ' << k << ' ' << w << '\n';
	if(w == 0){
		cout << max(2*k - 1, 0ll) << '\n';
		return ;
	}
	V.erase(V.begin());
	int com = w;
	sort(all(V));
	ll k2 = k;
	for(auto x : V){
		if(x > k2) break;
		//debug(x);
		com --;
		k2 -= x;
	}
	cout << 2* (w + k) - com << '\n';
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --) Main();
	return 0;
}
/*
2
5 2
WLWLL
6 5
LLLWWL

*/