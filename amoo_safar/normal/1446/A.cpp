// nemibinam invara kasi mesle khodemono !
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

ll w[N];

int Main(){
	ll n, W;
	cin >> n >> W;;
	for(int i = 1; i <= n; i++) cin >> w[i];
	ll x = (W + 1) / 2ll;
	for(int i = 1; i <= n; i++){
		if(x <= w[i] && w[i] <= W){
			cout << "1\n" << i << '\n';
			return 0;
		}
	}
	ll S = 0;
	vector<ll> V;

	for(int i = 1; i <= n; i++){
		if(w[i] > W) continue;
		S += w[i];
		V.pb(i);
		if(S >= x) break;
	}
	if(S < x) return cout << "-1\n", 0;
	cout << V.size() << '\n';
	for(auto x : V) cout << x << ' ';
	cout << '\n';

}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --) Main();
	return 0;
}