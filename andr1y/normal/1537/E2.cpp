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
const ll N = 5e5+18;
typedef unsigned long long ull;
typedef pair<unsigned long long, unsigned long long> pull;
const ull P = 29;
const ull M = 1014881489;
const ull PHI = 9223372036854775808ULL;
pull p[N];
pull hs[N];
pull norm_hs(ll rp, ll s){
	pull px = p[s];
	pull ex = hs[rp];
	ex.x*=px.x;
	ex.y=(ex.y*px.y)%M;
	return ex;
}
vector<pull> cache[N];
pull period_hs(ll pos, ll per){
	pull H = norm_hs(per-1, 0);
	ll xn = pos/per, xz=pos%per;
	pull SG = (xn?cache[per][xn-1]:make_pair(0ULL, 0ULL));
	pull PF = {SG.x*H.x, (SG.y*H.y)%M};
	pull SF = norm_hs(xz, xn*per);
	pull SS = {PF.x+SF.x, (PF.y+SF.y)%M};
	return SS;
}


signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	p[0]={1, 1};
	for(ll i = 1;i<N;i++){
		p[i].x=p[i-1].x*P;
		p[i].y=p[i-1].y*P;
		p[i].y%=M;
	}
	for(ll i = 1;i<N;i++){
		cache[i].push_back({1, 1});
		cache[i].reserve(N/i);
		for(ll j = i;j<N;j+=i){
			pull e = cache[i].back();
			e.x+=p[j].x;
			e.y=(e.y+p[j].y)%M;
			cache[i].push_back(e);
		}
	}
	ll n, k;
	string s;
	cin >> n >> k >> s;
	hs[0]={s[0]-'a'+1, s[0]-'a'+1};
	for(ll i = 1;i<n;i++){
		hs[i].x=(hs[i-1].x + (s[i]-'a'+1)*p[i].x);
		hs[i].y=(hs[i-1].y + (s[i]-'a'+1)*p[i].y)%M;
	}
	ll mp=n;
	for(ll i = n-1;i>0;i--){
		ll mr = k+1;
		ll l = -1, r = mr;
		while(r-l>1){
			ll m = (l+r)>>1;
			pull v1 = period_hs(m, mp);
			pull v2 = period_hs(m, i);
			if(v1==v2) l=m;
			else r=m;
		}
		if(r==mr) continue;
		else{
			char v1 = s[r%mp];
			char v2 = s[r%i];
			if(v1>v2) mp=i;
		}
	}
	for(ll i = 0;i<k;i++) cout<<s[i%mp];
}