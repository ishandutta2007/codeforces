#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200000
#define INF 101111111111111
using namespace std;
int main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		ll a, b, c;
		cin >> a >> b >> c;
		if(a > b) swap(a, b);
		if(b > c) swap(c, b);
		if(a > b) swap(a, b);
		ll of = c-b;
		ll skip = min(a, of);
		c -= skip;
		a -= skip;
		c -= a/2;
		b -= a/2;
		if(a&1) b--;
		ll res = skip + a + min(b, c);
		cout << res << endl;
	}
}