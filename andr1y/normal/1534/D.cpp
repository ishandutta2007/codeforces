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
const ll inf = 0x3fff3fff3fff3ff;
const ll N = 2002;
bool d[N][N];
ll cx[N];

signed main(){
	ll n;cin>>n;
	cout<<"? 1"<<endl;
	vector<ll> even, odd;
	for(ll i = 1;i<=n;i++){
		cin >> cx[i];
		if(cx[i]==0) continue;
		if(cx[i]==1) d[1][i]=d[i][1]=1;
		if(cx[i]&1) odd.push_back(i);
		else even.push_back(i);
	}
	vector<ll> todo;
	if(even.size()<=odd.size()){
		for(auto &i : even) todo.push_back(i);
	}else for(auto &i : odd) todo.push_back(i);
	for(auto &i : todo){
		cout<<"? "<<i<<endl;
		for(ll e, j = 1;j<=n;j++){
			cin >> e;
			if(e==1) d[i][j]=d[j][i]=1;
		}
	}
	cout<<"!"<<endl;
	for(ll i = 1;i<=n;i++){
		for(ll j = i+1;j<=n;j++){
			if(d[i][j]) cout<<i<<' '<<j<<endl;
		}
	}
}