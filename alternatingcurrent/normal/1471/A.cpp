#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int t;
int n; 
ll x;
int a[100100];

int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n >> x;
		rep(i, n) cin >> a[i];
		ll sum = 0, ans = 0;
		rep(i, n) sum += a[i], ans += (a[i] + x - 1) / x;
		sum = (sum + x - 1) / x;
		cout << sum << " " << ans << endl;
	}
	return 0;
}