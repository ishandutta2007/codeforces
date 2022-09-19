#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll sm[Maxn];

vector<ll> A, B;
vector< pair<ll, pll> > O;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	ll u, w, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v >> w;
		sm[u] -= w;
		sm[v] += w;
	}
	for(int i = 1; i <= n; i++){
		if(sm[i] < 0) A.pb(i);
		if(sm[i] > 0) B.pb(i);
	}
	ll p = 0;
	for(auto x : B){
		//cerr << x << '\n';
		while(p < A.size()){
			if(sm[x] == 0) break;
			if(sm[A[p]] == 0){
				p ++;
				continue;
			}
			ll d = min(abs(sm[A[p]]) , sm[x]);
			sm[x] -= d;
			sm[A[p]] += d;
			O.pb({x, {d, A[p]}});
		}
	}
	cout << O.size() << '\n';
	for(auto x : O) cout << x.S.S << ' ' << x.F << ' '  << x.S.F << '\n';
	return 0;
}