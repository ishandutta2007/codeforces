#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll Mod = 998244353;

int n;
ll from[200200], to[200200];
bool on[200200];
ll val[200200];
ll sum[200200];

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n)
		cin >> from[i] >> to[i] >> on[i];
	ll nowsum = 0;
	rep(i, n){
		val[i] = from[i] - to[i];
		int pos = lower_bound(from, from + n, to[i]) - from;
		val[i] = (val[i] + nowsum) % Mod;
		if(pos)
			val[i] = (val[i] + Mod - sum[pos - 1]) % Mod;
		nowsum = (nowsum + val[i]) % Mod;
		sum[i] = nowsum;
	}
	ll ans = (from[n - 1] + 1) % Mod;
	rep(i, n){
		if(on[i])
			ans = (ans + val[i]) % Mod;
	}
	cout << ans << endl;
	return 0;
}