#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
ll n;
ll fact[22];
ll sumfact[1111111];

int main(){
	fact[0] = 1;
	for(int i = 1; i <= 20; i++)
		fact[i] = fact[i - 1] * i;
	rep(mask, 1 << 17)
		rep(i, 17)
			if(mask & (1 << i))
				sumfact[mask] += fact[i + 3];
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		int ans = 1000;
		rep(mask, 1 << 17){
			if(sumfact[mask] > n)
				continue;
			ans = min(ans, __builtin_popcountll(n - sumfact[mask]) + __builtin_popcount(mask));
		}
		cout << ans << endl;
	}
	return 0;
}