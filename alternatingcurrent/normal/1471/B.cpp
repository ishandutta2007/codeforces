#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int t;
int n;
ll x;
ll a[100100];
int cnt[100100];

int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n >> x;
		rep(i, n) cin >> a[i];
		ll ans = 0;
		rep(i, n){
			cnt[i] = 0;
			ll add = a[i];
			while(a[i] % x == 0) a[i] /= x, cnt[i]++;
			a[i] = add;
		}
		int mn = 0x3f3f3f3f;
		rep(i, n) mn = min(mn, cnt[i]);
		rep(i, n){
			if(cnt[i] == mn) mn--;
			ans += 1LL * a[i] * (mn + 2);
		}
		cout << ans << endl;
	}
	return 0;
}