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
ll nl[N][26];
int main(){
	FAST;
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<ll> av;
	vector<ll> nav;
	for(ll i =0;i<k;i++){
		char c;
		cin >> c;
		av.pb(c-'a');
	}
	for(ll i =0;i<26;i++){
		bool ok = 1;
		for(auto j : av) if(i == j) ok = 0;
		if(ok) nav.pb(i);
	}
	for(ll i =0;i<26;i++){
		ll lst = n;
		for(ll j = n-1;j>=0;j--){
			if(s[j]-'a' == i) lst = j;
			nl[j][i] = lst;
		}
	}
	ll res = 0;
	for(ll i =0;i<n;i++){
		ll nc = n-1;
		for(auto j : nav) nc = min(nc, nl[i][j]-1);
		res += max(nc-i+1, 0ll);
	}
	cout << res << endl;
}