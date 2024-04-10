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

int ac[5555];
int bc[5555];
int a[5555];
int b[5555];

int n,m ,k;
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1, t, x, c; i <= k; i++){
    	scanf("%d %d %d", &t, &x, &c);
    	if( t== 1){
    		a[x] = i;
    		ac[x] = c;
    	}
    	else {
    		b[x] = i;
    		bc[x] = c;
    	}
    }
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j<=m; j++){
    		if(a[i] < b[j]) printf("%d ", bc[j]);
    		else printf("%d ", ac[i]);
    	}
    	printf("\n");
    }
    


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}