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

const ll MAXN = 110;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , ans , A[MAXN] , mark[MAXN] , mex[MAXN][MAXN] , dp[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		memset(mex , 0 , sizeof(mex));
		memset(dp , 0 , sizeof(dp));
		cin >> n; ans = 0;
		for(int i = 1 ; i <= n ; i++){
			cin >> A[i];
		}
		for(int i = 1 ; i <= n ; i++){
			memset(mark , 0 , sizeof(mark));
			int ptr = 0;
			for(int j = i ; j <= n ; j++){
				if(A[j] < MAXN){
					mark[A[j]] = 1;
				}
				while(mark[ptr])	ptr++;
				mex[i][j] = ptr;
			}
		}
		for(int l = n ; l >= 1 ; l--){
			for(int r = l ; r <= n ; r++){
				for(int i = l ; i <= r ; i++){
					dp[l][r] = max(dp[l][r] , mex[l][i] + 1 + dp[i + 1][r]);
				}
				//cout << l << sep << r << sep << dp[l][r] << sep << mex[l][r] << endl;
				ans += dp[l][r];
			}
		}
		cout << ans << endl;
	}

    return 0;
}
/*

*/