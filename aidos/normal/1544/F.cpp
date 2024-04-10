//Solution by Tima
#include <bits/stdc++.h>
 
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
#define y1 sda
#define all(x) x.begin(), x.end()
 
using namespace std;    
const int N = int(3e5) + 12, mod = 31607; 
 
int a[30][30];
int n, b[30];
int c[(1<<23)], x[(1<<23)];
int mul[1<<23];
int mul2[1<<23];
int fi[1<<23];
 
ll modpow(ll a,ll b){
	ll res = 1;
	while(b){
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
 
void add(int &a,int b){
    a += b;
    if(a >= mod) a -= mod;
}
 
void solve(){
    cin >> n;
    for(int i = 0; i < (1<<(n+2)); i++) c[i] = 1;
    
	for(int mask = 1; mask < (1<<n); mask++) {
	    int cc = 0;
	    while(!((1<<cc) & mask)) cc++;
	    fi[mask] = cc;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			//a[i][j] = 5000;
			a[i][j] = a[i][j] * modpow(10000, mod - 2) % mod;
		}
		memset(x, 0, sizeof(x));
		mul[0] = mul2[0] = 1;
		for(int mask = 1; mask < (1<<n); mask++) {
		    int cc = fi[mask];
		    mul[mask] = mul[mask^(1<<cc)] * a[i][cc] % mod;
		    mul2[mask] = mul2[mask^(1<<cc)] * (mod+1-a[i][cc]) % mod;
		}
		for(int mask = 0; mask < (1<<n); mask++){
			int res = mul[mask] * mul2[mask^((1<<n)-1)];
			
			if(mask == (1<<n) - 1){
				b[i] = res;
			}
			else{
				int nm = mask;
				if(mask & (1<<i)) nm |= (1 <<n);
				if(mask & (1<<(n - i - 1))) nm |= (1<<(n + 1));
				x[nm] = (x[nm] + res) % mod;
			}
		}
		for(int i = 0; i < (n + 2); i++){
			for(int mask = 0; mask < (1<<(n+2)); mask++){
				if(mask & (1<<i)) add(x[mask ^ (1<<i)] , x[mask]);
			}
		}
		for(int mask = 0; mask < (1<<(n+2)); mask++){
			c[mask] = (c[mask] * x[mask]) % mod;
		}
	}
	ll ans = 0;
	for(int mask = 1; mask < (1<<(n + 2)); mask++){
		if(__builtin_popcount(mask) & 1){
			ans = (ans + c[mask]) % mod;
		}
		else{
			ans = (ans - c[mask] + mod) % mod; 
		}
	}
	for(int mask = 1; mask < (1<<n); mask++){
		int res = 1;
		for(int i = 0; i < n; i++){
			if(mask & (1<<i)) res = res * b[i] % mod;
			else res = res * (mod + 1 - b[i]) % mod;
		}
		ans = (ans + res) % mod;
	}                               
	cout << ans;
	
}
 
int main () {
	int T = 1;
	//scanf("%d", &T);
 
	while(T--){
		solve();
	}
 
return 0;
}