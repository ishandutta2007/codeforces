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

string x;
int n, k;
int dp[100100];
int p[100100];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> k;
    cin >> x;
    int sum = 0;
    int ans=  n + 1;
    for(int i = 0; i < n; i++){
    	
    	if(x[i] == '0') {
    		sum++;
    		p[sum] = i;
    		if(sum > k){
    			int l = p[sum - k];
    			int c = (l + i ) >> 1;
    			l = sum - k;
    			int r = sum;
    			int t = sum;
    			while(l<=r){
    				int mid = (l + r) >> 1;
    				if(p[mid] <= c) {
    					t = mid;
    					l = mid + 1;
    				}
    				else r = mid-1;
    			}
    			if(t < sum) {
    				ans = min(ans, max(p[t+1] - p[sum - k], p[sum] - p[t+1]));
    			}
    			ans = min(ans, max(p[t] - p[sum - k], p[sum] - p[t]));
    		}
    	}
    	else {
    		
    	}
    }
    
    cout << ans << endl;

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}