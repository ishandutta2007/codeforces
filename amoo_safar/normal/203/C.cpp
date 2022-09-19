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
const int N = 1e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector<pll> V;
vector<ll> A;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, d, a, b;
	cin >> n >> d >> a >> b;
	ll x, y;
	for(int i = 1; i <= n; i++){
		cin >> x >> y;
		V.pb({x*a + y*b, i});
	}
	sort(all(V));
	for(auto X : V){
		if(X.F <= d){
			d -= X.F;
			A.pb(X.S);
		}
	}
	sort(all(A));
	cout << A.size() << '\n';
	for(auto y : A) cout << y << ' ';
	return 0;
}