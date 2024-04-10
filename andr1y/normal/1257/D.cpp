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
#define N 200005
#define INF 101111111111111
using namespace std;
ll t[4*N];
ll a[N], s[N], v[N];
void build(ll v, ll tl, ll tr){
	if(tl == tr) t[v] = a[tl];
	else{
		ll m = (tl+tr)>>1;
		build(2*v, tl, m);
		build(2*v+1, m+1, tr);
		t[v] = max(t[v*2], t[v*2+1]);
	}
}
ll get_max(ll v, ll tl, ll tr, ll l, ll r){
	if(l <= tl && tr <= r) return t[v];
	ll maxx = -INF, tm = (tl+tr)>>1;
	if(!(l > tm || r < tl)) maxx = max(maxx, get_max(v*2, tl, tm, l, r));
	if(!(l > tr || r < tm+1)) maxx = max(maxx, get_max(v*2+1, tm+1, tr, l, r));
	return maxx;
}

ll n, m;
ll binsearch(ll off, ll mon){
	ll l = off+1, r = min(off+v[mon], n-1);
	while(r-l>1){
		ll m = (l+r)>>1;
		if(get_max(1, 1, n, off+2, m+1) <= s[mon] && m - off <= v[mon]){
			l = m;
		}else{
			r = m;
		}
	}
	ll res = -INF;
	for(ll i  =l;i<=r;i++) if(get_max(1, 1, n, off+2, i+1) <= s[mon] && i - off <= v[mon]) res = i;
	return res;
}

ll bst[N];
int main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		cin >> n;
		for(ll i = 1;i<=n;i++){
			cin >> a[i];
			bst[i] = 0;
			//pr[i] = a[i];
			//if(i != 0) pr[i] += pr[i-1];
		}
		cin >> m;
		for(ll i =0;i<m;i++){
			cin >> s[i] >> v[i];
			bst[v[i]] = max(bst[v[i]], s[i]);
		}
		ll mxn = 0;
		for(ll i = n;i>0;i--){
			if(bst[i] != 0){
				mxn = max(mxn, bst[i]);
			}
			bst[i] = mxn;
		}
		//build(1, 1, n);
		ll now = 0, r = 0;
		bool bb = false;
		while(now < n){
			ll maxnow = 0, nowp = 1;
			if(a[now+1] > bst[1]){
				cout << -1 << endl;
				bb = true;
				break;
			}
			while(now+nowp-1 <= n && (maxnow = max(maxnow, a[now+nowp])) <= bst[nowp]) nowp++;
			nowp--;
			if(nowp <= 0){
				cout << -1 << endl;
				bb = 1;
				break;
			}
			now += nowp;
			r++;
		}
		if(!bb)cout << r << endl;
	}
}