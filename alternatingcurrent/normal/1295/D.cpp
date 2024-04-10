#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int T;
long long a, b;
vector<long long> pr;

int main(){
	scanf("%d", &T);
	while(T--){
		pr.clear();
		scanf("%lld %lld", &a, &b);
		long long g = __gcd(a, b);
		a /= g, b /= g;
		long long orgb = b;
		for(long long i = 2; i * i <= orgb; i++){
			if(b%i == 0){
				pr.push_back(i);
				while(b%i == 0) b /= i;
			}
		}
		if(b > 1) pr.push_back(b);
		long long ans = orgb;
		for(int mask = 1; mask < (1 << (int)(pr.size())); mask++){
			long long now = 1LL;
			rep(i, pr.size()) if(mask & (1 << i)) now *= pr[i];
			long long del = (orgb+a-1)/now - (a-1)/now;
//			cout << now << " " << del << endl;
			if(__builtin_popcount(mask) % 2 == 1) ans -= del;
			else ans += del;
		}
		cout << ans << endl;
	}
	return 0;
}