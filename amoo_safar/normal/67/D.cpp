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
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll n, a[N], b[N];
map<ll, ll> mp;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		mp[a[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
		b[i] = mp[b[i]];
		b[i] = n + 1 - b[i];
	}
	vector<ll> V;
	V.pb(b[1]);
	for(int i = 2; i <= n; i++){
		if(V.back() < b[i]) V.pb(b[i]);
		else {
			ll idx = upper_bound(all(V), b[i]) - V.begin();
			V[idx] = b[i];
		}
	}
	cout << V.size() << '\n';
	return 0;
}