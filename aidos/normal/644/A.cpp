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


int n, x, y;
int d[111][111];
vector<int> g1, g2;
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> x >> y;
    int st1 = -1, st2 = 0;
    for(int i = 0; i < x; i++){
    	for(int j = 0; j < y; j++){
    		if(i % 2 == j % 2){
    			st1 += 2;
    			d[i][j] = st1;
    		}
    		else {
    			st2 += 2;
    			d[i][j] = st2;
    		}
    	}
    }
    st1 += 2;
    st2 += 2;
    if(st1 <= n || st2 <= n){
    	cout << -1 << endl;
    	return 0;
    }
    for(int i = 0; i < x; i++){
    	for(int j = 0; j < y; j++){
    		if(j) cout << " ";
    		if(d[i][j] <= n) cout << d[i][j];
    		else cout << 0;
    	}
    	cout << endl;
    }



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}