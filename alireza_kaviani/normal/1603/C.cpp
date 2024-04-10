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
const int SQ = 320;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 9;

int q , n , A[MAXN] , dp[2][SQ * 2];
vector<int> cur , prv;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cur.clear(); prv.clear(); ll ans = 0;
		cin >> n;
		for(int i = 1 ; i <= n ; i++){
			cin >> A[i];
		}
		prv.push_back(A[n]);
		dp[0][0] = 1;
		for(int i = n - 1 ; i >= 1 ; i--){
			cur.clear();
			for(int j = 1 ; j <= min(SQ , A[i]) ; j++){
				cur.push_back(j);
			}
			for(int j = SQ ; j >= 1 ; j--){
				if(A[i] / j > SQ){
					cur.push_back(A[i] / j);
				}
			}
			for(int j = 0 ; j < SQ * 2 ; j++){
				dp[1][j] = dp[0][j];
				dp[0][j] = 0;
			}
			int ptr = 0;
			for(int j = 0 ; j < SZ(prv) ; j++){
				int y = (A[i] + prv[j] - 1) / prv[j] , x = (A[i] / y);
				while(ptr < SZ(cur) && cur[ptr] < x)	ptr++;
				dp[0][ptr] += dp[1][j];
				ans = (ans + 1ll * dp[1][j] * (y - 1) * i) % MOD;
			//	cout << i << sep << j << sep << prv[j] << sep << x << sep << y << endl;
			}
			dp[0][SZ(cur) - 1]++;
			prv = cur;
		}
		cout << ans << endl;
	}

    return 0;
}
/*

*/