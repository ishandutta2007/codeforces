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
const int N = 3e2 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector<ll> V[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll p = 1;
	ll p2 = n*n;
	ll m = n/2;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			V[i].pb(p);
			V[i].pb(p2);
			p ++;
			p2 --;
		}
	}
	if(n & 1) for(int i = p; i <= p2; i++) V[i - p + 1].pb(i);
	for(int i = 0; i < n; i++){
		for(auto x : V[i + 1]) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}