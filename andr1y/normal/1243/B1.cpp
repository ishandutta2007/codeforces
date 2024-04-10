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
int main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		ll n;
		cin >> n;
		string s1, s2;
		cin >> s1 >> s2;
		vector<ll> uneq;
		for(ll i =0;i<n;i++) if(s1[i] != s2[i]) uneq.pb(i);
		if(uneq.size() != 2){
			cout << "No" << endl;
		}else{
			if(s1[uneq[0]] == s1[uneq[1]] && s2[uneq[0]] == s2[uneq[1]]) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
}