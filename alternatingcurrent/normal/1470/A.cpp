#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int t;
int n, m;
ll a[300300], b[300300];

int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n >> m;
		rep(i, n) cin >> a[i];
		rep(i, m) cin >> b[i];
		sort(a, a + n);
		reverse(a, a + n);
		rep(i, n) a[i]--;
		ll ans = 0;
		int i = 0;
		for(i = 0; i < m && i < n; i++){
			if(i >= a[i]) break;
			ans += b[i];
		}
		for(; i < n; i++) ans += b[a[i]];
		cout << ans << endl;
	}
	return 0;
}