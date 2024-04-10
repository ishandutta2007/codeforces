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
//pll qb[N];	
//map<ll, ll> lx, ly;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		ll n, q;
		cin >> n >> q;
		//lx.clear();
		//ly.clear();
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
			/*lx[pfx[i]+pfx[i-1]]=i-1;
			if(i>1){
				ly[pfx[i]-pfx[i-2]]=i;
			}*/
		}
		for(ll i = 0;i<n;i++){
			for(auto j : qx[i]){
				ll l = ql[j];
				if(l==i){
					qa[j]=1;
					//qb[j]={l, -1};
				}else if((i-l+1)%2==1){
					qa[j]=1;
					/*ll sn = pfx[i] + (l?pfx[l-1]:0);
					ll u = lx[sn];
					assert(u>=l);
					qb[j]={u, -1};*/
				}else{
					ll sn = pfx[i] - (l?pfx[l-1]:0);
					if(sn==0){
						qa[j]=0;
						//qb[j]={0, 0};
					}else{
						/*ll u = ly[-sn];
						qa[j]=2;
						assert(u-2>=l);
						assert(u-1<=i);
						qb[j]={u-2, u-1};*/
						qa[j]=2;
					}
				}
				
			}
		}
		for(ll i = 0;i<q;i++) cout<<qa[i]<<'\n';
	}
}