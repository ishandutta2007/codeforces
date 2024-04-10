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



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    ll n, x = 8 * 9 * 5 * 7;
    vector < int > c = {2, 3, 5, 7};
    cin >> n;
    ll ans = n;
    for(int i = 1; i<(1<<4); i++){
    	int cur = 1;
    	int sgn = 1;
    	for(int j = 0; j < 4; j++){
    		if(i & ( 1<<j)) {
    			cur *= c[j];
    			sgn *= -1;
    		}
    	}
    	ans += (n/cur) * sgn;
    }
    cout << ans << endl;
    

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}