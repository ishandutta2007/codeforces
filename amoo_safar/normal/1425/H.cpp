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
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll a, b, c, d;
	for(int i = 0; i < n ; i++){
		cin >> a >> b >> c >> d;
		ll dg = (a + b) % 2;
		ll sm = (b + c) > 0;
		ll bg = (a + d) > 0;
		//cerr << "! " << bg << '\n';
		cout << (dg == 1 && bg == 1 ? "Ya" : "Tidak") << " ";
		cout << (dg == 1 && sm == 1 ? "Ya" : "Tidak") << " ";
		cout << (dg == 0 && sm == 1 ? "Ya" : "Tidak") << " ";
		cout << (dg == 0 && bg == 1 ? "Ya" : "Tidak") << "\n";
	}
	return 0;
}