#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n, q, k;
int a[100100];

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> q >> k;
	rep(i, n) cin >> a[i];
	while(q--){
		int l, r;
		cin >> l >> r;
		l--, r--;
		int ans = (a[l] - 1) + (k - a[r]);
		ans += (a[r] - a[l] + 1 - (r - l + 1)) * 2;
		cout << ans << endl;
	}
	return 0;
}