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

int d[100100];
int u[100100];
int n;
char c[100100];

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d", &n);
    scanf("%s", c);
    int x = 1;
    for(int i = 1; i <= n; i++){
    	scanf("%d", &d[i]);
    }
    while(1 <= x && x <= n){
    	if(u[x]) break;	
	    u[x] = 1;
	    int y = d[x];
	    if(c[x-1] == 60){
		    x = x - y;
		}
		else 
			x = x + y;
    }
    
    if(1 <= x && x <= n){
    	cout << "INFINITE";
    }
    else cout << "FINITE";



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}