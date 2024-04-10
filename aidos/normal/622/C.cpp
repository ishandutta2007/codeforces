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
int a[200200];
int nxt[200200];
int m;

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    	scanf("%d", &a[i]);
	for(int i=1; i <= n; i++){
		if(a[i] == a[i-1]) nxt[i] = nxt[i-1];
		else nxt[i] = i-1;	
	}
	for(int i=0, l, r, x; i < m; i++){
		scanf("%d %d %d", &l, &r, &x);
		printf("%d\n", a[r] != x? r : nxt[r] < l ? -1: nxt[r]);
	}




    



    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}