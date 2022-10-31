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
#define N 200000
#define INF 101111111111111
using namespace std;
string gen(ll n, ll k){
	string s = "";
	for(ll i = 0;i<k-1;i++) s+="()";
	for(ll i =0;i<(n-2*k+2)/2;i++) s+="(";
	for(ll i =0;i<(n-2*k+2)/2;i++) s+=")";
		return s;
}
int main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		ll n, k;
		cin >> n >> k;
		string e, s;
		getline(cin, e);
		getline(cin, s);
		string generated = gen(n, k);
		vector<pll> sw;
		for(ll i =0;i<n;i++){
			if(s[i] != generated[i]){
				ll px = i+1;
				while(generated[i] != s[px]) px++;
				reverse(s.begin()+i, s.begin()+px+1);
				sw.pb({i, px});
			}
		}
		cout << sw.size() << endl;
		for(auto i : sw) cout << i.x+1 << " " << i.y+1 << endl;
	}
}