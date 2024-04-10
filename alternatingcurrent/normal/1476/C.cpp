#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
ll qabs(ll a){
	return (a < 0) ? -a : a;
}

int T;
int n;
ll c[100100];
ll a[100100], b[100100];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n) cin >> c[i];
		rep(i, n) cin >> a[i];
		rep(i, n) cin >> b[i];
		ll sum = 0;
		ll ans = 0;
		for(int i = 1; i < n; i++){
			ll len = c[i] - 1 + 2 - qabs(a[i] - b[i]);
			ll len2 = len + qabs(a[i] - b[i]) * 2LL;
			if(a[i] != b[i]) sum += len;
			else sum = len;
			if(len2 > sum) sum = len2;
			if(sum > ans) ans = sum;
		}
		cout << ans << endl;
	}
	return 0;
}