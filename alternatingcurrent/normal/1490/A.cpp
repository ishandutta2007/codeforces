#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n;
int a[55];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n) cin >> a[i];
		int ans = 0;
		rep(i, n-1){
			int j = max(a[i], a[i + 1]), t = min(a[i], a[i + 1]);
			int cnt = 0;
			while(j > t){
				cnt++;
				t *= 2;
			}
			ans += max((cnt - 1), 0);
		}
		cout << ans << endl;
	}
	return 0;
}