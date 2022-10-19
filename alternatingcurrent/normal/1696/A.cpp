#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;

int T;
int n, z;
ll a[400400]; 
ll ans = 0;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		ans = 0;
		cin >> n >> z;
		rep(i, n){
			cin >> a[i];
			ans = max(ans, a[i] | z);
		}
		cout << ans << endl;
	}
	return 0;
}