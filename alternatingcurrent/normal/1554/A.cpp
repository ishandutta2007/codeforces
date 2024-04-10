#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
int n;
ll a[100100];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		ll ans = 0;
		rep(i, n){
			cin >> a[i];
		}
		rep(i, n - 1)
			ans = max(ans, a[i] * a[i + 1]);
		cout << ans << endl;
	}
	return 0;
}