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
const ll N = 2e5+18;
pll a[N];
ll oa[N], ob[N];
ll dp[2][N], _tcb[N];
void fwinc(ll p, ll d){
	for(;p<N;p+=p&-p) _tcb[p]+=d;
}
ll fwget(ll r, ll s = 0){
	if(r<1) return 0;
	for(;r;r-=r&-r) s+=_tcb[r];
	return s;
}

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	/* 
	diff by a or b = diff by only a + diff by b but a not diff - >
	a clear
	b count only from one group or only from (2+1)
	*/
	ll qqq;cin>>qqq;while(qqq--){
		ll n;
		cin >> n;
		for(ll i = 0;i<n;i++) cin >> a[i].x >> a[i].y;
		sort(a, a+n);
		ll c=0, t=-1;
		for(ll i = 0;i<n;i++){
			if(a[i].x!=t){
				c++;
				oa[c-1]=0;
				t=a[i].x;
			}
			oa[c-1]++;
		}
		ll pf = oa[0];
		for(ll i =1;i<c;i++){
			dp[0][i] = oa[i]*pf;
			pf+=oa[i];
		}
		pf=dp[0][1];
		ll res=0;
		for(ll i = 2;i<c;i++){
			dp[1][i] = oa[i]*pf;
			res+=dp[1][i];
			pf+=dp[0][i];
		}
		for(ll i = 0;i<n;i++) fwinc(a[i].y, 1);
		for(ll g=0, s=0;g<c;g++){
			ll z = oa[g], c2=0, t2=-1;
			for(ll i = 0;i<z;i++) fwinc(a[i+s].y, -1);
			for(ll i = 0;i<z;i++){
				if(a[i+s].y != t2){
					t2=a[i+s].y;
					c2++;
					ob[c2-1]=0;
				}
				ob[c2-1]++;
			}

			pf = ob[0];
			for(ll i =1;i<c2;i++){
				dp[0][i] = ob[i]*pf;
				pf+=ob[i];
			}
			pf=dp[0][1];
			for(ll i = 2;i<c2;i++){
				dp[1][i] = ob[i]*pf;
				res+=dp[1][i];
				pf+=dp[0][i];
			}

			if(c2>1){
				ll ts=ob[0];
				for(ll i = 1;i<c2;i++){
					ll v = a[s+ts].y;
					res+=dp[0][i]*(fwget(n)-fwget(v));
					ts+=ob[i];
				}

				ll la = 0, fc=ob[0];
				pf=0;
				for(ll i = s;i<s+z;i++){
					if(a[i].y != la){
						pf+=fwget(a[i].y-1)-fwget(la-1);
						la=a[i].y;
					}
					dp[0][i]=pf;
				}
				ll que=0;
				la = a[s].y, pf=0;
				for(ll i = s;i<s+fc;i++) que+=dp[0][i];
				for(ll i = s+fc;i<s+z;i++){
					if(a[i].y != la){
						pf+=que;
						que=0;
						la=a[i].y;
					}
					dp[1][i] = pf;
					res+=dp[1][i];
					que+=dp[0][i];
				}

				la=a[s].y, pf=ob[0];
				for(ll i = 1;i<c2;i++){
					ll v = a[s+pf].y;
					dp[0][i] = (fwget(v-1)-fwget(la))*pf;
					dp[1][i] = (fwget(v)-fwget(la))*pf;
					pf+=ob[i];
					la=v;
				}
				pf=0;
				for(ll i = 1;i<c2;i++){
					res+=(pf+dp[0][i])*ob[i];
					pf+=dp[1][i];
				}
			}


			for(ll i = 0;i<z;i++) fwinc(a[i+s].y, 1);
			s+=z;
		}
		for(ll i = 0;i<n;i++) fwinc(a[i].y, -1);
		cout<<res<<'\n';
	}
}