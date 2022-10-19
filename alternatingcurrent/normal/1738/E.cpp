#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const int Mod = 998244353;
int qpow(int b, int p){
	int ret = 1;
	while(p){
		if(p & 1) ret = 1ll * ret * b % Mod;
		p >>= 1;
		b = 1ll * b * b % Mod;
	}
	return ret;
}

int t;
int n;
int a[100100];
int f[100100];
int fact[100100], invfact[100100], pw2[100100];
int C(int N, int M){
	if(M > N) return 0;
	return 1ll * fact[N] * invfact[M] % Mod * invfact[N-M] % Mod;
}

int main(){
	fact[0] = 1;
	rep(i, 100000)
		fact[i+1] = 1ll * fact[i] * (i+1) % Mod;
	invfact[100000] = qpow(fact[100000], Mod-2);
	for(int i = 100000; i > 0; --i)
		invfact[i-1] = 1ll * invfact[i] * i % Mod;
	pw2[0] = 1;
	rep(i, 100000)
		pw2[i+1] = 2ll * pw2[i] % Mod;
	
	ios::sync_with_stdio(false);
	
	cin >> t;
	while(t--){
		cin >> n;
		rep(i, n)
			cin >> a[i];
		
		vector<int> ap;
		ap.push_back(-1);
		rep(i, n)
			if(a[i] != 0)
				ap.push_back(i);
		ap.push_back(n);
		
		auto calc = [&](int l, int r){
			if(l+1 == r){
				if(l == 0)
					return pw2[ap[r] - ap[l] - 2];
				else
					return (pw2[ap[r] - ap[l]] + Mod - 1) % Mod;
			} else {
				int cl = ap[l+1] - ap[l] - 1, cr = ap[r] - ap[r-1] - 1;
				int ret = 0;
				for(int k = 0; k <= cl && k <= cr; ++k)
					ret = (ret + 1ll * C(cl + (l!=0), k + (l!=0)) * C(cr + (l!=0), k + (l!=0))) % Mod;
				return ret;
			}
		};
		
		f[0] = calc(0, (int)ap.size()-1);
//		cout << "f[0] " << f[0] << endl;
		int sum = f[0];
		ll sl = 0, sr = 0;
		for(int i = 1, j = (int)ap.size()-1; i < j; ++i){
			sl += a[ap[i]];
			while(j > i && sr < sl)
				--j, sr += a[ap[j]];
			
//			cout << i << " " << j << " " << sl << " " << sr << endl;
			
			if(j <= i)
				break;
			
			if(sl == sr){
				f[i+1] = 1ll * sum * calc(i, j) % Mod;
				sum = (sum + f[i+1]) % Mod;
				
//				cout << i << " " << j << " " << sl << " " << sr << ": " << f[i+1] << " " << sum << endl;
			}
		}
		
		cout << sum << endl;
	}
	
	return 0;
}