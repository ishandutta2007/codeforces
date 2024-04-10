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

int n;
int a[2222];

ll dp[212222];
ll d[212222];

long double z[220222];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    sort(a, a + n);

    for(int i = 0; i < n; i++){
    	for(int j = i + 1; j < n; j++){
    		dp[a[j] - a[i]]++;
    	}
    }
    for(int i = 0; i < 6000; i++){
    	for(int j = 0; j < 6000; j++){
    		d[i + j] += dp[i] * 1ll * dp[j];
    	}
    }
    long double ans = 0, cur = 0, t = 0;

	for(int i = 1; i < 100000; i++){
		z[i] = t;
		cur = d[i];
		cur *= 8;
		for(int k = 0; k < 3; k++){
    		cur/=n;
    		cur /= n - 1;
    	}
    	t += cur;
	}
    for(int i = 0; i < n; i++){
    	for(int j = i + 1; j < n; j++){
    		cur = z[a[j] - a[i]];
    		
    		ans += cur;
    		
    	}
    }
    printf("%.12lf\n", (double)ans); 
    

    


    

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}