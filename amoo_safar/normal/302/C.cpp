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

multiset<ll> ms;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, q;
	cin >> n;
	ll s = 0;
	ll S = 0;
	ll v;
	for(int i = 0; i < n + n - 1; i++){
		cin>> v;
		s += v;
		S += abs(v);
		ms.insert(v);
	}
	if(n & 1) return cout << S << '\n', 0;
	ll ans = s;
	ll x1, x2;
	for(int i = 0; i < n; i++){
		ans = max(ans, s);
		x1 = *ms.begin();
		ms.erase(ms.begin());
		x2 = *ms.begin();
		ms.erase(ms.begin());
		s -= x1;
		s -= x2;
		x1 = -x1;
		x2 = -x2;
		s += x1;
		s += x2;
		ms.insert(x1);	
		
		ms.insert(x2);
	}
	cout << ans << '\n';
	return 0;
}