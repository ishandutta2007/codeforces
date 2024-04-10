#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'

#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

#ifndef __LOCAL
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout); FAST;
#else
#define FILES(namein, nameout) FAST;
#endif //__LOCAL

using namespace std;
using namespace __gnu_pbds;
using python = void;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned short uss;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef tree<ll, null_type> ordered_set;

const ll M = 1e9+7;
const ll N = 1e6+228;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
const ll P = 29;
pull ps[2*N];
pull hsp[N];
pull hss[N];
python solve(){
	FAST;
	string s;
	ll n;
	cin >> s;
	n = s.length();
	hsp[0].x = hsp[0].y = (s[0]-'a'+1);
	for(ll i = 1;i<n;i++){
		hsp[i].x = hsp[i-1].x + (s[i]-'a'+1)*ps[i].x;
		hsp[i].y = hsp[i-1].y +((s[i]-'a'+1)*ps[i].y)%M;
		hsp[i].y %= M;
	}
	hss[n].x = hss[n].y = 0;
	for(ll i = n-1;i>=0;i--){
		hss[i].x = hss[i+1].x + (s[i]-'a'+1)*ps[n-i-1].x;
		hss[i].y = hss[i+1].y +((s[i]-'a'+1)*ps[n-i-1].y)%M;
		hss[i].y %= M;
	}
	// pll mr = {1, 0};
	// for(ll i = 0;i<=n;i++){
	// 	for(ll j = n;j>=i;j--){
	// 		pull h1 = {(i?hsp[i-1].x:0)*ps[n].x+(hsp[n-1].x-hsp[j-1].x)*ps[n+i-j].x, (((i?hsp[i-1].y:0)*ps[n].y)%M+(((hsp[n-1].y+M-hsp[j-1].y)%M)*ps[n+i-j].y)%M)%M};
	// 		pull h2 = {(j!=n?hss[j].x:0)*ps[n].x+(hss[0].x-(i!=n?hss[i].x:0))*ps[n+n-j-(n-i)].x, (((j!=n?hss[j].y:0)*ps[n].y)%M + (((hss[0].y+M-(i!=n?hss[i].y:0))%M)*ps[n+n-j-(n-i)].y)%M)%M};
	// 		if(h1 == h2){
	// 			if(i+n-j>mr.x+mr.y){
	// 				mr = {i, n-j};
	// 			}
	// 		}
	// 	}
	// }
	// for(ll i = 0;i<mr.x;i++) cout << s[i];
	// for(ll i = 0;i<mr.y;i++) cout << s[n-mr.y+i];
	ll l = 1, r = n/2;
	while(r-l>1){
		ll m = (l+r)>>1;
		if(hsp[m-1] == hss[n-m]) l = m;
		else r = m;
	}
	ll lcp = 0;
	ll mp = 0, ms   =0;
	for(ll m = l;m<=r;m++) if(hsp[m-1]==hss[n-m]) lcp = m;
	for(ll i = 0;i<n-lcp-lcp;i++){
		ll p = lcp+i;
		if((i+1)&1){
			ll ln = (i+1)/2;
			pull h1 = {hsp[lcp+ln].x-(lcp?hsp[lcp-1].x:0), (hsp[lcp+ln].y+M-(lcp?hsp[lcp-1].y:0))%M};
			pull h2 = {hss[lcp+ln].x-hss[lcp+ln+ln+1].x, (hss[lcp+ln].y+M-hss[lcp+ln+ln+1].y)%M};
			h1.x *= ps[n-lcp].x;
			h1.y *= ps[n-lcp].y;
			h1.y %= M;

			h2.x *= ps[1+(lcp+ln+ln)].x;
			h2.y *= ps[1+(lcp+ln+ln)].y;
			h2.y %= M;

			if(h1 == h2){
				mp = i+1;
			}
		}else{
			ll ln = (i+1)/2;
			pull h1 = {hsp[lcp+ln-1].x-(lcp?hsp[lcp-1].x:0), (hsp[lcp+ln-1].y+M-(lcp?hsp[lcp-1].y:0))%M};
			pull h2 = {hss[lcp+ln].x-hss[lcp+ln+ln].x, (hss[lcp+ln].y+M-hss[lcp+ln+ln].y)%M};
			h1.x *= ps[n-lcp].x;
			h1.y *= ps[n-lcp].y;
			h1.y %= M;

			h2.x *= ps[1+(lcp+ln+ln-1)].x;
			h2.y *= ps[1+(lcp+ln+ln-1)].y;
			h2.y %= M;

			if(h1 == h2){
				mp = i+1;
			}
		}
	}
	for(ll i = 0;i<n-lcp-lcp;i++){
		ll p = n-lcp-i-1;
		if((i+1)&1){
			ll ln = (i+1)/2;
			pull h1 = {hsp[p+ln].x-(p?hsp[p-1].x:0), (hsp[p+ln].y+M-(p?hsp[p-1].y:0))%M};
			pull h2 = {hss[p+ln].x-hss[p+i+1].x, (hss[p+ln].y+M-hss[p+i+1].y)%M};
			h1.x *= ps[n-p].x;
			h1.y *= ps[n-p].y;
			h1.y %= M;

			h2.x *= ps[1+p+i].x;
			h2.y *= ps[1+p+i].y;
			h2.y %= M;

			if(h1 == h2){
				ms = i+1;
			}
		}else{
			ll ln = (i+1)/2;
			pull h1 = {hsp[p+ln-1].x-(p?hsp[p-1].x:0), (hsp[p+ln-1].y+M-(p?hsp[p-1].y:0))%M};
			pull h2 = {hss[p+ln].x-hss[p+i+1].x, (hss[p+ln].y+M-hss[p+i+1].y)%M};
			h1.x *= ps[n-p].x;
			h1.y *= ps[n-p].y;
			h1.y %= M;

			h2.x *= ps[1+p+i].x;
			h2.y *= ps[1+p+i].y;
			h2.y %= M;

			if(h1 == h2){
				ms = i+1;
			}
		}
	}
	if(mp>=ms){
		for(ll i = 0;i<lcp;i++) cout<<s[i];
		for(ll i = 0;i<mp;i++) cout<<s[lcp+i];
		for(ll i = 0;i<lcp;i++) cout<<s[n-lcp+i];
	}else{
		for(ll i = 0;i<lcp;i++) cout<<s[i];
		for(ll i = 0;i<ms;i++) cout<<s[n-lcp-ms+i];
		for(ll i = 0;i<lcp;i++) cout<<s[n-lcp+i];
	}
	cout << '\n';
}

signed main(){
	FAST;
	ps[0].x = ps[0].y = 1;
	for(ll i = 1;i<2*N;i++){
		ps[i].x = ps[i-1].x*P;
		ps[i].y = ps[i-1].y*P;
		ps[i].y %= M;
	}
	ll q = 1;
	cin >> q;
	while(q--){
		solve();
	}
}