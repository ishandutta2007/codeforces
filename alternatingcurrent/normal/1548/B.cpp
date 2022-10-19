#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
ll qabs(ll a){
	return (a < 0) ? -a : a;
}

int T;
const int BS = 447;
int n;
ll a[200555];
ll diff[200555];
ll blockgcd[460];

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n){
			cin >> a[i];
		}
		rep(i, n - 1)
			diff[i] = qabs(a[i] - a[i + 1]);
		n--;
		rep(i, (n - 1) / BS + 1)
			blockgcd[i] = diff[i * BS];
		rep(i, n)
			blockgcd[i / BS] = __gcd(blockgcd[i / BS], diff[i]);
		int ans = 0;
		for(int l = 0; l < n; l++){
			int r = l;
			ll nowgcd = diff[l];
			ll pregcd = diff[l];
			for(r = l; r < n && r < ((l / BS) + 1) * BS; r++){
				pregcd = nowgcd;
				nowgcd = __gcd(diff[r], nowgcd);
				if(nowgcd == 1){
					nowgcd = pregcd;
					break;
				}
			}
			if(r < ((l / BS) + 1) * BS){
				ans = max(ans, r - l);
				continue;
			}
			for(; r < n; r += BS){
				pregcd = nowgcd;
				nowgcd = __gcd(blockgcd[r / BS], nowgcd);
				if(nowgcd == 1){
					nowgcd = pregcd;
					break;
				}
			}
			for(; r < n; r++){
				pregcd = nowgcd;
				nowgcd = __gcd(diff[r], nowgcd);
				if(nowgcd == 1){
					nowgcd = pregcd;
					break;
				}
			}
			if(r >= n)
				r = n;
			ans = max(ans, r - l);
		}
		cout << ans + 1 << endl;
	}
	return 0;
}