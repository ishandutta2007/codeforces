#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n, x;
int a[200200];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n >> x;
		rep(i, n)
			cin >> a[i];
		int mn = 0x3f3f3f3f, mx = -1;
		int ans = 0;
		rep(i, n){
			int nmn = min(mn, a[i]), nmx = max(mx, a[i]);
			if(nmx - nmn > x + x)
				ans++, mn = mx = a[i];
			else
				mn = nmn, mx = nmx;
		}
		cout << ans << endl;
	}
	return 0;
}