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

char c[1000100];
int n, m, k;
int la[100];
ll sum[100];

ll prevc[100];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d", &n, &k);
    scanf("%s", c);
    m = strlen(c);
    n += m;
    memset(la, -1, sizeof la);
    ll ans = 1;
    for(int i = 0; i < n; i++){
    	if(i < m){
    		int cc = c[i] - 'a';

    		//cout << cc << " " << ans << " "<< sum[cc] << endl;
    		if(la[cc] == -1){
				sum[cc] = ans;
    		}
    		else {
    			sum[cc] = ans - prevc[cc];
    		}
    		prevc[cc] = ans;
    		if(sum[cc] < 0) sum[cc] += mod;
    		if(sum[cc] >= mod) sum[cc] -= mod;

    		ans += sum[cc];
    		la[cc] = i;
    		if(ans < 0) ans += mod;
    		if(ans >= mod) ans -= mod;
    	}
    	else {
    		int cc = 0;
    		for(int j= 0; j < k; j++){
    			if(la[j]  < la[cc] ) cc = j;
    		}
    		
			//cout << cc << " " << ans << " "<< sum[cc] << endl;
    		if(la[cc] == -1){
				sum[cc] = ans;
    		}
    		else {
    			sum[cc] = ans - prevc[cc];
    		}
    		prevc[cc] = ans;
    		
    		if(sum[cc] < 0) sum[cc] += mod;
    		if(sum[cc] >= mod) sum[cc] -= mod;

    		ans += sum[cc];
    		la[cc] = i;
    		if(ans < 0) ans += mod;
    		if(ans >= mod) ans -= mod;
    	}
    }
    cout << ans<<endl;


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}