//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 528;
bool a[N][N];
ll dph[N][N];
ll dpv[N][N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll n, m;
	cin >> n >> m;
	for(ll i =0;i<n;i++){
		for(ll j = 0;j<m;j++){
			char c;
			cin >> c;
			if(c^'#') a[i][j] = 1;
		}
	}
	for(ll i = 0;i<n;i++){
		for(ll j = 0;j<m;j++){
			dph[i][j] = (a[i][j] && a[i][j+1] ? 1 : 0);
			if(j) dph[i][j] += dph[i][j-1];
			if(i) dph[i][j] += dph[i-1][j];
			if(i && j) dph[i][j] -= dph[i-1][j-1];

			dpv[i][j] = (a[i][j] && a[i+1][j] ? 1 : 0);
			if(j) dpv[i][j] += dpv[i][j-1];
			if(i) dpv[i][j] += dpv[i-1][j];
			if(i && j) dpv[i][j] -= dpv[i-1][j-1];
		}
	}
	ll q, r1, c1, r2, c2;
	cin >> q;
	while(q--){
		cin >> r1 >> c1 >> r2 >> c2;
		--r1, r2--, c1--, --c2;
		ll v = 0;
		if(c1^c2){
			v+= dph[r2][c2-1]-(c1?dph[r2][c1-1]:0)-(r1?dph[r1-1][c2-1]:0)+(c1&&r1?dph[r1-1][c1-1]:0);
		}
		if(r1^r2){
			// v+= dpv[r2-1][c2]-(r1?dpv[r1-1][c2]:0)-(c2?dpv[r2-1][c2-1]:0) + (r1&&c2?dpv[r1-1][c2-1]:0);
			v+= dpv[r2-1][c2]-(r1?dpv[r1-1][c2]:0)-(c1?dpv[r2-1][c1-1]:0)+(r1&&c1?dpv[r1-1][c1-1]:0);
		}
		cout << v << '\n';
	}
}