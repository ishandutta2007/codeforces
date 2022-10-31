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
pll a[N];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n;
	cin >> n;
	for(ll i = 0;i<n;i++){
		cin >> a[i].x >> a[i].y;
	}
	sort(a, a+n, [](pll a, pll b){
		return abs(a.x)==abs(b.x) ? abs(a.y)<abs(b.y) : abs(a.x)<abs(b.x);
	});
	vector<pair<ll, pll>> ops;
	for(ll i = 0;i<n;i++){
		if(a[i].x < 0){
			ops.push_back({1, {-a[i].x, 0}}); //L
		}else if(a[i].x > 0){
			ops.push_back({1, {a[i].x, 1}}); //R
		}
		if(a[i].y < 0){
			ops.push_back({1, {-a[i].y, 2}}); //D
		}else if(a[i].y > 0){
			ops.push_back({1, {a[i].y, 3}}); //U
		}
		ops.push_back({2, {0, 0}});
		if(a[i].x < 0){
			ops.push_back({1, {-a[i].x, 1}}); //R
		}else if(a[i].x > 0){
			ops.push_back({1, {a[i].x, 0}}); //L
		}
		if(a[i].y < 0){
			ops.push_back({1, {-a[i].y, 3}}); //U
		}else if(a[i].y > 0){
			ops.push_back({1, {a[i].y, 2}}); //D
		}
		ops.push_back({3, {0, 0}});
	}
	cout<<ops.size()<<'\n';
	for(auto i : ops){
		if(i.x==1){
			cout<<1<<' '<<i.y.x<<' ';
			if(i.y.y==0) cout<<'L';
			if(i.y.y==1) cout<<'R';
			if(i.y.y==2) cout<<'D';
			if(i.y.y==3) cout<<'U';
			cout<<'\n';
		}else cout<<i.x<<'\n';
	}
}