#include <bits/stdc++.h>

using namespace std;

const int M = 1e6;
unordered_map<int, int> mp;
int sieve[1000005];
long long fact[2000005];
const long long MOD = 1e9+7;

long long mult(long long a, long long b){
	return (a*b)%MOD;
}

long long qikpow(long long b, long long e){
	if(!e){
		return 1;
	}
	long long ret = qikpow(b, e/2);
	ret = mult(ret, ret);
	if(e&1){
		ret = mult(ret, b);
	}
	return ret;
}

long long choose(long long n, long long r){
	//cout << fact[n] << " " << qikpow(mult(fact[n], fact[n-r]), MOD-2) << "\n";
	return mult(fact[n], qikpow(mult(fact[r], fact[n-r]), MOD-2));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int Q;
	cin >> Q;
	sieve[0] = sieve[1] = 1;
	for(int i = 2; i<=M; i++){
		if(!sieve[i]){
			for(int j = i; j<=M; j+=i){
				sieve[j] = i;
			}
		}
	}
	fact[0] = 1;
	for(int i = 1; i<=2*M; i++){
		fact[i] = mult(fact[i-1], i);
	}
	while(Q--){
		int x, y;
		cin >> x >> y;
		unordered_map<int, int> mp;
		while(x != 1){
			mp[sieve[x]]++;
			x /= sieve[x];
		}
		long long ans = qikpow(2, y-1);
		//cout << ans << "\n";
		for(auto p : mp){
			//cout << choose(y+p.second-1, p.second) << "\n";
			//cout << y + p.second - 1 << " " << p.second << "\n";
			//cout << choose(y + p.second - 1, p.second) << "\n";
			ans = mult(ans, choose(y + p.second - 1, p.second));
		}
		cout << ans << "\n";
	}
}