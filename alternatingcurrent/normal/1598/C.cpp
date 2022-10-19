#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
int n;
ll a[200200];
ll k;
map<ll, int> cnt;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			cin >> a[i];
		ll sum = 0;
		rep(i, n)
			sum += a[i];
		if(sum * 2LL % n != 0){
			cout << "0" << endl;
		} else {
			k = sum * 2ll / n;
			cnt.clear();
			ll ans = 0;
			rep(i, n){
				ans += cnt[k - a[i]];
				cnt[a[i]]++;
			}
			cout << ans << endl;
		}
	} 
	return 0;
}