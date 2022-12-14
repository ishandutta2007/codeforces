#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) (int(s.size()))
#define bit(n, k) (((n)>>(k))&1)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 2e5 + 10;
const ll inf = 1e18;

struct DSU{
    int par[maxn];
    void build(int n){
	fill(par, par + n + 1, -1);
    }
    int fnd(int u){
	return par[u] < 0 ? u : par[u] = fnd(par[u]);
    }
    bool mrg(int a, int b){
	if( (a = fnd(a)) == (b = fnd(b)) )
	    return 0;
	if(par[a] > par[b])
	    swap(a, b);
	par[a]+= par[b];
	par[b] = a;
	return 1;
    }    
};DSU dsu;

ll solve(){
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<pair<int, pii> > V1, V2;

    for(int i = 0; i < m; i++){
	int a, b, c;
	cin >> a >> b >> c;
	if(c <= k)
	    V1.PB({c, {a, b}});
	else
	    V2.PB({c, {a, b}});
    }
    sort(V1.begin(), V1.end());
    sort(V2.begin(), V2.end());
    reverse(V1.begin(), V1.end());

    dsu.build(n);
    ll ans = inf;
    int MX = -1;
    int cnt = 0;
    for(auto p : V1){
	if(dsu.mrg(p.S.F, p.S.S))
	    cnt++, MX = max(MX, p.F);
    }
    if(cnt == n-1)
	ans = min(ans, ll(k-MX));
    ll sum = 0;
    int used = 0;
    for(auto p : V2){
	if(dsu.mrg(p.S.F, p.S.S))
	    used++, sum+= p.F-k;
    }
    if(used){
	ans = min(ans, sum);
    }
    else{
	if(!V2.empty())
	    ans = min(ans, ll(V2[0].F-k));
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(), cout.tie();

    int q;
    cin >> q;
    while(q--){
	cout << solve() << "\n";
    }
    return 0;
}