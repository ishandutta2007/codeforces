#include<bits/stdc++.h>
#define ll long long
#define N 1015
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
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
int n, k, y, p;
bool ok[N];
ll sum[N], sum2[N], v, vv, a[N][N];;
int main(){
	// freopen("D.in","r",stdin);
	// freopen("D.out","w",stdout);
	scanf("%d%d", &n, &k);
	rep(i, 1, k) {
		rep(j, 1, n) scanf("%lld", &a[i][j]);
	}
	rep(i, 1, k) rep(j, 1, n) sum[i] += a[i][j];
	rep(i, 1, k) rep(j, 1, n) sum2[i] += a[i][j] * a[i][j];
	v = (sum[k] - sum[1]) / (k - 1);
	ok[1] = ok[k] = 1;
	rep(i, 2, k - 1){
		if(sum[i] == (sum[1] + (i - 1) * v) ) ok[i] = 1;
	}
	rep(i, 2, k - 1) {
		if(ok[i - 1] && ok[i] && ok[i + 1]) {
			vv = (sum2[i + 1] - sum2[i]) - (sum2[i] - sum2[i - 1]);
			vv /= 2;
			break;
		}
	}
	rep(i, 2, k - 1) {
		if(!ok[i]) {
			y = i;
			ll delta = sum[i - 1] + v - sum[i];
			rep(j, 1, n) {
				ll nsum2 = sum2[i] - (a[i][j] * a[i][j]) + (a[i][j] + delta) * (a[i][j] + delta);
				if((sum2[i + 1] + sum2[i - 1] - 2 * nsum2) == 2 * vv) {
					p = a[i][j] + delta;
					break;
				}
			}
		}
	}
	printf("%d %d\n", y - 1, p);
	fflush(stdout);
	return 0;
}