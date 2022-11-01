#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
long long read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	long long num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
vector<long long> prime;
int inv[100];
int fact[100], invfact[100];
int main() {
	long long d = read();
	for (int i = 2; 1ll * i * i <= d; i++)
		if (d % i == 0) {
			prime.push_back(i);
			while (d % i == 0) d /= i;
		}
	if (d > 1) prime.push_back(d);
	inv[1] = 1;
	for (int i = 2; i < 100; i++) inv[i] = 1ll*(mod-mod/i)*inv[mod%i]%mod;
	fact[0] = invfact[0] = 1;
	for (int i = 1; i < 100; i++) fact[i] = 1ll*fact[i-1]*i%mod, invfact[i] = 1ll*invfact[i-1]*inv[i]%mod;
	int q = read();
	for (int i = 1; i <= q; i++) {
		long long a, b;
		a = read(), b = read();
		int a1 = 0, a2 = 0, ans = 1;
		for (long long i : prime) {
			int c1 = 0, c2 = 0;
			while (a % i == 0) ++c1, a /= i;
			while (b % i == 0) ++c2, b /= i;
			if (c1 == c2) continue;
			if (c1 > c2) a1 += c1 - c2;
			else a2 += c2 - c1;
			ans = 1ll*ans*invfact[abs(c1-c2)]%mod;
		}
		cout << 1ll*ans*fact[a1]%mod*fact[a2]%mod << endl;
	}
}