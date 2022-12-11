#include <bits/stdc++.h>

using namespace std;

const int M = 1000000;
vector<long long> p;
long long fact[1000005], inv[1000005];
const long long MOD = 998244353;

long long mult(long long a, long long b){
	return a*b%MOD;
}

long long qikpow(long long a, long long b){
	if(!b){
		return 1;
	}
	long long ret = qikpow(a, b/2);
	ret = mult(ret, ret);
	if(b&1){
		ret = mult(ret, a);
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long N;
	cin >> N;
	for(int k = 2; k<=sqrt(N); k++){
		if(N%k == 0){
			p.push_back(k);
			while(N%k == 0){
				N /= k;
			}
		}
	}
	if(N > 1){
		p.push_back(N);
	}
	fact[0] = inv[0] = 1;
	for(int i = 1; i<=M; i++){
		fact[i] = mult(fact[i-1], i);
		inv[i] = qikpow(fact[i], MOD-2);
	}
	int Q;
	cin >> Q;
	while(Q--){
		long long a, b;
		cin >> a >> b;
		long long ans = 1;
		long long tot1 = 0, tot2 = 0;
		for(int i = 0; i<p.size(); i++){
			long long pr = p[i];
			int cnt1 = 0, cnt2 = 0;
			while(a%pr == 0){
				cnt1++;
				a /= pr;
			}
			while(b%pr == 0){
				cnt2++;
				b /= pr;
			}
			auto g = min(cnt1, cnt2);
			tot1 += cnt1-g;
			tot2 += cnt2-g;
			ans = mult(ans, inv[cnt1-g]);
			ans = mult(ans, inv[cnt2-g]);
		}	
		ans = mult(ans, fact[tot1]);
		ans = mult(ans, fact[tot2]);
		cout << ans << "\n";
	}
}