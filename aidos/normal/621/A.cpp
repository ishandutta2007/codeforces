#include <bits/stdc++.h>

using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (int)1e9;
const int mod = (int) 1e9 + 7;

vector < int > v[3];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    for(int i = 0, x; i < n; i++){
    	scanf("%d", &x);
    	v[x%2].pb(x);
    }
    sort(all(v[0]));
    sort(all(v[1]));
    
    ll ans = 0;
    int last = 0;
    for(int i = 0; i < 2; i++){
    	
    	while(v[i].size() > 0){
    		ans += v[i].back();
    		last = v[i].back();
    		v[i].pop_back();
    	}
    	if(ans % 2 == 1) ans -= last;
    }
    cout << ans << endl;

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}