// Black lives matter !
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

const ll Mod = 998244353;
const int N = 1e5 + 10;
const int Inf = 2000000100;
const ll Log = 30;

vector<pll> A;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	ll a, c;
	ll ans = 0;
	ll nw = 0;
	for(int i = 0; i < n; i++){
		cin >> a >> c;
		ans += c;
		A.pb({a, a + c});
		if(i == 0) nw = a + c;
	}
	sort(all(A));
	nw = A[0].S;
	
	for(auto x : A){
		if(x.F <= nw){
			nw = max(nw, x.S);
			continue;
		}
		ans += x.F - nw;
		nw = x.S;
	}
	cout << ans << '\n';
	return 0;
}
/*
5 1
1 2
2 3
3 4
1 5

*/