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
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll N = 50005;
pair<array<ll, 3>, ll> s2[10][N];
bool bad[N][10];
ll fwt[N];

void fwset(ll p, ll d){
	++p;
	for(;p<N;p+=p&-p) fwt[p]=min(fwt[p], d);
}
ll fwmin(ll r, ll s=inf){
	r++;
	for(;r;r-=r&-r) s=min(s, fwt[r]);
	return s;
}
void fwunset(ll p){
	++p;
	for(;p<N;p+=p&-p) fwt[p]=inf;
}


signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	memset(fwt, 0x3f, sizeof fwt);
	ll qqq;cin>>qqq;while(qqq--){
		ll n;
		cin >> n;
		for(ll i =0;i<n;i++){
			ll r[5];
			cin >> r[0] >> r[1] >> r[2] >> r[3] >> r[4];
			for(ll mask=0, x2=0;mask<32;mask++){
				if(__builtin_popcount(mask)==3){
					s2[x2][i].y=i;
					for(ll j = 0, x=0;j<5;j++){
						if(mask&(1<<j)){
							s2[x2][i].x[x] = r[j];
							x++;
						}
					}
					bad[i][x2]=0;
					++x2;
				}
			}
		}
		for(ll i = 0;i<10;i++){
			sort(s2[i], s2[i]+n, [](pair<array<ll, 3>, ll> a, pair<array<ll, 3>, ll> b){
				return a.x[0]<b.x[0];
			});
			for(ll j = 0;j<n;j++){
				pll now = {s2[i][j].x[1], s2[i][j].x[2]};
				ll x = fwmin(now.x);
				if(x < now.y){
					bad[s2[i][j].y][i]=1;
				}
				fwset(now.x,now.y);
			}
			for(ll j = 0;j<n;j++) fwunset(s2[i][j].x[1]);
		}
		ll ans=-2;
		for(ll i = 0;i<n;i++){
			bool ok=1;
			for(ll j = 0;j<10;j++){
				ok = ok && (!bad[i][j]);
			}
			if(ok){ans=i;break;}
		}
		cout<<ans+1<<'\n';
	}
}