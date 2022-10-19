#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int t;
int calc(int x, int pos){
//	cout << x << " " << pos << ": "<< (x >> (pos + 1)) << " " << (x & ((1 << pos) - 1)) << endl;
	if(x & (1 << pos))
		return ((x >> (pos + 1)) << pos) + (x & ((1 << pos) - 1)) + 1;
	else {
		if(((x >> (pos + 1)) - 1) < 0)
			return 0;
		return (((x >> (pos + 1)) - 1) << pos) + ((1 << pos) - 1) + 1;
	}
}

int l, r;

int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> l >> r;
		int ans = 0;
		for(int pos = 0; pos < 20; pos++){
			ans = max(ans, calc(r, pos) - calc(l - 1, pos));
//			cout << pos << ": "<< calc(r, pos) << "-" << calc(l - 1, pos) << " to " << ans << endl;
		}
//		cout << ans << endl;
		cout << r - l + 1 - ans << endl;
	} 
	return 0;
}