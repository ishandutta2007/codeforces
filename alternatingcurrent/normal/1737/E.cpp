#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const int Mod = 1e9 + 7;
const int inv2 = (Mod+1) / 2;

int t;
int n;
int pre[1000100], nxt[1000100], pw2[1000100], pwinv2[1000100];

int main(){
	pw2[0] = pwinv2[0] = 1;
	for(int i = 1; i <= 1000000; ++i)
		pw2[i] = 2ll * pw2[i-1] % Mod, pwinv2[i] = 1ll * inv2 * pwinv2[i-1] % Mod;
	ios::sync_with_stdio(false);
	
	cin >> t;
	while(t--){
		cin >> n;
		
		int nval = 1;
		rep(i, n){
			if(!(i&1)) nval = 1ll * nval * inv2 % Mod;
			if(i == n-1) nval = 2ll * nval % Mod;
			pre[i] = nval;
		}
		
		nxt[n-1] = 1;
		int sum = 2, r = n-1;
		for(int l = n-2; l >= 0; --l){
			sum = 1ll * sum * inv2 % Mod;
			while(r > l + l) sum = (sum + Mod - 1ll * nxt[r] * pwinv2[r-l-(r==n-1)] % Mod) % Mod, --r;
			nxt[l] = sum;
			sum = (sum + nxt[l]) % Mod;
		}
		
		rep(i, n)
			cout << 1ll * pre[i] * nxt[i] % Mod << "\n";
	}
	
	return 0;
}