#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 998244353;
const ll Inf = 2242545357980376863LL;
const ll Log = 20;
const ll N = 1ll << Log;
const int Maxn = N + 10;

ll mul(ll a, ll b){
	return (a * b) % Mod;
}

int bin_pow(ll b, ll p){
    ll res = 1;
    for(ll j = 1, pw = b; j <= p; j <<= 1, pw = mul(pw, pw))
    	if(p & j)
    		res = mul(res, pw);
    return res;
}
ll pw[2][Maxn];

void calc(){
    pw[0][0] = 1;
    pw[0][1] = bin_pow(3, (Mod - 1) / N);
    for(int i = 2; i < N; i++)
		pw[0][i] = mul(pw[0][i - 1], pw[0][1]);
    for(int i = 1; i < N; i++)
		pw[1][i] = pw[0][N - i];
    pw[1][0] = 1;
}

ll A[Maxn], B[Maxn], C[Maxn];

void FFT(ll *arr, bool inv){
    for(int i = 0; i < N; i++){
		int rev = 0;
		for(int j = 0; j < Log; j++)
			rev += ((i >> j) & 1) << (Log - 1 - j);
		if(rev < i) swap(arr[i], arr[rev]);
    }
    for(int st = 0; st < Log; st++){
		int ln = 1 << st;
		for(int l = 0; l < N; l += ln+ln){
			for(int i = 0; i < ln; i++){
				ll &a = arr[l + i], &b = arr[l + ln + i], c = mul(b, pw[inv][i << (Log - 1 - st)]);
				b = (a - c + Mod) % Mod;
				a = (a + c) % Mod;
			}
		}
    }
    if(inv){
		int inverse = bin_pow(N, Mod - 2);
		for(int i = 0; i < N; i++)
			arr[i] = mul(arr[i], inverse);
    }
}

map<ll, ll> mp;

ll b[10], dp[10][Maxn];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	calc();
	A[0] = 1; A[1] = 2;
	FFT(A, false);
	B[0] = 1; B[1] = 2; B[2] = 1;
	FFT(B, false);
	//for(int i = 0; i < N; i++) C[i] = mul(A[i], mul(A[i], B[i]));
	//FFT(C, true);
	ll n, k;
	cin >> n >> k;
	
	ll c1 = 0, c2 = 0;
	ll v;
	for(int i = 1; i <= n; i++){
		cin >> v;
		mp[v] ++;
	}
	for(int i = 1; i <= k; i++)
		cin >> b[i];
	sort(b + 1, b + k + 1);
	b[k + 1] = Inf;
	ll p = 1;
	for(auto x : mp){
		//cerr << x.F << " " << x.S << '\n';
		while(b[p] <= x.F){
			for(int i = 0; i < N; i++) dp[p][i] = mul(bin_pow(A[i], c1), bin_pow(B[i], c2));
			FFT(dp[p], true);
			p ++;
		}
		if(x.S == 1) c1 ++;
		else c2 ++;
	}
	while(p <= k){
		for(int i = 0; i < N; i++) dp[p][i] = mul(bin_pow(A[i], c1), bin_pow(B[i], c2));
		FFT(dp[p], true);
		p ++;
	}
	ll q;
	cin >> q;
	for(int i = 0; i < q; i++){
		ll ans = 0;
		cin >> v;
		//cerr << "v : " << v << '\n';
		v >>= 1;
		for(int j = 1; j <= k; j++){
			if(v >= b[j] + 1) ans += dp[j][v - b[j] - 1];
		}
		cout << ans % Mod << '\n';
	}
	return 0;
}