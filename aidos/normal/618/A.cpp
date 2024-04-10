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


vector < int > v;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
    	v.pb(1);
    	while(v.size() > 1){
    		int ind = v.size();
    		if(v[ind-1] == v[ind-2]){
    			v.pop_back();
    			v[ind-2]++;
    		}
    		else break;
    	}
    }
    for(int x: v){
    	cout << x << " ";
    }
    	


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}