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
	string s;
	ll k;
	cin >> s >> k;
	if(s.length()%k != 0) cout << "NO\n";
	else{
		ll n = s.length()/k;
		bool ok = 1;
		for(ll i = 0;i<k;i++){
			ll st = i*n, ed = (i+1)*n-1;
			for(ll j = 0;j<n/2;j++) ok &= s[st+j] == s[ed-j];

		}
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
}