#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const int INF=1e9+7, LIM=407;
int sum[LIM][LIM];
int f(int a, int b, int c, int d) {
	return sum[c+1][d+1]-sum[a][d+1]-sum[c+1][b]+sum[a][b];
}
void solve() {
	int n, m;
	cin >> n >> m;
	string T[n];
	rep(i, n+2) rep(j, m+2) sum[i][j]=0;
	rep(i, n) {
		cin >> T[i];
		rep(j, m) {
			sum[i+1][j+1]=sum[i][j+1]+sum[i+1][j]-sum[i][j]+T[i][j]-'0';
		}
	}
	int ans=INF;
	rep(i, n) {
		for(int j=i+4; j<n; ++j) {
			int akt=2*(j-i-1)-f(i+1, 0, j-1, 0)-f(i+1, 3, j-1, 3);
			akt+=f(i+1, 1, j-1, 2);
			akt+=4-f(i, 1, i, 2)-f(j, 1, j, 2);
			ans=min(ans, akt);
			int k=3;
			rep(p, m-3) {
				while(k<m-1) {
					int nakt=akt;
					nakt-=(j-i-1)-f(i+1, k, j-1, k);
					nakt+=f(i+1, k, j-1, k);
					nakt+=2-f(i, k, i, k)-f(j, k, j, k);
					nakt+=(j-i-1)-f(i+1, k+1, j-1, k+1);
					if(nakt>akt && k-p>=3) break;
					akt=nakt;
					++k;
				}
				ans=min(ans, akt);
				akt-=(j-i-1)-f(i+1, p, j-1, p);
				akt-=f(i+1, p+1, j-1, p+1);
				akt+=(j-i-1)-f(i+1, p+1, j-1, p+1);
				akt-=2-f(i, p+1, i, p+1)-f(j, p+1, j, p+1);
			}
		}
	}
	cout << ans << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}