#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
#define y1 sda
using namespace std;    
const int N = int(1e6) + 10, mod = int(1e9)  + 7; 

int n, a[N];
int sum[11][11][11][11][11][11], d[11][11][11][11][11][11], cnt[11][11][11][11][11][11];
int dp[11][11][11][11][11][11];

int p2[N + 3];

void add(int &a,int b){
	a += b;
	if(a >= mod) a -= mod;
}

int main () {
	scanf("%d",&n);
	p2[0] = 1;
	for(int i = 1; i <= N; i++){
		p2[i] = p2[i - 1] * 2ll % mod;
	}
	for(int i = 1,x; i <= n; i++){
		scanf("%d",&x);
		int y = x;
		vi dg;
		while(x > 0){
			dg.pb(x % 10);
			x /= 10;
		}
		while(dg.size() < 6) dg.pb(0);
		reverse(dg.begin(), dg.end());
		add(sum[dg[0]][dg[1]][dg[2]][dg[3]][dg[4]][dg[5]],y); 
		cnt[dg[0]][dg[1]][dg[2]][dg[3]][dg[4]][dg[5]] += 1;
		add(d[dg[0]][dg[1]][dg[2]][dg[3]][dg[4]][dg[5]],1ll * y * y % mod);
	}
	for(int i0 = 9; i0 >= 0; i0--){
		for(int i1 = 9; i1 >= 0; i1--){
			for(int i2 = 9; i2 >= 0; i2--){
				for(int i3 = 9; i3 >= 0; i3--){
					for(int i4 = 9; i4 >= 0; i4--){
						for(int i5 = 9; i5 >= 0; i5--){
							for(int mask = 1; mask < (1<<6); mask++){
								int y0 = i0 + ((mask >> 0) & 1);
								int y1 = i1 + ((mask >> 1) & 1);
								int y2 = i2 + ((mask >> 2) & 1);
								int y3 = i3 + ((mask >> 3) & 1);
								int y4 = i4 + ((mask >> 4) & 1);
								int y5 = i5 + ((mask >> 5) & 1);
								if(__builtin_popcount(mask) & 1){
									add(sum[i0][i1][i2][i3][i4][i5],sum[y0][y1][y2][y3][y4][y5]);
									add(cnt[i0][i1][i2][i3][i4][i5],cnt[y0][y1][y2][y3][y4][y5]);
									add(d[i0][i1][i2][i3][i4][i5],d[y0][y1][y2][y3][y4][y5]);	
								}
								else{
									add(sum[i0][i1][i2][i3][i4][i5],mod - sum[y0][y1][y2][y3][y4][y5]);
									add(cnt[i0][i1][i2][i3][i4][i5],mod - cnt[y0][y1][y2][y3][y4][y5]);
									add(d[i0][i1][i2][i3][i4][i5],mod - d[y0][y1][y2][y3][y4][y5]);
								}
							}
						}
					}
				}
			}
		}
	}
	for(int i0 = 9; i0 >= 0; i0--){
		for(int i1 = 9; i1 >= 0; i1--){
			for(int i2 = 9; i2 >= 0; i2--){
				for(int i3 = 9; i3 >= 0; i3--){
					for(int i4 = 9; i4 >= 0; i4--){
						for(int i5 = 9; i5 >= 0; i5--){
							int cn =  cnt[i0][i1][i2][i3][i4][i5];
							ll s = sum[i0][i1][i2][i3][i4][i5];
							int dd = d[i0][i1][i2][i3][i4][i5];
							if(cn == 1) dp[i0][i1][i2][i3][i4][i5] = dd;
							else{
								dp[i0][i1][i2][i3][i4][i5] = p2[cn - 2] * ((s * s % mod + dd) % mod) % mod;	
							}
						}
					}
				}
			}
		}
	}
	ll  ans = 0;
	for(int i0 = 9; i0 >= 0; i0--){
		for(int i1 = 9; i1 >= 0; i1--){
			for(int i2 = 9; i2 >= 0; i2--){
				for(int i3 = 9; i3 >= 0; i3--){
					for(int i4 = 9; i4 >= 0; i4--){
						for(int i5 = 9; i5 >= 0; i5--){
							int x = i0 * 100000 + i1  * 10000 + i2 * 1000 + i3 * 100 + i4 * 10 + i5;
							int cur = dp[i0][i1][i2][i3][i4][i5];
							for(int mask = 1; mask < (1<<6); mask++){
								int y0 = i0 + ((mask >> 0) & 1);
								int y1 = i1 + ((mask >> 1) & 1);
								int y2 = i2 + ((mask >> 2) & 1);
								int y3 = i3 + ((mask >> 3) & 1);
								int y4 = i4 + ((mask >> 4) & 1);
								int y5 = i5 + ((mask >> 5) & 1);
								if(__builtin_popcount(mask) & 1){
									add(cur,mod - dp[y0][y1][y2][y3][y4][y5]);
								}
								else{
									add(cur,dp[y0][y1][y2][y3][y4][y5]);
								}
							}
							ll res = 1ll * cur * x;
							ans ^= res;
						}
					}
				}
			}
		}
	}
	printf("%lld", ans);
return 0;
}