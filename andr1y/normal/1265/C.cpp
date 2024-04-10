#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 400045
#define INF 101111111111111
using namespace std;
ll a[N];
ll groups[N], gc = 0;
ll groups_pref[N];
/*ll check2(ll g, ll s, ll mr){
	ll l = s+1, r = mr;
	while(r-l>1){
		ll m = (l+r)>>1;
		if(groups_pref[m] - groups_pref[s] > groups_pref[g]){
			l = m;
		}else r = m;
	}
	if(l>r) return -1;
	ll rs = -1;
	for(ll m = r;m>=l;m--) if(groups_pref[g] < groups_pref[m] - groups_pref[s]){
		rs = m;
		break;
	}
	return rs;
}*/
bool count(ll m, ll g, ll mr){
	ll c2 = groups_pref[mr]-groups_pref[m];
	if(groups_pref[g] < groups_pref[m]-groups_pref[g] && c2 > groups_pref[g]){
		return true;
	}else return false;
}
ll check(ll g, ll mr){
	ll l = g+1, r = mr-1;
	while(r-l>1){
		ll m = (l+r)>>1;
		if(groups_pref[m] - groups_pref[g] > groups_pref[g]) r = m;
		else l = m;
	}
	if(l > r) return -1;
	for(ll m = l;m<=r;m++){
		if(groups_pref[m] - groups_pref[g] > groups_pref[g]) return m;
	}
	return -1;
}
int main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		ll n;
		cin >> n;
		for(ll i =0;i<n;i++) cin >> a[i];
		ll last = -1, lz = -1;
		gc = 0;
		for(ll i = 0;i<n;i++){
			if(i == 0){
				last = a[i];
				lz = 1;
			}else{
				if(a[i] == last) lz++;
				else{
					groups[gc++] = lz;
					last = a[i];
					lz = 1;
				}
			}
		}
		groups[gc++] = lz;
		groups_pref[0] = groups[0];
		for(ll i  =1;i<gc;i++) groups_pref[i] = groups_pref[i-1] + groups[i];
		ll mxl = n/2;
		ll l = 0, r = gc-1;
		while(r-l>1){
			ll m  =(l+r)>>1;
			if(groups_pref[m] <= mxl){
				l = m;
			}else{
				r = m;
			}
		}
		ll res = -1;
		for(ll m = r;m >= l;m--) if(groups_pref[m] <= mxl && res == -1) res = m;
		if(res == -1){
			cout << "0 0 0" << endl;
		}else{
			l = 0, r = res;
			while(r-l>1){
				ll m = (l+r)>>1;
				ll ch = check(m, res);
				if(ch == -1 || (groups_pref[res] - groups_pref[ch] <= groups_pref[m])){
					r = m;
				}else l =m;
			}
			pair<ll, pll> res2 = {-1, {-1, -1}};
			for(ll m = r;m>=l;m--){
				ll ch = check(m, res);
				if(!(ch == -1 || (groups_pref[res] - groups_pref[ch] <= groups_pref[m]))){
					res2 = {m, {ch, res}};
					break;
				}
			}
			if(res2.x == -1) cout << "0 0 0" << endl;
			else cout << groups_pref[res2.x] << " " << groups_pref[res2.y.x]-groups_pref[res2.x] << " " << groups_pref[res2.y.y]-groups_pref[res2.y.x] << endl;
		}
	}
}