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

multiset<pll> st;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, s;
	cin >> n >> s;
	ll x, y, t;
	for(int i = 0; i < n; i++){
		cin >> x >> y >> t;
		st.insert({x*x + y*y, t});
	}
	for(auto X : st){
		s += X.S;
		if(s >= 1000000) return cout << fixed << setprecision(16) << sqrt(X.F) << '\n', 0;
	}
	cout << "-1\n";
	return 0;
}