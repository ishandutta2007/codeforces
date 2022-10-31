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
		ll n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		ll found_zeros = 0;
		ll last_zero_pos = INF;
		for(ll i = 0;i<s.length();i++){
			if(s[i] == '0'){
				ll need = i-found_zeros;
				if(need > k){
					last_zero_pos = i;
					break;
				}
				k -= need;
				found_zeros++;
			}
		}
		if(last_zero_pos != INF){
			for(ll j = 0;j<found_zeros;j++) cout << 0;
			for(ll j = found_zeros;j<=last_zero_pos-k-1;j++) cout << 1;
			cout << 0;
			for(ll j = last_zero_pos-k+1;j<=last_zero_pos;j++)cout << 1;
			for(ll j = last_zero_pos+1;j<n;j++) cout << s[j];
		}else{
			for(ll j = 0;j<found_zeros;j++) cout << 0;
			for(ll j = found_zeros;j<n;j++) cout << 1;
		}
		cout << endl;
	}
}