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



int n;
int k;
map < int, int > m;
vector < pii > v;
map < int, int > mx[100100];

int a[5050];



int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
          
    cin >> n >> k;
    for(int i = 0, w; i < n; i++){
    	cin >> w;
    	for(int j = 1; j <= k; j++){
    		if(m.count(j * w)) m[j * w] = min(m[j * w], j);
    		else m[j * w] = j;
    	}
    	a[i] = w;
    }        
    

    int q;
    cin >> q;
    for(int t = 0, x; t < q; t++){
    	cin >> x;
    	int ans = k+1;
    	for(int i = 0; i < n; i++){
    		for(int j = 0; j <= k; j++){
    			if(m.count(x - j * a[i])){
    				ans = min(ans, j + m[x-j * a[i]]);
    			}
    		}
    	}
    	if(ans > k) ans = -1;
    	cout << ans << endl;
    }

    






    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}