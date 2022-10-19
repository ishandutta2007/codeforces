#include<bits/stdc++.h>
#define ll long long
#define N 505
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int mod = 998244353;
int n, x, f[N][N], C[N][N], pd[N][N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &x);
	rep(i, 0, n) {
		C[i][0] = 1;
		rep(j, 1, i) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod; 
	}
	rep(i, 1, max(n, x)) {
		pd[i][0] = 1;
		rep(j, 1, max(n, x)) {
			pd[i][j] = (ll) pd[i][j - 1] * i % mod;
		}
	}
	rep(i, 1, n) {
		rep(j, 1, x) {
			if(i == 1) f[i][j] = j;
			else {
				rep(ii, 1, i) {
					if(j - i + 1 > 0) (f[i][j] += (ll) f[ii][j - i + 1] * C[i][ii] % mod * pd[i - 1][i - ii] % mod) %= mod;
				}
			}
		}
	}
	printf("%d\n", (pd[x][n] + mod - f[n][x]) % mod);
	return 0;
}