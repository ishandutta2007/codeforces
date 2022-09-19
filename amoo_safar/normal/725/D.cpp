#include <bits/stdc++.h>

#define pb push_back

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) 9223372036854775;
const ld EPS = (ld) 1e-8;

ll t[MAXN], w[MAXN], ind[MAXN];

bool cmp(ll i, ll j){
	if(t[i] == t[j]) return i < j;
	return t[i] > t[j];
}
multiset<ll> st;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> t[i] >> w[i];
		ind[i] = i;
	}
	sort(ind + 1, ind + n + 1, cmp);
	ll ii = -1;
	for(int i = 1; i <= n; i++) if(ind[i] == 1) ii = i;
	debug(ii);
	ll ans = ii;
	ll rank = ii;
	for(int i = 1; i < ii; i++){
		ll j = ind[i];
		st.insert(w[j] - t[j] + 1);
	}
	ll b = t[1];
	for(int k = 0; k < n; k++){
		if(ans == 1) break;
		ll mn = *st.begin();
		st.erase(st.begin());
		b -= mn;
		debug(b);
		if(b < 0) break;
		rank --;
		while(ii + 1 <= n){
			if(b < t[ind[ii + 1]]){
				swap(ind[ii], ind[ii + 1]);
				rank ++;
				st.insert(w[ind[ii]] - t[ind[ii]] + 1);
				ii ++;
			} else {
				break;
			}
		}
		ans = min(ans, rank);
	}
	cout << ans << '\n';
	return 0;
}