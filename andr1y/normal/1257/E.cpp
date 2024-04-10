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
ll a[N];
ll cl[3], cr[3];
int main(){
	FAST;
	ll k1, k2, k3, n;
	cin >> k1 >> k2 >> k3;
	n = k1+k2+k3;
	for(ll x,i =0;i<k1;i++){cin>>x;a[x-1]=0;cr[0]++;};
	for(ll x,i =0;i<k2;i++){cin>>x;a[x-1]=1;cr[1]++;};
	for(ll x,i =0;i<k3;i++){cin>>x;a[x-1]=2;cr[2]++;};
	ll ans = cr[0]+cr[1];
	ll maxlft = 0;
	for(ll i = 0;i<n;i++){
		cl[a[i]]++, cr[a[i]]--;
		maxlft = max(maxlft, cl[0] - cl[1]);
		ll cans = cr[0]+cr[1]+cl[2]+cl[0]-maxlft;
		ans = min(ans, cans);
	}
	cout << ans;
}