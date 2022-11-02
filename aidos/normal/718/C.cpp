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

using namespace std;
int mod = 1000000007;
int t[400400];
int ad[400400][4][4];
int sum[400400][4][4];
int a[400400];
int g[4][4];
int c[4][4];
int te[4][4];
void binpow(int nn){
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			g[i][j] = (i==j);
			c[i][j] = 1;
		}
	}
	c[1][1] = 0;
	while(nn > 0){
		if(nn & 1){
			for(int i = 0; i < 2; i++){
				for(int j = 0; j < 2; j++){
					te[i][j] = 0;
					for(int k = 0; k < 2; k++){
						te[i][j] = (g[i][k] * 1ll * c[k][j]+ te[i][j]) % mod;
					}
				}
			}
			for(int i = 0; i < 2; i++){
				for(int j = 0; j<2; j++){
					g[i][j] = te[i][j];
				}
			}
		}
		for(int i = 0; i < 2; i++){
				for(int j = 0; j < 2; j++){
					te[i][j] = 0;
					for(int k = 0; k < 2; k++){
						te[i][j] = (c[i][k] * 1ll * c[k][j]+ te[i][j]) % mod;
					}
				}
			}
			for(int i = 0; i < 2; i++){
				for(int j = 0; j<2; j++){
					c[i][j] = te[i][j];
				}
			}

		nn>>=1;
	}
}

void push(int v, int l, int r){
		
	for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++){
				te[i][j] = 0;
				for(int k = 0;k < 2; k++){
					te[i][j] = (ad[v * 2][i][k] * 1ll * ad[v][k][j] + te[i][j]) % mod;
				}
			}
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				ad[v * 2][i][j] = te[i][j];
			}
		}
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++){
				te[i][j] = 0;
				for(int k = 0;k < 2; k++){
					te[i][j] = (ad[v * 2+1][i][k] * 1ll * ad[v][k][j] + te[i][j]) % mod;
				}
			}
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				ad[v * 2+1][i][j] = te[i][j];
			}
		}
			for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++){
				te[i][j] = 0;
				for(int k = 0;k < 2; k++){
					te[i][j] = (sum[v * 2][i][k] * 1ll * ad[v][k][j] + te[i][j]) % mod;
				}
			}
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				sum[v * 2][i][j] = te[i][j];
			}
		}
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++){
				te[i][j] = 0;
				for(int k = 0;k < 2; k++){
					te[i][j] = (sum[v * 2+1][i][k] * 1ll * ad[v][k][j] + te[i][j]) % mod;
				}
			}
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				sum[v * 2+1][i][j] = te[i][j];
			}
		}
	
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			ad[v][i][j] = (i == j);
}


void upd(int v, int l, int r, int tl, int tr){
	if(tl > tr) return;
	if(l == tl && tr == r){
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++){
				te[i][j] = 0;
				for(int k = 0;k < 2; k++){
					te[i][j] = (sum[v][i][k] * 1ll * g[k][j] + te[i][j]) % mod;
				}
			}
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				sum[v][i][j] = te[i][j];
			}
		}
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++){
				te[i][j] = 0;
				for(int k = 0;k < 2; k++){
					te[i][j] = (ad[v][i][k] * 1ll * g[k][j] + te[i][j]) % mod;
				}
			}
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				ad[v][i][j] = te[i][j];
			}
		}
		return;
	}
	int mid = (l + r)>>1;
	push(v, l, r);
	upd(v * 2, l, mid, tl, min(tr, mid));
	upd(v * 2 + 1, mid + 1, r, max(mid+1, tl), tr);
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++){
			sum[v][i][j] = (sum[v * 2][i][j] + sum[v *2 + 1][i][j]) % mod;
		}
}

ll get(int v, int l, int r, int tl, int tr){
	if(tl > tr) return 0;
	if(tl == l && tr == r) {
		return sum[v][1][0];
	}
	push(v, l, r);
	int mid = (l + r)>>1;
	ll a1 = get(v * 2, l, mid, tl, min(tr, mid));
	ll a2 = get(v *2 + 1, mid+1, r, max(tl, mid+1), tr);
	return (a1 + a2) % mod;
}

void build(int v, int l, int r){
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++){
			ad[v][i][j] =(i==j);
		}
	if(l == r){
		binpow(a[l]);
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				sum[v][i][j] = g[i][j];
		return;
	}
	int mid = (l + r) >> 1;
	build(v * 2, l, mid);
	build(v * 2 + 1, mid+1, r);
	for(int i = 0; i <2; i++)
		for(int j = 0; j < 2; j++){
			sum[v][i][j] = (sum[v * 2][i][j] + sum[v * 2 + 1][i][j]) % mod;
		}

}

int n, m;
void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	build(1, 0, n-1);
	for(int i = 0, l, r, x, ty; i < m; i++){
		scanf("%d%d%d", &ty, &l, &r);
		if(ty == 1){
			scanf("%d", &x);
			binpow(x);
			upd(1, 0, n-1, l-1, r-1);
		}
		else {
			printf("%d\n", get(1, 0, n-1, l-1, r-1) % mod);
		}
	}
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}