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
    ll cur = 1;
    for(int i = 0; i < 5; i++){
    	cur *= (n - i);
    }
    for(int i = 0; i < 5; i++){
    	cur /= i + 1;
    }
    ans += cur;
    for(int i = 5; i < 6; i++)
    	cur *= n- i;
	for(int i = 5; i < 6; i++)
    	cur /= i+1;
	ans += cur;

    for(int i = 6; i < 7; i++)
    	cur *= n- i;
	for(int i = 6; i < 7; i++)
    	cur /= i+1;
	ans += cur;
	cout << ans << endl;

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}