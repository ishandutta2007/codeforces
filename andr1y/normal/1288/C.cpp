#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#ifndef __LOCAL
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#else
#define FILES(namein, nameout) FAST;
#endif //__LOCAL
#define M 1000000007
#define N 1111
#define INF 101111111111111LL
using namespace std;
using python = void;

ll cs[N][N];

signed main(){
	FAST;
	ll n, m;
	cin >> n >> m;
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	cs[0][1] = 1;
	for(ll i = 1;i<=m+1;i++){
		for(ll j = 1;j<=n;j++) cs[i][j] = (cs[i-1][j] + cs[i][j-1])%M;
	}
	ll res = 0;
	for(ll i = 0;i<n;i++){
		for(ll j = i;j<n;j++){
			ll is = i+1, js = n-j;
			res = (res + ((cs[m][js]*cs[m][is])%M))%M;
		}
	}
	cout << res << endl;
}