#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

int t;
int n;
int a[200200];

int main(){
	ios::sync_with_stdio(false);
	
	cin >> t;
	while(t--){
		cin >> n;
		rep(i, n)
			cin >> a[i];
		
		int l = 0;
		ll ans = 0;
		for(int r = 0; r < n; ++r){
			l = max(l, r - a[r] + 1);
			ans += r-l+1;
		}
		
		cout << ans << endl;
	}
	
	return 0;
}