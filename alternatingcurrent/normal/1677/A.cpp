#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
int n;
int p[5050];
int presum[5050][5050], sufsum[5050][5050];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			cin >> p[i], p[i]--;
		rep(i, n)
			rep(j, n)
				presum[i][j] = sufsum[i][j] = (j == p[i]);
		rep(i, n)
			rep(j, n)
				presum[i + 1][j] += presum[i][j];
		rep(i, n)
			rep(j, n)
				presum[i][j + 1] += presum[i][j];
		for(int i = n - 1; i > 0; i--)
			rep(j, n)
				sufsum[i - 1][j] += sufsum[i][j];
		rep(i, n)
			rep(j, n)
				sufsum[i][j + 1] += sufsum[i][j];
		ll ans = 0;
		for(int i = 1; i < n; i++)
			for(int j = i + 1; j < n - 1; j++){
				ans += 1ll * presum[i - 1][p[j]] * sufsum[j + 1][p[i]];
			}
		cout << ans << endl;
	}
	return 0;
}