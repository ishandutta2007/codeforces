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


int n, h, d;
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> d >> h;
    
    if( h == n - 1){
    	for(int i = 1; i < n; i++){
    		cout << i << " " << i + 1 << "\n";
    	}
    	return 0;
    }
    if(h + h < d) {
    	cout << -1 << endl;
    	return 0;
    }
    if( d == 1){
    	cout << -1 << endl;
    	return 0;
    }
    for(int i = 2; i <= h+ 1; i++){
    	printf("%d %d\n", i-1, i);
    }
    if( h == d){
    	for(int i = h + 2; i <= n; i++){
    		printf("%d %d\n", 2, i);
    	}
    	return 0;
    }
    d -= h;
    for(int i = h + 2; i <= n; i++){
    	if( i == h + 2){
    		printf("1 %d\n", i);
    		d--;
    	}
    	else if(d > 0){
    		printf("%d %d\n", i-1, i); 
    		d--;
    	}
    	else {
    		printf("%d %d\n", 1, i); 
    	}
    }





    





    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}