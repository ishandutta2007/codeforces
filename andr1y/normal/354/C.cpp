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
#define N 300015
#define INF 101111111111111
using namespace std;
ll n, k, a[N];
ll mina = INF, maxa = 0;
ll cnt[N*10];
ll pre[N*10];
bool check(ll d){
	ll mx = maxa/d;
	ll rx =0;
	for(ll i = 1;i<=mx;i++) rx+=pre[i*d+k]-pre[i*d-1];
	return rx == n;
}
int main(){
	FAST;
	cin >> n >> k;
	for(ll i = 0;i<n;i++){
		cin >> a[i];
		mina = min(mina, a[i]);
		maxa = max(maxa, a[i]);
		cnt[a[i]]++;
	}
	pre[0] = cnt[0];
	for(ll i = 1;i<N*10;i++) pre[i] = cnt[i] + pre[i-1];
	if(mina <= k+1){
		cout << mina << endl;
	}else{
		for(ll i = mina;i>k;i--){
			if(check(i)){
				cout << i << endl;
				exit(0);
			}
		}
		cout << 1 << endl;
	}
}