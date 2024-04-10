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

map<str,ll> mp;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
str s;
ll v;
	for(int i = 0; i < n; i++){
		cin >> s >> v;
		mp[s] = max(mp[s], v);
	}
	n = mp.size();
	cout << n << '\n';
	for(auto x : mp){
		ll cnt = 0;
		for(auto y : mp) if(y.S > x.S) cnt ++;
		cout << x.F << " ";
		if(100 * cnt > 50 * n) cout << "noob\n";
		else if	(100 * cnt > 20 * n) cout << "random\n";
		else if	(100 * cnt > 10 * n) cout << "average\n";
		else if	(100 * cnt > 1 * n) cout << "hardcore\n";
		else cout << "pro\n";
	}
	return 0;
}