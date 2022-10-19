#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = (1 << 20);
const ll LOG = 20;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 9;

ll poww(ll x , ll y){
	ll ans = 1;
	for(; y ; y >>= 1 , x = x * x % MOD){
		if(y & 1){
			ans = ans * x % MOD;
		}
	}
	return ans;
}

ll n , k , N = (1 << 20), A[MAXN] , rev[MAXN];

void fix(ll &x){
	if(x < 0)	x += MOD;
	if(x >= MOD)	x -= MOD;
}

void NTT(ll *A, bool inv){
	for(int i = 1 ; i < N ; i++){
		rev[i] = ((rev[i >> 1] >> 1) | ((i & 1) << (LOG - 1)));
		if(rev[i] < i){
			swap(A[i] , A[rev[i]]);
		}
	}
	for(int len = 1 ; len < N ; len *= 2){
		ll wn = poww(5 , MOD / 2 / len);
		if(inv)	wn = poww(wn , MOD - 2);
		for(int i = 0 ; i < N ; i += len * 2){
			ll w = 1;
			for(int j = i ; j < i + len ; j++){
				ll v = A[j], u = w * A[j + len] % MOD;
				fix(A[j] = v + u);
				fix(A[j + len] = v - u);
				w = w * wn % MOD;
			}
		}
	}
	if(inv){
		ll invn = poww(N , MOD - 2);
		for(int i = 0 ; i < N ; i++){
			A[i] = (A[i] * invn) % MOD;
		}
	}
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> k;
	for(int i = 0 ; i < k ; i++){
		int x;
		cin >> x;
		A[x]++;
	}
	NTT(A , 0);
	for(int i = 0 ; i < MAXN ; i++){
		A[i] = poww(A[i] , n / 2);
	}
	NTT(A , 1);
	ll ans = 0;
	for(int i = 0 ; i < MAXN ; i++){
		ans = (ans + A[i] * A[i]) % MOD;
	}
	cout << ans << endl;

    return 0;
}
/*

*/