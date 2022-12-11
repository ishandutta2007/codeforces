#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
using namespace std;    
const int N = int(8e5) + 1, mod = int(1e6)  + 3;

ll modpow(ll a,ll b){
	ll res = 1;
	while(b){
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

ll f[N+10], d[N + 10];

ll C(int n,int k){
	ll res = f[n] * d[k] % mod;
	return (res * d[n - k]) % mod;
}

int main () {
	int n,c;
	f[0] = d[0] = 1;
	cin >> n >> c;
	for(int i = 1;i <= n + c; i++){
		f[i] = f[i - 1] * i % mod;
		d[i] = modpow(f[i],mod-2);
	}
	ll ans = 0;
	for(int i = 1;i <= n; i++){
		ans = (ans + C(i + c - 1, c - 1)) % mod;
	}
	cout << ans;

return 0;
}