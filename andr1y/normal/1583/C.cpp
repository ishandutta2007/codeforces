//ulala
//code by 255
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ld inf = 0x3fff3fff3fff3fff;
const ll N = 1e6+18;
vector<vector<char>> a;
bool bad[N];
ll pfb[N];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n, m;
	cin >> n >> m;
	a.resize(n);
	for(auto &i : a) i.resize(m);
	for(ll i = 0;i<n;i++){
		for(ll j = 0;j<m;j++){
			cin >> a[i][j];
			if(i&&j+1<m&&a[i-1][j+1]=='X'&&a[i][j]=='X') bad[j]=1;
		}
	}
	pfb[0]=0;
	for(ll i = 0;i<m;i++){
		pfb[i+1]=pfb[i]+(bad[i]?1:0);
	}
	ll q;
	cin >> q;
	while(q--){
		ll l, r;
		cin >> l >> r;
		if(pfb[r-1]==pfb[l-1]) cout<<"yes\n";
		else cout<<"no\n";
	}
}