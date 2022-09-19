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


map<ll, ll> mp;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll v;
	for(int i = 1; i <= n; i++){
		cin >> v;
		mp[i - v] += v;
	}
	ll ans = 0;
	for(auto x : mp) ans = max(ans, x.S);
cout << ans << '\n';
	return 0;
}