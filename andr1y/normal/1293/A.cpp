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
#ifndef __LOCAL
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#else
#define FILES(namein, nameout) FAST;
#endif //__LOCAL
#define M 1000000007
#define N 200200
#define INF 101111111111111LL
using namespace std;
using python = void;
ll a[N];
signed main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		ll n, s, k;
		cin >> n >> s >> k;
		bool cs = false;
		map<ll, bool> vl;
		for(ll i =0;i<k;i++) {cin >> a[i];vl[a[i]] = 1;};
		ll r1 = 0, r2 = 0;
		bool f1 = 0, f2 = 0;
		while(s-r1 > 0){
			if(vl[s-r1]) r1++;
			else{
				f1 = 1;
				break;
			}
		}
		while(s+r2 <= n){
			if(vl[s+r2]) r2++;
			else{
				f2 = 1;
				break;
			}
		}
		ll r = 0;
		if(f1 && f2) r = min(r1, r2);
		else if(f1) r = r1;
		else if(f2) r = r2;
		else r = INF;
		cout << r << '\n';
	}
}