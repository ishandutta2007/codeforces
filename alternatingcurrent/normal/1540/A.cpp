#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
int n;
ll d[100100];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			cin >> d[i];
		sort(d, d + n);
		ll ans = d[n - 1];
		rep(i, n - 1){
			ll diff = d[i + 1] - d[i];
			ans -= diff * (i + 1) * (n - 1 - i);
		}
		cout << ans << endl;
	}
	return 0;
}