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
    ll ans = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    	for(int j = i; j < n; j++)
    		for(int k = j; k < n; k++){
    			int t = n - k;
    			ans += t * (t + 1)/2;
    		}
	ll cur = 0;
	for(int i = 0; i <n; i++)
		for(int j = i; j < n; j++)
			for(int k = j; k < n; k++)
				cur += ans;
	cout << cur << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}