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
ll last[N];
int main(){
	FAST;
	ll q;
	cin >> q;
	while(q--){
		ll n;
		cin >> n;
		for(ll i  =0;i<=n;i++) last[i] = -1;
		ll res = INF;
		for(ll a, i =0;i<n;i++){
			cin >> a;
			if(last[a] != -1){
				res = min(res, i-last[a]+1);
			}
			last[a] = i;
		}
		if(res == INF) cout << -1 << endl;
		else cout << res << endl;
	}
}