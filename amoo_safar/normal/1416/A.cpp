// That's How much we have in common
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
const int N = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector<ll> V[N];

void Main(){
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		V[i] = {0};
	}
	for(int i = 1; i <= n; i++){
		ll v;
		cin >> v;
		V[v].pb(i);
	}
	for(int i = 1; i <= n; i++){
		V[i].pb(n + 1);
	}
	vector<ll> ans(n + 3, n + 1);
	for(int i = 1; i <= n; i++){
		ll mx = 0;
		for(int j = 1; j < (int) V[i].size(); j++)
			mx = max(mx, V[i][j] - V[i][j - 1]);
		ans[mx] = min(ans[mx], (ll) i);
		//cout << "! " << i << ' ' << mx << '\n';
	}
	for(int i = 2; i <= n; i++) ans[i] = min(ans[i], ans[i - 1]);
	for(int i = 1; i <= n; i++)
		cout << (ans[i] == n + 1 ? -1 : ans[i]) << " \n"[i == n];
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --) Main();
	return 0;
}