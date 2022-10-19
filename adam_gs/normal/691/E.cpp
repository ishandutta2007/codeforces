#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=107;
const ll MOD=1e9+7;
ll T[LIM], M[LIM][LIM], ans[LIM][LIM], tmp[LIM][LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, k;
	cin >> n >> k; --k;
	rep(i, n) cin >> T[i];
	rep(i, n) rep(j, n) if(__builtin_popcountll(T[i]^T[j])%3==0) M[i][j]=1;
	rep(i, n) ans[i][i]=1;
	while(k) {
		if(k&1) {
			rep(i, n) rep(j, n) {
				tmp[i][j]=0;
				rep(l, n) tmp[i][j]=(tmp[i][j]+ans[i][l]*M[l][j])%MOD;
			}
			rep(i, n) rep(j, n) ans[i][j]=tmp[i][j];
		}
		rep(i, n) rep(j, n) {
			tmp[i][j]=0;
			rep(l, n) tmp[i][j]=(tmp[i][j]+M[i][l]*M[l][j])%MOD;
		}
		rep(i, n) rep(j, n) M[i][j]=tmp[i][j];
		k/=2;
	}
	ll sum=0;
	rep(i, n) rep(j, n) sum=(sum+ans[i][j])%MOD;
	cout << sum << '\n';
}