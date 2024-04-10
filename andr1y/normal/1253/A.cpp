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
#define N 100005
#define INF 101111111111111
using namespace std;
ll n, a[N], b[N], c[N];
int main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		cin >> n;
		for(ll i =0;i<n;i++) cin >> a[i];
		for(ll i =0;i<n;i++) {cin >> b[i];c[i] = b[i]-a[i];}
		ll bc = 0, bs = -1, bn = 0;
		bool f = true;
		for(ll i =0;i<n;i++){
			if(c[i] < 0) f = 0;
			if(c[i]!=0){
				if(bn == 0){
					bs = i;
				}
				if(c[bs] == c[i]) bn++;
				else f = 0;
			}else{
				if(bn != 0) bc++;
				bn = 0, bs = -1;
			}
		}
		if(!f){
			cout << "NO" << endl;
			continue;
		}
		if(bn!=0) bc++;
		if(bc > 1){
			cout << "NO" << endl;
		}
		else cout << "YES" << endl;
	}
}