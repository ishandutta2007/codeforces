// har ki ro didi goft mikhad beshe meslemon !
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

const int N = 1e5 + 10;
const ll Inf = 2242545357980376863LL;

vector< pair<ll, pll> > V;

ll Inter(pll A, pll B){
	return (B.S - A.S) / (A.F - B.F) + ( (B.S > A.S) && ((B.S - A.S) % (A.F - B.F) > 0) );
}
void Add(pll X){
	while(!V.empty() && Inter(V.back().S, X) <= V.back().F) V.pop_back();
	V.pb({V.empty() ? -Inf : Inter(V.back().S, X), X});
}
ll Get(ll x){
	pll ln = (--lower_bound(all(V), pair<ll, pll>(x, {Inf, Inf}) )) -> S;
	return x * ln.F + ln.S;
}

ll dp[N], a[N], b[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];

	dp[0] = 0;
	Add({b[0], dp[0]});
	for(int i = 1; i < n; i++){
		dp[i] = Get(a[i]);
		Add({b[i], dp[i]});
	}
	
	cout << dp[n - 1] << '\n';
	return 0;
}