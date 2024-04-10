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

vector<ll> V;
ll a[N], v[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	V.pb(a[0]);
	for(int i = 1; i < n; i++) if(a[i] != a[i - 1]) V.pb(a[i]);
	n = V.size();
	for(int i = 1; i < n; i++){
		v[V[i]] --;
		v[V[i-1]] --;
	}
	for(int i = 1; i + 1 < n; i++){
		if(V[i - 1] != V[i + 1]) v[V[i]] ++;
	}
	cout << min_element(v + 1, v + 1 + k) - v << '\n';
	return 0;
}