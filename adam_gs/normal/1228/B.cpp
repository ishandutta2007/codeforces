#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll MOD=1e9+7;
const int LIM=1e3+7;
int zero[LIM][LIM], jeden[LIM][LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, n) {
		int a;
		cin >> a;
		rep(j, a) jeden[i][j]=1;
		if(a<m) zero[i][a]=1;
	}
	rep(i, m) {
		int a;
		cin >> a;
		rep(j, a) jeden[j][i]=1;
		if(a<n) zero[a][i]=1;
	}
	ll ans=1;
	rep(i, n) rep(j, m) {
		if(jeden[i][j] && zero[i][j]) ans=0;
		else if(!jeden[i][j] && !zero[i][j]) ans=(ans*2)%MOD;
	}
	cout << ans << '\n';
}