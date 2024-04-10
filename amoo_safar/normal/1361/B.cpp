#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll mul(ll a, ll b){
	return (a * b) % Mod;
}
ll bin_pow(ll b, ll p){
	ll res = 1;
	for(ll j = 1, pw = b; j <= p; j <<= 1, pw = mul(pw, pw)){
		if(p & j)
			res = mul(res, pw);
	}
	return res;
}

ll a[N];
vector<pll> V;

void Main(){
	ll n, p;
	cin >> n >> p;
	for(int i = 0; i < n; i++){
		scanf("%lld", a + i);
	}
	if(p == 1){
		printf("%lld\n", (n & 1));
		return ;
	}
	sort(a, a + n);
	ll pw = a[n - 1];
	ll C = 1;
	ll ans = bin_pow(p, a[n - 1]);
	for(int i = n - 2; i >= 0; i--){
		//cerr << pw << ' ' << C << '\n';
		if(C)
			while(pw > a[i] && C < 1000000){
				C *= p;
				pw --;
			}
		pw = a[i];
		if(C){
			C--;
			ans -= bin_pow(p, a[i]);
		} else {
			ans += bin_pow(p, a[i]);
			C ++;
		}
	}
	printf("%lld\n", (((ans%Mod) + Mod) % Mod));
}

int main(){
	ll tc;
	scanf("%lld", &tc);
	while( tc -- ) Main();
	return 0;
}