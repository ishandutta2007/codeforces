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

const ll M = 1e9+123;
const ll N = 5228;
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
	pll mr = {1, 0};
	for(ll i = 0;i<=n;i++){
		for(ll j = n;j>=i;j--){
			pull h1 = {(i?hsp[i-1].x:0)*ps[n].x+(hsp[n-1].x-hsp[j-1].x)*ps[n+i-j].x, (((i?hsp[i-1].y:0)*ps[n].y)%M+(((hsp[n-1].y+M-hsp[j-1].y)%M)*ps[n+i-j].y)%M)%M};
			pull h2 = {(j!=n?hss[j].x:0)*ps[n].x+(hss[0].x-(i!=n?hss[i].x:0))*ps[n+n-j-(n-i)].x, (((j!=n?hss[j].y:0)*ps[n].y)%M + (((hss[0].y+M-(i!=n?hss[i].y:0))%M)*ps[n+n-j-(n-i)].y)%M)%M};
			if(h1 == h2){
				if(i+n-j>mr.x+mr.y){
					mr = {i, n-j};
				}
			}
		}
	}
	for(ll i = 0;i<mr.x;i++) cout << s[i];
	for(ll i = 0;i<mr.y;i++) cout << s[n-mr.y+i];
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