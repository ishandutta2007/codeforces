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

vector< pair<ll, str> > V;
void Solve(ll n, ll m){
	if(n == 1){
		if(m == 1) return ;
		V.pb({m - 1, "R"});
		V.pb({m - 1, "L"});
		return ;
	}
	if(m == 1){
		V.pb({n - 1, "D"});
		V.pb({n - 1, "U"});
		return ;
	}
	if(n == 2){
		Solve(1, m);
		V.pb({m - 1, "DRU"});
		V.pb({1, "D"});
		V.pb({m - 1, "L"});
		V.pb({1, "U"});
		return ;
	}
	if(m == 2){
		Solve(n, 1);
		V.pb({n - 1, "RDL"});
		V.pb({1, "R"});
		V.pb({n - 1, "U"});
		V.pb({1, "L"});
		return ;	
	}
	V.pb({1, "DR"});
	Solve(n - 2, m - 2);
	V.pb({n - 2, "LDR"});
	V.pb({m - 2, "UDR"});
	V.pb({n - 2, "ULR"});
	V.pb({m - 2, "ULD"});
	V.pb({1, "UL"});
	V.pb({m - 1, "R"});
	V.pb({n - 1, "D"});
	V.pb({m - 1, "L"});
	V.pb({n - 1, "U"});
}

vector< pair<ll, str> > A;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, m, k;
	cin >> n >> m >> k;
	Solve(n, m);
	ll sm = 0;
	for(auto M : V){
		if(sm >= k) break;
		if(sm + (M.F * (M.S.size())) <= k){
			sm += (M.F * (M.S.size()));
			A.pb(M);
			continue;
		}
		ll rem = k - sm;
		if(rem >= M.S.size()){
			A.pb({rem / M.S.size(), M.S});
		}
		if(rem % M.S.size()){
			A.pb({1, M.S.substr(0, rem % M.S.size())});
		}
		break;
	}
	if(k > 4*n*m - 2*n - 2*m) cout << "NO\n";
	else{
		cout << "YES\n" << A.size() << '\n';
		for(auto x : A) cout << x.F << " " << x.S << '\n';
	}
	return 0;
}