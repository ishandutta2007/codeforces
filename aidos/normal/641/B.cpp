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

pii q[111][111];
int a[111][111];
int n, m, qq;
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d %d", &n, &m, &qq);
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		q[i][j] = mp(i, j);
    	}
    }
    for(int i = 0, type, x, y, r; i < qq; i++){
    	scanf("%d", &type);
    	if(type == 1){
    		scanf("%d", &x);
    		pii c = q[x][1];
    		for(int j = 1; j < m; j++)
    			q[x][j] = q[x][j+1];
			q[x][m] = c;
    	}
    	else if(type == 2){
    		scanf("%d", &y);
    		
    		pii c = q[1][y];
    		for(int j = 1; j < n; j++)
    			q[j][y] = q[j+1][y];
			q[n][y] = c;
    	}
    	else {
    		scanf("%d %d %d", &x, &y, &r);
    		int v1 = q[x][y].f;
    		int v2 = q[x][y].s;
    		a[v1][v2] = r;
    	}
    }
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		printf("%d ", a[i][j]);
    	}
    	printf("\n");
    }

    


    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}