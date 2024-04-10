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
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    string a;
    cin >> a;
    int n = a.size();
    for(int i = 0; i <n; i++){
    	string ans= "";
    	for(int k = 0; k < i; k++){
    		ans += a[k];
    	}
    	for(int j = i; j < n; j++){
    		if(ans + a.substr(j) == "CODEFORCES"){
    			cout << "YES\n";
    			return 0;
    		}
    	}
    	if(ans == "CODEFORCES"){

    			cout << "YES\n";
    			return 0;
    	}
    }
    cout  << 	"NO\n";




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}