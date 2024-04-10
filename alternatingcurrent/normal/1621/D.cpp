#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
int n;
ll c[555][555];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n + n)
			rep(j, n + n)
				cin >> c[i][j];
		ll ans = 0;
		for(int i = n; i < n + n; i++)
			for(int j = n; j < n + n; j++)
				ans += c[i][j];
		ans += min({c[0][n], c[0][n + n - 1], c[n - 1][n], c[n - 1][n + n - 1], c[n][0], c[n][n - 1], c[n + n - 1][0], c[n + n - 1][n - 1]});
		cout << ans << endl;
	}
	return 0;
}