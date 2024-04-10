#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const int Mod = 998244353;
void uadd(int &a, int b){
	a += b-Mod;
	a += (a>>31) & Mod;
}
int add(int a, int b){
	return (a+b >= Mod) ? a+b-Mod : a+b;
}
void umul(int &a, int b){
	a = (int)(1ll * a * b % Mod);
}
int mul(int a, int b){
	return (int)(1ll * a * b % Mod);
}
int qpow(int b, int p){
	int ret = 1;
	while(p){
		if(p & 1) umul(ret, b);
		umul(b, b), p >>= 1;
	}
	return ret;
}
int inv(int b){
	return qpow(b, Mod-2);
}

int fact[2020], invfact[2020];
int C(int n, int m){
	return mul(fact[n], mul(invfact[m], invfact[n-m]));
}

int sum[555][1555], sumsame[4][555][1555];

signed n, k;

signed main(){
	ios::sync_with_stdio(false);
	
	cin >> n >> k;
	
	fact[0] = 1;
	for(signed i = 1; i <= 4*n; ++i)
		fact[i] = mul(fact[i-1], i);
	invfact[4*n] = inv(fact[4*n]);
	for(signed i = 4*n; i > 0; --i)
		invfact[i-1] = mul(invfact[i], i);
	
	static int tmp[555];
	rep(i, n+1)
		tmp[i] = mul(invfact[i], invfact[n-i]);
	for(signed a = 0; a <= n; ++a) for(signed b = 0; b <= n; ++b) for(signed c = 0; c <= n; ++c){
		signed mn = min({a, b, c});
		int val = mul(tmp[a], mul(tmp[b], tmp[c]));
		uadd(sum[mn][a+b+c], val);
		signed cnt = (a == mn) + (b == mn) + (c == mn);
		uadd(sumsame[cnt][mn][a+b+c], val);
	}
	
	for(signed i = n; i > 0; --i) rep(j, 3*n+1)
		uadd(sum[i-1][j], sum[i][j]);
	
	int ans = 0;
	int inv2 = inv(2), inv3 = inv(3), inv4 = inv(4); 
	for(signed i = 1; i <= 4*n; ++i){
		signed s = min(k, i-1);
		for(signed x = 0; x <= min(s, k) && x <= n; ++x){
			int val = sum[x+1][s-x];
			uadd(val, mul(inv2, sumsame[1][x][s-x]));
			uadd(val, mul(inv3, sumsame[2][x][s-x]));
			uadd(val, mul(inv4, sumsame[3][x][s-x]));
//			cout << i << " " << x << ": " << val << " " << mul(C(s, x), mul(C(4*n-s-1, n-x-1), mul(fact[s-x], mul(fact[3*n-s+x], val)))) << endl;
			uadd(ans, mul(C(s, x), mul(C(4*n-s-1, n-x-1), mul(fact[s-x], mul(fact[3*n-s+x], val)))));
		}
	}
	
//	cout << ans << endl;
	cout << mul(mul(ans, 4), inv(mul(fact[4*n], mul(invfact[n], mul(invfact[n], mul(invfact[n], invfact[n])))))) << endl;
	
	return 0;
}