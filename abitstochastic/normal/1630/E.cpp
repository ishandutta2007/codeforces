#include<bits/stdc++.h>
using namespace std;

const int P = 998244353; int N , pot[1000003] , ans[1000003] , ans2[1000003] , T , fac[1000003] , ifac[1000003];
int poww(long long a , int b){int tms = 1; while(b){if(b & 1) tms = tms * a % P; a = a * a % P; b >>= 1;} return tms;}

signed main(){
	ios::sync_with_stdio(0);
	fac[0] = 1; for(int i = 1 ; i <= 1e6 ; ++i) fac[i] = 1ll * fac[i - 1] * i % P;
	ifac[1000000] = poww(fac[1000000] , P - 2); for(int i = 1e6 - 1 ; ~i ; --i) ifac[i] = ifac[i + 1] * (i + 1ll) % P;
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <= N ; ++i) pot[i] = ans[i] = ans2[i] = 0;
		for(int i = 1 ; i <= N ; ++i){int x; cin >> x; ++pot[x];}
		int L = 0; vector < int > num; for(int i = 1 ; i <= N ; ++i) if(pot[i]) num.push_back(pot[i]);
		for(auto t : num) L = __gcd(L , t);
		if(num.size() == 1){cout << 1 << endl; continue;}
		int sum = 0 , cnt = 0;
		for(int i = L ; i ; --i)
			if(L % i == 0){
				vector < int > tmp = num; for(auto &t : tmp) t /= i;
				int mul = fac[N / i]; for(auto t : tmp) mul = 1ll * mul * ifac[t] % P;
				int tcnt = mul; for(int j = i ; j <= L ; j += i) tcnt = (tcnt - ans[j] + P) % P;
				ans[i] = tcnt; cnt = (cnt + 1ll * tcnt * poww(N / i , P - 2)) % P; int tmpsum = mul;
				for(auto t : tmp) if(t >= 2) tmpsum = (tmpsum - 1ll * mul * t % P * (t - 1) % P * poww(1ll * (N / i) * (N / i - 1) % P , P - 2) % P + P) % P;
				tmpsum = 1ll * tmpsum * N % P; for(int j = i ; j <= L ; j += i) tmpsum = (tmpsum - ans2[j] + P) % P;
				ans2[i] = tmpsum; sum = (sum + 1ll * tmpsum * poww(N / i , P - 2)) % P;
			}
		cout << 1ll * sum * poww(cnt , P - 2) % P << endl;
	}
	return 0;
}