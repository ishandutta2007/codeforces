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

vector < int > ans;
int dp[100100];
int m;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> m;
    for(int i = 1; i <= 1000000; i++){
    	int j = i;
    	int cur = 0;
    	while(j > 0){
    		cur += j/5;
    		j /= 5;
    	}
    	if(cur == m) ans.pb( i );
    }
    cout << ans.size() << endl;
    for(int x: ans) cout << x << " ";


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}