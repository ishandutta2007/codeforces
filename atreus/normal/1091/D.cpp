#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,int> pii;

const int maxn = 1e6 + 10;
const int mod = 998244353;

ll fac[maxn], dp[maxn];

int main(){
	ios_base::sync_with_stdio(false);	
	ll n;
	cin >> n;
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = 1ll * fac[i - 1] * i % mod;
	for (int i = 2; i <= n; i++)
		dp[i] = 1ll * i * ((1ll * dp[i - 1] + fac[i - 1] - 1 + mod) % mod);
	cout << (dp[n] + fac[n]) % mod << endl;
}