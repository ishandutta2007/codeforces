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

#define MAXN (int) (2e5)
using namespace std;

int a[MAXN], n, m;
bool used[MAXN];
char x[MAXN];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif         
    cin >> n >> m;
    int k = -1;
    for(int i = 0; i < m; i++){
    	cin >> x[i] >> a[i];
    	if(x[i] == '-'){
    		if(!used[a[i]]){
    			k = i;	
    		}
    	}
    	used[a[i]] = 1;
    }
    vector <int> ans;
    for(int i  = 1; i <= n; i++){
    	if(!used[i]) ans.pb(i);
    }
    if( k == -1){
    	memset(used, 0, sizeof(used));
    	bool ok = 1;
    	int cur = 0;
    	for(int i = 1; i<m; i++){
    		if(a[i] == a[0]){
    			if(cur != 0) ok = false;
    			if( i +1 < m && a[i] != a[i+1] ) ok = false;
    			i++;
    		}
    		else 
    		if( used[a[i]] ){
    			used[a[i]] = false;
    			cur--;
    		}
    		else {
    			used[a[i]] = 1;
    			cur++;
    		}
    	}
    	if(ok == 1){
    		ans.pb(a[0]);
    	}
    }
    else {
    	memset(used, 0, sizeof(used));
    	int cur = 0;
    	for(int i = 0; i < k; i++){
    		if(used[a[i]]){
    			cur--;
    			used[a[i]] = 0;
    		}
    		else if(x[i] != '-'){
    			used[a[i]] = 1;
    			cur++;
    		}
    	}
    	if(cur == 0){
    		if( k == m-1) ans.pb(a[k]);
    		else if( a[k+1] == a[k] ){
    			memset(used, 0, sizeof(used));
    			cur = 0;
    			bool ok = 1;
    	for(int i = k+2; i<m; i++){
    		if(a[i] == a[k]){
    			if(cur != 0) ok = false;
    			if(i+1 < m && a[i] != a[i+1] ){
    				ok = false;
    			}
    			i++;
    		}
    		else 
    		if( used[a[i]]){
    			used[a[i]] = false;
    			cur--;
    		}
    		else {
    			used[a[i]] = 1;
    			cur++;
    		}
    	}
    	if(ok == 1){
    		ans.pb(a[k]);
    	}
    		}
    	}
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for(int i = 0; i< ans.size(); i++){
    	cout << ans[i] << " ";
    }
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}