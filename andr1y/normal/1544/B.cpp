//ulala
//code by 255
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ll inf = 0x3fff3fff3fff3fff;
const ll N = 1e5+18;
char a[22][22], b[22][22];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		ll n, m;
		cin >> n >> m;
		memset(a, '0', sizeof a);
		for(ll i = 0, j=1;i<m;i++, j^=1){
			if(j) a[0][i]='1';
			else a[0][i]='0';
		}
		if(n>2){
			for(ll i = 0, j=1;i<m;i++, j^=1){
				if(j) a[n-1][i]='1';
				else a[n-1][i]='0';
			}
		}
		for(ll i = 2, j=1;i+2<n;i++, j^=1){
			if(j) a[i][0]=a[i][m-1]='1';
			else a[i][0]=a[i][m-1]='0';
		}
		for(ll i = 0;i<n;i++){
			for(ll j = 0;j<m;j++) cout<<a[i][j];
			cout<<'\n';
		}
	}
}