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
#define N 1010
#define INF 101111111111111
using namespace std;
ll only_a_min = INF, only_b_min = INF, only_c_min = INF, all_min = INF;
pll d[N];
main(){
    FAST;
    ll n;
    cin >> n;
    for(ll i =0;i<n;i++){
    	ll c;
    	cin >> c;
    	string dt;
    	cin >> dt;
    	if(dt.length() == 1){
    		if(dt[0] == 'A') only_a_min = min(only_a_min, c);
    		if(dt[0] == 'B') only_b_min = min(only_b_min, c);
    		if(dt[0] == 'C') only_c_min = min(only_c_min, c);
    	}
    	if(dt.length() == 3){
    		all_min = min(all_min, c);
    	}
    	d[i] = {([](string dt){
    		ll res = 0;
    		for(auto i : dt) res += (1 << (i - 'A'));
    		return res;
    	})(dt), c};
    }
    ll res = min(only_c_min + only_b_min + only_a_min, all_min);
    for(ll i =0;i<n;i++){
    	for(ll j = i+1;j<n;j++){
    		if((d[i].x | d[j].x) == 7) res = min(res, d[i].y + d[j].y);
    	}
    }
    if(res >= INF) cout << -1;
    else cout << res;
}