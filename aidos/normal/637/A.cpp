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

pii a[1111];
int n, ans, ti;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> a[i].f;
    	a[i].s = i;
    }
    sort(a, a + n);
    for(int i = 0; i < n; ){
    	int j = i;
    	while(i < n && a[j].f == a[i].f) i++;
    	if(i - j > ans){
    		ans = i - j;
    		ti = i - 1;
    	}
    	else if( i - j == ans){
    		if(a[ti].s > a[i-1].s) ti = i - 1;
    	}
    }
    cout << a[ti].f << endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}