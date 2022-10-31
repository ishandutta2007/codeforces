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
ll a[N], p[N];
int main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		ll n;
		cin >> n;
		for(ll i =0;i<n;i++){
			cin >> a[i];
			p[a[i]] = i;
		}
		ll l = p[1], r = p[1], empty = 0;
		string res = "1";
		for(ll i = 2;i<=n;i++){
			ll pos = p[i];
			if(pos < l){
				empty += l - pos - 1;
				l = pos;
			}else if(pos > r){
				empty += pos - r - 1;
				r = pos;
			}else{
				empty--;
			}
			if(empty == 0) res += "1";
			else res += "0";
		}
		cout << res << endl;
	}
}