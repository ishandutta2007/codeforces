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

vector < pii > v;

int cntx[200200];
int cnty[200200];

int mid = 100100;


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
    	int x, y;
    	cin>> x>>y;
    	cntx[x + y + mid]++;
    	cnty[y - x + mid]++;
    }
    ll ans = 0;
    for(int i = 0; i < 200000; i++){
    	ans += (cntx[i] - 1) * 1ll * (cntx[i])/2;
    	ans += (cnty[i] - 1) * 1ll * (cnty[i])/2;
    }
    cout << ans << endl;


    

    
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}