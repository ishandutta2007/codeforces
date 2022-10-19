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

const ll MAX = 1e4 + 10;
const ll MAXN = 110;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll q , n , A[MAXN] , B[MAXN] , dp[MAXN][MAX];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin >> q;
	while(q--){
		cin >> n;
		ll sum = 0 , sum2 = 0;
		for(int i = 1 ; i <= n ; i++){
			cin >> A[i];
			sum += A[i];
			sum2 += A[i] * A[i];
		}
		for(int i = 1 ; i <= n ; i++){
			cin >> B[i];
			sum += B[i];
			sum2 += B[i] * B[i];
		}
		dp[0][0] = 1;
		for(int i = 1 ; i <= n ; i++){
			for(int j = 0 ; j < MAX ; j++){
				dp[i][j] = 0;
				if(j >= A[i])	dp[i][j] |= dp[i - 1][j - A[i]];
				if(j >= B[i])	dp[i][j] |= dp[i - 1][j - B[i]];
			}
		}
		ll ans = INF;
		for(ll i = 0 ; i < MAX ; i++){
			if(dp[n][i]){
				ans = min(ans , i * i + (sum - i) * (sum - i));
			}
		}
		cout << (ans + (n - 2) * sum2) << endl;
	}

    return 0;
}
/*

*/