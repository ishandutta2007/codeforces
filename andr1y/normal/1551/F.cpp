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
const ll N = 101;
const ll M = 1e9+7;
ll mcnt[N][N];
vector<ll> d[N];
void dfs(ll &v, ll &cont, ll h, ll p){
	mcnt[cont][h]++;
	for(auto i : d[v]){
		if(i^p) dfs(i, cont, h+1, v);
	}
}
ll dp[N][N];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		memset(mcnt, 0, sizeof mcnt);
		for(ll i = 1;i<N;i++) d[i].clear();
		ll n, k;
		cin >> n >> k;
		for(ll a, b, i = 1;i<n;i++){
			cin >> a >> b;
			d[a].push_back(b);
			d[b].push_back(a);
		}
		if(k==2){
			ll r = (n*(n-1));
			r>>=1;
			r%=M;
			cout<<r<<'\n';
			continue;
		}
		ll res=0;
		for(ll i = 1;i<=n;i++){
			ll cnt=0;
			ll adt=d[i].size();
			memset(mcnt, 0, sizeof (mcnt[0])*adt);
			for(auto j : d[i]){
				dfs(j, cnt, 1, i);
				cnt++;
			}
			for(ll hei=1;hei<n;hei++){
				dp[0][0]=1;
				dp[0][1]=mcnt[0][hei];
				for(ll j = 1;j<adt;j++){
					for(ll tk=0;tk<=k&&tk<=j+1;tk++){
						dp[j][tk]=(dp[j-1][tk] + (tk?dp[j-1][tk-1]*mcnt[j][hei] : 0))%M;
					}
				}
				res=(res+dp[adt-1][k])%M;
			}
		}
		cout<<res<<'\n';
	}
}