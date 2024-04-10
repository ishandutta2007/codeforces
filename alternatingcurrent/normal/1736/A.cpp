#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int t;
int n;
int a[111], b[111];

int main(){
	ios::sync_with_stdio(false);
	
	cin >> t;
	while(t--){
		cin >> n;
		rep(i, n)
			cin >> a[i];
		rep(i, n)
			cin >> b[i];
		
		int s = 0;
		rep(i, n)
			s += a[i] - b[i];
		int ans = 1 + abs(s);
		
		s = 0;
		rep(i, n)
			s += (a[i] != b[i]);
		ans = min(ans, s);
		
		cout << ans << endl;
	}
	
	return 0;
}