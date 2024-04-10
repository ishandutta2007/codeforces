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

vector<ll> V;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll v;
	ll cnt = 0;
	ll c = 0;
	for(int i = 0; i < n; i++){
		cin >> v;
		if(v < 0){
			c ++;
			if(c == 3){
				c = 1;
				V.pb(cnt);
				cnt = 0;
				
			}
		}
		cnt ++;
	}
	V.pb(cnt);
	cout << V.size() << '\n';
	for(auto x : V) cout << x << ' ';
	return 0;
}