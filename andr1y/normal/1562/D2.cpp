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
const ll N = 3e5+18;
ll ql[N], qa[N], pfx[N];
vector<ll> qx[N];
pll qb[N];	
map<ll, ll> lx;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		ll n, q;
		cin >> n >> q;
		lx.clear();
		for(ll i = 1;i<=n;i++) qx[i].clear();
		string s;
		cin >> s;
		for(ll i = 0, r;i<q;i++){
			cin >> ql[i] >> r;
			--ql[i];
			--r;
			qx[r].push_back(i);
		}
		pfx[0]=(s[0]=='+'?1:-1);
		for(ll i = 1;i<n;i++){
			pfx[i]=pfx[i-1]+(s[i]=='+'?1:-1)*((i&1) ? -1 : 1);
		}
		for(ll i = 0;i<n;i++){
			if(i) lx[pfx[i]+pfx[i-1]]=i;
			else lx[pfx[i]]=i;
			for(auto j : qx[i]){
				ll l = ql[j];
				if((i-l+1)%2==1){
					qa[j]=1;
					ll sn = pfx[i] + (l?pfx[l-1]:0);
					ll u = lx[sn];
					qb[j]={u, -1};
				}else{
					ll sn = pfx[i] - (l?pfx[l-1]:0);
					if(sn==0){
						qa[j]=0;
						qb[j]={-1, -1};
					}else{
						sn = pfx[i] + pfx[l];
						ll u = lx[sn];
						qa[j]=2;
						qb[j]={l, u};
					}
				}
				
			}
		}
		for(ll i = 0;i<q;i++){
			cout<<qa[i]<<'\n';
			if(qa[i]==1){
				cout<<qb[i].x+1<<'\n';
			}else if(qa[i]==2){
				cout<<qb[i].x+1<<' '<<qb[i].y+1<<'\n';
			}
		}
	}
}