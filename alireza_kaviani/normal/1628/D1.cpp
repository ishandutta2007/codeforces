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

const ll MAXN = 2020;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll q , n , m , k , inv2 = (MOD + 1) / 2 , dp[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	for(int i = 0 ; i < MAXN ; i++){
		dp[i][0] = 0;
		dp[i][i] = i;
		for(int j = 1 ; j < i ; j++){
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) * inv2 % MOD;
		}
	}
	cin >> q;
	while(q--){
		cin >> n >> m >> k;
		cout << dp[n][m] * k % MOD << endl;
	}
	

    return 0;
}
/*

*/