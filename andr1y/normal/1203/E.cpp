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
#define N 150002
#define INF 101111111111111
using namespace std;
ll dp[N];
ll a[N], tr[N];
void fw_set(ll pos, ll val){
	for(ll i = pos;i<N;i = (i | (i+1))) tr[i]= max(tr[i], val);
}
ll fw_get(ll r){
	ll s = 0;
	for(;r>=0;r = (r & (r+1)) - 1) s = max(tr[r], s);
	return s;
}
main(){
    FAST;
    ll n;
    cin >> n;
    for(ll i =0;i<n;i++) cin >> a[i];
    sort(a, a+n);
	for(ll i = 0;i<=150001;i++) dp[i] = 0;
	dp[0] = 0;
	for(ll i = 0;i<n;i++){
		dp[a[i]+1] =  max(dp[a[i]+1], fw_get(a[i])+1);
		dp[a[i]] = max(dp[a[i]], fw_get(a[i]-1)+1);
		if(a[i]>1) dp[a[i]-1] = max(dp[a[i]-1], fw_get(a[i]-2)+1);
		fw_set(a[i]+1, dp[a[i]+1]);
		fw_set(a[i], dp[a[i]]);
		fw_set(a[i]-1, dp[a[i]-1]);
	}
	cout << fw_get(N-1);
}