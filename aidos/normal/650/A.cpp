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
map <int, int > m1, m2;
map < pii, int > m3;
int n, x, y;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    ll ans= 0;
    for(int i = 0; i < n; i++){
    	cin >> x >> y;
    	ans += m1[x];
    	ans += m2[y];
    	ans -= m3[mp(x, y)];
    	m1[x]++;
    	m2[y]++;
    	m3[mp(x, y)]++;
    }
    cout << ans<<endl;
    


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}