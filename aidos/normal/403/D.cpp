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
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int, string>
#define psi pair<string, int>
using namespace std;
int d[50][1003][1003], mod = (ll)(1e9 + 7);
ll fact[55];
void precalc(){
	fact[0] = 1;
	for(int i = 1; i < 50; i++) fact[i] = (fact[i-1] * 1ll*i) % mod;
	for(int i = 0; i < 1002; i++)
		for(int j = 0; j < 1002; j++)
			d[0][i][j] = 1;
	for(int k = 1; k < 50; k++)
		for(int i = 1; i < 1002; i++)
			for(int j  = 1; j < 1002; j++){
				ll res = 0;
				res = ((ll)(d[k][i-1][j] + d[k][i][j-1])) % mod;
				res -= d[k][i-1][j-1];
				if(res < 0) res += mod;
				if(j >= i){
					res = ((ll)(res + d[k-1][i-1][j-i]))% mod;
				}
				d[k][i][j] = (int) (res % mod);
			}
}
int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    precalc();
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
    	int x, y;
    	ll res = 0;
    	scanf("%d %d", &x, &y);
    	if(y < 45) res = (fact[y] * 1ll* d[y][x][x]) % mod;
    	printf("%I64d\n", res);
    }
    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}