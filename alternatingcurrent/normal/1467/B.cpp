#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int n;
int a[300300];
bool is_pnt(int i){
	if(i <= 0 || i >= n-1) return 0;
	if(a[i] > a[i-1] && a[i] > a[i+1]) return 1;
	if(a[i] < a[i-1] && a[i] < a[i+1]) return 1;
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		rep(i, n) cin >> a[i];
		int ans = 0, mn = 0;
		rep(i, n) ans += is_pnt(i);
		rep(i, n){
			int pai = a[i];
			int pre = is_pnt(i-1) + is_pnt(i) + is_pnt(i+1);
			if(i) a[i] = a[i-1], mn = min(mn, is_pnt(i+1) - pre);
			a[i] = pai;
			if(i < n-1) a[i] = a[i+1], mn = min(mn, is_pnt(i-1) - pre);
			a[i] = pai;
		}
		ans += mn;
		cout << ans << endl;
	}
	return 0;
}