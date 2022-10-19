#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 1e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 9;

int q , n , k , cnt[MAXN];
ll fact[MAXN] , inv[MAXN];
vector<int> vec;
string s;

ll poww(ll x , ll y){
	ll ans = 1;
	for( ; y ; y >>= 1 , x = x * x % MOD)	if(y & 1)	ans = ans * x % MOD;
	return ans;
}

ll C(int n , int r){
	return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	fact[0] = 1;
	for(int i = 1 ; i < MAXN ; i++)	fact[i] = fact[i - 1] * i % MOD;
	for(int i = 0 ; i < MAXN ; i++)	inv[i] = poww(fact[i] , MOD - 2);

	cin >> q;
	while(q--){
		cin >> n >> s; k = 0; vec.clear();
		fill(cnt , cnt + n + 5 , 0);
		for(int i = 0 ; i < n ; i++){
			if(s[i] == '1'){
				vec.push_back(i);
				k++;
			}
		}
		int cur = 0;
		for(int i = 0 ; i < k ; i++){
			cnt[vec[i] - i]++;
		}
		for(int i = 0 ; i < n ; i++){
			cur += cnt[i] / 2;
		}
		cout << C(cur + n - k , n - k) << endl;
	}

    return 0;
}
/*

*/