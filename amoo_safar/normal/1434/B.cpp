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
ll n;
ll a[N], b[N];

vector<ll> V;

vector<pll> Q[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	char c;
	ll v;
	ll cnt = 0;
	for(int i = 0; i < n+n; i++){
		cin >> c;
		if(c == '-'){
			cin >> v;
			b[v] = cnt;
		
			while(!V.empty() && V.back() < v) V.pop_back();
			ll res = (V.empty() ? 0 : b[V.back()]);
			V.pb(v);
			Q[res].pb({cnt, v});
		} else {
			cnt ++;
		}
	}
	set<pll> ms;
	vector<ll> ans;
	for(int i = 0; i < n; i++){
		for(auto x : Q[i])
			ms.insert(x);
		while(!ms.empty() && ms.begin()->F <= i) ms.erase(ms.begin());
		if(ms.empty())
			return cout << "NO\n", 0;
		ans.pb(ms.begin()->S);
		ms.erase(ms.begin());
	}
	cout << "YES\n";
	for(auto x : ans) cout << x << ' ';
		cout << '\n';
	return 0;
}