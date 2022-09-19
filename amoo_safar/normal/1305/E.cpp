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
const int N = 5e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll f[N];
vector<ll> V;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f[1] = 0;
	for(int i = 2; i < N; i++){
		f[i] = f[i - 1] + ((i - 1) / 2);
	}
	ll n, m;
	cin >> n >> m;
	if(f[n] < m){
		return cout << "-1\n", 0;
	}
	ll x;
	for(int i = 1; i <= n; i++) if(f[i] >= m){
		x = i;
		break;
	}
	ll mx = 1000000000ll-1;
	ll D = 20000;
	ll rm = n - x;
	while(rm){
		rm --;
		V.pb(mx - D);
		mx -= D;
	}
	for(int i = 1; i < x; i++) V.pb(i);
	ll F = f[x];
	while(F > m){
		if(x & 1) F--;
		x ++;
	}	
	V.pb(x);
	sort(all(V));
	for(auto y : V) cout << y << ' ';
	return 0;
}