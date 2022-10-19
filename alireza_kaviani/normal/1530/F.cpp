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

const ll MAXN = 1e6 + 10;
const ll LOG = 23;
const ll INF = 8e18;
const int MOD = 31607; //998244353; //1e9 + 9;

int n , A[LOG][LOG] , mul[(1 << (LOG - 2))] , popcnt[(1 << (LOG - 2))] , ans[(1 << LOG)];

int poww(int x , int y){
	int ans = 1;
	for( ; y ; y >>= 1 , x = x * x % MOD){
		if(y & 1){
			ans = ans * x % MOD;
		}
	}
	return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	fill(ans , ans + (1 << LOG) , 1);
	
	for(int i = 1 ; i < (1 << LOG - 2) ; i++){
		popcnt[i] = ((i & 1) ? 0 : popcnt[i / 2] + 1);
	}

	cin >> n;
	int inv = poww(10000 , MOD - 2);
	int inv16 = poww(16 , MOD - 2);
//	cout << inv << endl;
//	cout << inv16 * 11 % MOD << endl;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> A[i][j];
//			A[i][j] = 10000 - A[i][j];
			A[i][j] = A[i][j] * inv % MOD;
//			cout << A[i][j] << endl;
		}
		mul[0] = 1;
		for(int j = 1 ; j < (1 << n) ; j++){
			mul[j] = mul[j ^ (j & -j)] * A[i][popcnt[j]] % MOD;
		}
		int all = (1 << n) - 1 , main = (all ^ (1 << i)) , anti = (all ^ (1 << (n - i - 1)));
		for(int j = 0 ; j < (1 << (n + 2)) ; j++){
			int cur = (j & all);
			if((j & (1 << n)) == 0)	cur &= main;
			if((j & (1 << (n + 1))) == 0)	cur &= anti;
			int val = (MOD + 1 - mul[cur]) * mul[(cur ^ all)] % MOD;
			ans[j] = ans[j] * val % MOD;
		}
	}
	int tot = 0;
	for(int i = 0 ; i < (1 << (n + 2)) ; i++){
//		cout << i << sep << ans[i] << endl;
		if(__builtin_popcount(i) % 2 == (n + 2) % 2)	tot = (tot + ans[i]) % MOD;
		else	tot = (tot + MOD - ans[i]) % MOD;
//		cout << i << sep << tot << endl;
	}
	cout << (MOD + 1 - tot) % MOD << endl;

    return 0;
}
/*

*/