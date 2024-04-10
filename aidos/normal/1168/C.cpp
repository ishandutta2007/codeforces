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
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int n, q;
int a[300300];
int c[520][20][20];
int b[520][20];
int lg[555];
int K = 600;
void precalc(int bl){
	for(int i = 0; i < 20; i++) {
		int x = (1<<i);
		for(int j = bl * K; j < min(bl * K + K, n); j++){
			if(a[j] & x) {
				x |= a[j];
			}
		}
		b[bl][i] = x;
	}
}
void precalc2(int en){
	for(int i = 0; i <= en; i++){
		for(int j = 0; j < 20; j++){
			c[i][0][j] = b[i][j];
		}
	}
	lg[0] = -1;
	for(int i = 1; i <= en + 1; i++){
		lg[i] = lg[i/2] + 1;
	}
	for(int len = 1; (1<<len) <= en; len++){
		for(int j = 0; j + (1<<len)<=en; j++){
			for(int i = 0; i < 20; i++){
				int mask = c[j][len-1][i];
				int &res = c[j][len][i];
				
				for(int t = 0; t < 20; t++){
					if(mask & (1<<t)) {
						res |= c[j+(1<<(len-1))][len-1][t];
					}
				}
			}
		}
	} 
}
int get2(int l, int r, int mask) {
	for(int d=12; d >=0; d--){
		if((l + (1<<d) - 1) <= r) {
			int res=mask;
			for(int i = 0; i < 20; i++){
				if(mask & (1<<i)) {
					res |= c[l][d][i];	
				}
			}
			mask = res;
			l += (1<<d);
		}
	}
	return mask;
}
int get(int x, int y) {
	int l = x/K;
	int r = y/K;
	if(l == r) {
		int cur = a[x];
		for(int i = x; i <= y; i++) {
			if(cur&a[i]) cur |= a[i];
		}
		return cur&a[y];
	}
	int cur = a[x];
	for(int i = x; i < (l+1) * K; i++) {
		if(cur & a[i]) cur |= a[i];
	}
	int mask2 = get2(l + 1, r-1, cur);
	for(int i = r * K; i <= y; i++) if(mask2&a[i]) mask2 |= a[i];
	return mask2 & a[y];
}
void solve(){
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i * K < n; i++) {
		precalc(i);
	}
	precalc2((n-1)/K);
	for(int i = 0; i < q; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		if(get(x-1, y-1)) {
			printf("Shi\n");
		}else{
			printf("Fou\n");
		}
	}
}

int main () {
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}