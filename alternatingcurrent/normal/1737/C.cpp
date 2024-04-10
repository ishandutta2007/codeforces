#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	
	int T;
	cin >> T;
	while(T--){
		static pair<int, int> a[3];
		int n;
		cin >> n;
		rep(i, 3)
			cin >> a[i].first >> a[i].second;
		
		int tx, ty;
		cin >> tx >> ty;
		
		sort(a, a + 3);
		bool ans = 0;
		if(a[0] == make_pair(1, 1) && a[1] == make_pair(1, 2) && a[2] == make_pair(2, 1)){
			ans = (tx == 1 || ty == 1);
		} else if(a[0] == make_pair(1, n-1) && a[1] == make_pair(1, n) && a[2] == make_pair(2, n)){
			ans = (tx == 1 || ty == n);
		} else if(a[0] == make_pair(n-1, 1) && a[1] == make_pair(n, 1) && a[2] == make_pair(n, 2)){
			ans = (tx == n || ty == 1);
		} else if(a[0] == make_pair(n-1, n) && a[1] == make_pair(n, n-1) && a[2] == make_pair(n, n)){
			ans = (tx == n || ty == n);
		} else {
			int sx = a[0].first ^ a[1].first ^ a[2].first, sy = a[0].second ^ a[1].second ^ a[2].second;
			ans = ((tx & 1) != (sx & 1)) || ((ty & 1) != (sy & 1));
		}
		
		cout << (ans ? "YES\n" : "NO\n");
	}
	
	return 0;
}