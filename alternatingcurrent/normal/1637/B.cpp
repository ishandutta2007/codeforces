#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
int n;
int a[10010];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			cin >> a[i];
		long long ans = 0;
		rep(i, n)
			ans += 1ll * ((a[i] == 0) ? 2 : 1) * (i + 1) * (n - i);
		cout << ans << endl;
	}
	return 0;
}