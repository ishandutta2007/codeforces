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

ll a[N];
int n;
ll Calc(int i){
	ll res = 0;
	if(0 <= i && i < n) res += max(0ll, a[i] - a[i + 1]);
	return res;
}
void Main(){
	ll q;
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	a[n] = 0;
	ll ans = 0;
	for(int i = 0; i < n; i++) ans += Calc(i);
	cout << ans << '\n';
	int u, v;
	for(int i = 0; i < q; i++){
		cin >> u >> v;
		u --; v--;
		ans -= Calc(u);
		ans -= Calc(u - 1);
		int tmp = a[u];
		a[u] = a[v];
		ans += Calc(u);
		ans += Calc(u - 1);
	
		u = v;
		ans -= Calc(u);
		ans -= Calc(u - 1);
		a[u] = tmp;
		ans += Calc(u);
		ans += Calc(u - 1);
		cout << ans << '\n';
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --) Main();

	return 0;
}