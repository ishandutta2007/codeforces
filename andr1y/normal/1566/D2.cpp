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
ll ra[N];
yree cnt[N];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll qqq;cin>>qqq;while(qqq--){
		ll n, m;
		cin >> n >> m;
		for(ll i = 0;i<n;i++) cnt[i].clear();
		for(ll i = 0;i<n*m;i++){
			cin >> a[i].x;
			a[i].y=i;
		}
		sort(a, a+n*m);
		for(ll i = 0;i<n*m;){
			ll si = i;
			while(i<n*m&&a[i].x == a[si].x) i++;
			if(si/m == (i-1)/m){
				reverse(a+si, a+i);
			}else{
				ll mi = si;
				while(mi<i){
					if(mi%m==m-1 || mi==i-1){
						reverse(a+si, a+mi+1);
						si=mi+1;
					}
					mi++;
				}
			}
		}
		for(ll i = 0;i<n*m;i++) ra[a[i].y]=i;
		ll res=0;
		for(ll i = 0;i<n*m;i++){
			res+=cnt[ra[i]/m].order_of_key(ra[i]);
			cnt[ra[i]/m].insert(ra[i]);
		}
		cout<<res<<'\n';
	}
}