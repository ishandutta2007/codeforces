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


vector <pii> g[100100];
int fact[100100];
int rev[100100];
int m;
vector<int> ans;
char c[100100];
int cur[100100];
int n;
int power[100100];

int getC(int n, int k){
	return fact[n] * 1ll * rev[n-k] % mod * 1ll * rev[k] % mod;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d", &m);
    scanf("%s", c);
    n = strlen(c);
    for(int i = 0, t, x; i < m; i++){
    	scanf("%d", &t);
    	if(t == 1){	
		    scanf("%s", c);
		    n = strlen(c);
    	}
    	else {
    		scanf("%d", &x);
    		g[n].pb(mp(ans.size(), x));
    		ans.pb(0);
    	}
    }
    fact[0] = 1;
    rev[0] = 1;
    power[0] = 1;
    for(int i = 1; i < 100010; i++){
    	fact[i] = (fact[i-1] * 1ll * i) % mod;
    	power[i] = power[i-1] * 25ll % mod;
    	int pw = mod-2;
    	int t = fact[i];
    	rev[i] = 1;
    	while(pw > 0){
    		if(pw & 1) rev[i] = (rev[i] * 1ll * t) % mod;
    		t = (t * 1ll * t ) % mod;
    		pw /= 2;
    	}
    }
    for(int i = 0; i < 100100; i++){
    	if(g[i].size()){
    		for(int j = 0; j < 100100; j++) {
    			cur[j] = 0;
    		}
			int x = 0;
			for(int j = i; j<100100; j++){
				x = (x * 26ll + getC(j-1, i - 1) * 1ll * power[j - i]) % mod;
				cur[j] = x;
			}
			for(int j = 0; j < g[i].size(); j++)
				ans[g[i][j].f] = cur[g[i][j].s];	
    	}
    }
    for(int i = 0; i < ans.size(); i++)
    	printf("%d\n", ans[i]);




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}