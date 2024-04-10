#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n;
int a[2020];

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			cin >> a[i];
		int mx = 0, mn = 0x3f3f3f3f;
		rep(i, n)
			mx = max(mx, a[i]), mn = min(mn, a[i]);
		int ans = max(mx - a[0], a[n - 1] - mn);
		rep(i, n)
			ans = max(ans, a[i] - a[(i + 1) % n]);
		cout << ans << endl;
	}
	return 0;
}