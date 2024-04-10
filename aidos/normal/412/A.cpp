#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define Vint vector < int >
#define Vll vector < ll >
#define Vb vector < bool >
#define Vpii vector < pii >
#define Vpll vector < pll >

const int inf = (1ll << 31) - 1;

#define MAXN (int) (1e7)
using namespace std;


int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    string  S;
    cin >> S;
    k--;
    if(k < n - k){
    	while(k > 0){
    		cout << "LEFT\n";
    		k--;
    	}
    	for(int i = 0; i < n; i++){
    		cout << "PRINT " << S[i] << endl;
    		if(i != n -1) cout << "RIGHT\n";
    	}
    }
    else {
    	while(k < n-1){
    		cout << "RIGHT\n";
    		k++;
    	}
    	for(int i = n-1; i >= 0; i--){
    		cout << "PRINT " << S[i] << endl;
    		if(i != 0) cout << "LEFT\n";
    	}
    }
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}