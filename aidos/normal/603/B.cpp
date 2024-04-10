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


int was[1000100];
int n, k;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> k;
    int a = 1;
    if(k == 1) {
    	for(int i = 0; i<n; i++)
    		a =(a * 1ll * n) % mod;
    }
    else {
    	for(int i = 0, j = 0; i < n; i++){
    		j = i;
    		if(!was[j] && j > 0) a = (a * 1ll * n) % mod;
    		while(!was[j]){
    			was[j] = 1;
    			j = (j * 1ll * k) % n;
    		}
    	}
    }
    cout << a << endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}