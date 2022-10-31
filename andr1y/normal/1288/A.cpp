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

signed main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		ll n, d;
		cin >> n >> d;
		ll res = d;
		for(ll i = 1;i*i<=d;i++){
			res = min(res, i+(d/(i+1))+(d%(i+1) != 0 ? 1 : 0));
		}
		if(res <=n) cout << "YES\n";
		else cout << "NO\n";
	}
}