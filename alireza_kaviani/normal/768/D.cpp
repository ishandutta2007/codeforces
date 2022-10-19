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

const ll MAXK = 1010;
const ll MAXN = 10010;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll k , q , dp[MAXK][MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> k >> q;
	dp[0][0] = 2e15;
	for(int i = 1 ; i < MAXK ; i++){
		for(int j = 1 ; j < MAXN ; j++){
			dp[i][j] = double(i) / double(k) * dp[i][j - 1] + double(k - i + 1) / double(k) * dp[i - 1][j - 1];
		}
	}
	while(q--){
		ll p;
		cin >> p;
		p *= 1e12;
		cout << lower_bound(dp[k] , dp[k] + MAXN , p) - dp[k] << endl;
	}

    return 0;
}
/*

*/