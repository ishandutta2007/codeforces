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

int n, m;

int ok(int x){
	int y = x/2;
	int z = x/3;
	int c = x/6;
	if(n > y) return 0;
	if(m > z) return 0;
	return (y + z - c ) >= (n + m);
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> m;
    int l = 0, r = 1e9;
    int ans =0;
    while(l <= r){
    	int mid = (l + r)>>1;
    	if(ok(mid)){
    		r = mid-1;
    		ans = mid;
    	}
    	else {
    		l = mid+1;
    	}
    }
    cout << ans << endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}