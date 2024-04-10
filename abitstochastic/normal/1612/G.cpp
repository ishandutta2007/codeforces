#include<bits/stdc++.h>
using namespace std;

#define int long long
const int _ = 1e6 + 3 , P = 1e9 + 7;
int sum[2 * _ + 3] , N , fac[_];

signed main(){
	cin >> N; for(int i = 1 ; i <= N ; ++i){int C; cin >> C; ++sum[-C + 1 + _]; --sum[C + 1 + _];}
	fac[0] = 1; for(int i = 1 ; i <= N ; ++i) fac[i] = 1ll * fac[i - 1] * i % P;
	int ans = 0 , cnt = 1 , pos = 0;
	for(int i = 0 ; i <= 2 * _ ; ++i){
		sum[i + 2] += sum[i];
		cnt = 1ll * cnt * fac[sum[i]] % P; ans = (ans + 1ll * (i - _ + P) * ((pos + sum[i] + pos + 1) % P) % P * sum[i] % P * (P + 1) / 2) % P;
		pos += sum[i];
	}
	cout << ans << ' ' << cnt << endl;
	return 0;
}