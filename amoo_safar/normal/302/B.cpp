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

ll t[N], c[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> t[i] >> c[i];
	}
	t[n] = Inf;
	c[n] = 1;

	ll T = 0;
	ll v, p = 0;

	for(int i = 0; i < q; i++){
		cin >> v;
		while(T + t[p] * c[p] < v){
			T += t[p]*c[p], p++;
		}
		cout << p + 1 << '\n';
	}
	return 0;
}