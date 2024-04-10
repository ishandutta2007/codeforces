#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll n, k;

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> n >> k;
		ll nowval = 1;
		ll ans = 0;
		while(nowval < n && nowval <= k)
			nowval = nowval * 2LL, ans++;
		if(nowval < n){
			ll res = n - nowval;
			ans += (res + k - 1) / k;
		}
		cout << ans << endl;
	}
	return 0;
}