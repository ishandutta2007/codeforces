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
main(){
    FAST;
    ll q;
    cin >> q;
    while(q--){
    	ll n;
    	cin >> n;
    	ll maxx = INF, minx = -INF, maxy = INF, miny = -INF;
    	bool ok = true;
    	for(ll i = 0;i<n;i++){
    		ll nx, ny, xm, yp, xp, ym;
    		cin >> nx >> ny >> xm >> yp >> xp >> ym;
    		if(xm == 0){
    			if(minx <= nx) minx = nx;
    			else ok = ok&(xp == 1);
    		}
    		if(yp == 0){
    			if(maxy >= ny) maxy = ny;
    			else ok = ok&(ym == 1);
    		}
    		if(xp == 0){
    			if(maxx >= nx) maxx = nx;
    			else ok = ok&(xm == 1);
    		}
    		if(ym == 0){
    			if(miny <= ny) miny = ny;
    			else ok = ok&(yp == 1);
    		}
    	}
    	if(!ok || (minx > maxx) || (miny > maxy)){
    		printf("%s\n", "0");
    	}else{
    		printf("%d %lld %lld\n", 1, (minx == -INF ? (maxx == INF ? 0 : maxx) : minx), (miny == -INF ? (maxy == INF ? 0 : maxy) : miny));
    	}
    }
}