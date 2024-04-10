#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
int n;
ll S[5050];
ll done[5050];
ll ans = 0;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n) cin >> S[i];
		memset(done, 0, sizeof(done));
		ans = 0;
		rep(i, n){
			ans += max(S[i] - done[i] - 1LL, 0LL);
			for(int j = min(i + S[i], (ll)n); j >= i + 2; j--){
				done[j]++;
			}
			for(int j = done[i] - S[i] + 1; j > 0; j--){
				done[i + 1]++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}