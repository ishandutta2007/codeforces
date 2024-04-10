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

#define MAXN (int) (1e7)
using namespace std;
char c[1000010];
int a[1000010], b[1000010], d[1000010];
bool num(char x){
	if(x >= '0' && x <= '9') return 1;
	return 0;
}
bool isLet(char x){
	if(x >= 'a' && x <= 'z') return 1;
	return 0;
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    scanf("%s", &c);
    int n = strlen(c);
    for(int i = 0; i < n; ){
    	int j = i;
    	while(isLet(c[j]) && j < n) j++;
    	while( i< j) {
    		a[i] = j - i;
    		i++;
    	}
    	i = j+1;
    }
    for(int i = 0; i < n; ){
    	int j = i;
    	while((isLet(c[j]) || num(c[j]))&& j < n) j++;
    	while( i<= j) {
    		b[i] = j;
    		i++;
    	}
    	i = j+1;
    }
    for(int i = n-1; i>=0; ){
    	
    	int j = i;
    	while((isLet(c[j]) || num(c[j]) || c[j] == '_')&& j>=0) j--;
    	int cnt = 0, x = j + 1;
    	while( i >= x){    	
    		cnt += isLet(c[x]);
    		d[x] = cnt;
    		x++;
    	}	
    	i = j - 1;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
    	if(c[i] == '@'){
    		int ans1 = 0, ans2 = 0;
    		if( i > 0) ans1 = d[i-1];
    		if( i+1 < n){
    			int j = b[i+1];
    			if(j+1 < n && j != i+1&& c[j] == '.'){
    				ans2 = a[j+1];
    			}
    		}
    		ans += ans1 * 1ll*ans2;
    	}
    }
    cout << ans << endl;
    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}