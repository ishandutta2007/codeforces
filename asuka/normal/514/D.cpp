#include<bits/stdc++.h>
#define ll long long
#define N 100015
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
int n, m, k, a[6][N], Log[N], ans[6];
struct RMQ {
	int Max[N][21];
	void init(int *a) {
		rep(i, 1, n) Max[i][0] = a[i];
		rep(j, 1, 19) {
			rep(i, 1, n) {
				if(i + (1 << j) - 1 > n) break;
				Max[i][j] = max(Max[i][j - 1], Max[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
	int query(int l, int r) {
		int K = Log[r - l + 1];
		return max(Max[l][K], Max[r - (1 << K) + 1][K]);
	}
} T[6];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 2, n) Log[i] = Log[i >> 1] + 1;
	rep(i, 1, n) rep(j, 1, m) scanf("%d", &a[j][i]);
	rep(i, 1, m) T[i].init(a[i]);
	for(int l = 1, r = 1; r <= n; r++) {
		while(l <= r) {
			int sum = 0;
			rep(i, 1, m) sum += T[i].query(l, r);
			if(sum > k) l++;
			else {
				if(r - l + 1 > ans[0]) {
					ans[0] = r - l + 1;
					rep(i, 1, m) ans[i] = T[i].query(l, r);	
				}
				break;
			}
		}
	}
	rep(i, 1, m) printf("%d ", ans[i]);
	return 0;
}