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

const ll MAX = 410;
const ll LOG = 20;
const ll MAXN = (1 << LOG);
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 9;

ll n , m , r , c , tot , A[MAXN] , B[MAXN] , C[MAXN] , ans[MAXN] , rev[MAXN] , cnt[MAX][MAX];
string s[MAX] , t[MAX];

ll poww(ll x , ll y){
	ll ans = 1;
	for(; y ; y >>= 1 , x = x * x % MOD){
		if(y & 1){
			ans = ans * x % MOD;
		}
	}
	return ans;
}

void fix(ll &x){
	if(x >= MOD)	x -= MOD;
	if(x < 0)	x += MOD;
}

void NTT(ll A[] , bool inv){
	for(int i = 0 ; i < MAXN ; i++){
		if(rev[i] < i){
			swap(A[i] , A[rev[i]]);
		}
	}
	for(int len = 1 ; len < MAXN ; len *= 2){
		ll wn = poww(5 , MOD / 2 / len);
		if(inv)	wn = poww(wn , MOD - 2);
		for(int i = 0 ; i < MAXN ; i += len * 2){
			ll w = 1;
			for(int j = i ; j < i + len ; j++){
				ll v = A[j] , u = w * A[j + len] % MOD;
				fix(A[j] = v + u);
				fix(A[j + len] = v - u);
				w = w * wn % MOD;
			}
		}
	}
	if(inv){
		ll invn = poww(MAXN , MOD - 2);
		for(int i = 0 ; i < MAXN ; i++){
			A[i] = (A[i] * invn) % MOD;
		}
	}
}

int ind(int x , int y){
	return x * m * 2 + y;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	for(int i = 1 ; i < MAXN ; i++){
		rev[i] = ((rev[i >> 1] >> 1) | ((i & 1) << (LOG - 1)));
	}

	cin >> n >> m;
	for(int i = 0 ; i < n ; i++){
		cin >> s[i];
	}
	cin >> r >> c;
	for(int i = 0 ; i < r ; i++){
		cin >> t[i];
		for(int j = 0 ; j < c ; j++){
			if(t[i][j] != '?'){
				tot++;
			}
		}
	}

	for(int i = 0 ; i < 26 ; i++){
		memset(A , 0 , sizeof(A));
		memset(B , 0 , sizeof(B));
		for(int j = 0 ; j < n ; j++){
			for(int k = 0 ; k < m ; k++){
				if(s[j][k] == char(97 + i)){
					A[ind(j , k)] = 1;
				}
			}
		}
		for(int j = 0 ; j < r ; j++){
			for(int k = 0 ; k < c ; k++){
				if(t[j][k] == char(97 + i)){
					B[ind(((n - j) % n + n) % n , ((m - k) % m + m) % m)]++;
				}
			}
		}
		NTT(A , 0);
		NTT(B , 0);
		for(int j = 0 ; j < MAXN ; j++){
			C[j] = A[j] * B[j] % MOD;
		}
		for(int j = 0 ; j < MAXN ; j++){
			ans[j] += C[j];
		}
	}
	for(int i = 0 ; i < MAXN ; i++){
		ans[i] %= MOD;
	}
	NTT(ans , 1);
	for(int i = 0 ; i < 2 * n ; i++){
		for(int j = 0 ; j < 2 * m ; j++){
			cnt[(i >= n ? i - n : i)][(j >= m ? j - m : j)] += ans[ind(i , j)];
		}
	}
//	cout << tot << endl;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
//			cout << cnt[i][j] << sep;
			cout << (cnt[i][j] == tot ? 1 : 0);
		}
		cout << endl;
	}

    return 0;
}
/*

*/