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
string ts(__int128 a){
	string res;
	while(a){
		res.push_back('0'+a%10);
		a/=10;
	}
	reverse(res.begin(), res.end());
	return res;
}
ll t[N][10], mv[N], sz=1;
bool term[N];
void add(string s){
	ll v = 0;
	for(auto i : s){
		if(!t[v][i-'0']) t[v][i-'0']=(sz++);
		v = t[v][i-'0'];
	}
	term[v]=1;
}
void dfs(ll v){
	ll md = (term[v] ? 0 : inf);
	for(ll i = 0;i<10;i++){
		if(t[v][i]) dfs(t[v][i]), md=min(md, mv[t[v][i]]+1);
	}
	mv[v]=md;
}

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	__int128 a=1;
	for(ll i =0;i<70;i++){
		add(ts(a));
		a<<=1;
	}
	dfs(0);
	ll qqq;cin>>qqq;while(qqq--){
		string xs;
		cin >> xs;
		ll n = xs.length();
		ll res=12;
		for(ll i = 0;i<(1<<n);i++){
			ll v = 0, ok=1;
			for(ll j = 0;j<n&&ok;j++){
				if(i&(1<<j)){
					if(!t[v][xs[j]-'0'])ok=0;
					else v=t[v][xs[j]-'0'];
				}
			}
			if(ok) res=min(res, n-__builtin_popcount(i)+mv[v]);
		}
		cout<<res<<'\n';
	}
}