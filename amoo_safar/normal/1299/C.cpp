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
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll a[N];

bool CMP(pll a, pll b){
	return a.F * b.S < a.S * b.F;
}

stack<pair<ll, ll>> st;
vector<ld> V;
int main(){
	ll n;
	scanf("%lld", &n);
	for(int i = 0; i < n; i++) scanf("%lld", a + i);
	pll nw;
	for(int i = 0; i < n; i++){
		nw = {a[i], 1};
		while((!st.empty()) && CMP(nw, st.top())){
			nw.F += st.top().F;
			nw.S += st.top().S;	
			st.pop();
		}
		st.push(nw);
	}
	while(!st.empty()){
		ld X = ((ld) st.top().F) / st.top().S;
		for(int i = 0; i < st.top().S; i++) V.pb(X);
		st.pop();
	}
	reverse(all(V));
	for(auto x : V) printf("%.8f\n", (double) x);
	//for(auto x : V) cout << fixed << setprecision(8) << x << '\n';
	return 0;
}