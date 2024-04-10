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


vector < string > v;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int n;
    cin >> n;
    v.pb( "+");
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < ( 1 << i ); j++){
    		string x = v[j];
    		for(int t = 0; t < x.size(); t++){
    			if( x[t] == '+') x[t] = '*';
    			else x[t] = '+';
    		}
    		v.pb(v[j] + x);
    		v[j] += v[j];
    	}
    }
    for(int i = 0; i < v.size(); i++){
    	for(int j = 0; j < v.size(); j++){
    		cout << v[j][i];
    	}
    	cout << endl;
    }
    


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}