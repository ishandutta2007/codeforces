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

unordered_map<ll, ll> cnt;
ll n, k;
ll hsss(string& s){
	ll hv = 0;
	ll kf = 1;
	for(ll v, j = k-1;j>=0;j--){
		if(s[j] == 'S') v = 0;
		if(s[j] == 'E') v = 1;
		if(s[j] == 'T') v = 2;
		hv += kf*v;
		kf *= 3;
	}
	return hv;
}
string ors[N];
signed main(){
	FAST;
	cin >> n >> k;
	for(ll i = 0;i<n;i++){
		string s;
		cin >> s;
		ll hs = hsss(s);
		cnt[hs]++;
		ors[i] = s;
	}
	ll res =0;
	for(ll i = 0;i<n;i++){
		for(ll j = 0;j<n;j++){
			if(i == j) continue;
			string src = "";
			bool aeq = 1;
			for(ll z = 0;z<k;z++){
				if(ors[i][z] == ors[j][z]) src += ors[i][z];
				else{
					aeq = 0;
					if((ors[i][z] == 'E' && ors[j][z] == 'T') || (ors[i][z] == 'T' && ors[j][z] == 'E')) src += "S"; 
					if((ors[i][z] == 'S' && ors[j][z] == 'T') || (ors[i][z] == 'T' && ors[j][z] == 'S')) src += "E"; 
					if((ors[i][z] == 'S' && ors[j][z] == 'E') || (ors[i][z] == 'E' && ors[j][z] == 'S')) src += "T"; 
				}
			}
			ll hv = hsss(src);
			res += cnt[hv]-(aeq ? 2 : 0);
		}
	}
	cout << res/6 << endl;
}