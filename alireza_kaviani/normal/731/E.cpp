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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , mx = -INF , A[MAXN] , ps[MAXN] , dp[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i];
		ps[i] = A[i];
	}
	partial_sum(ps , ps + MAXN , ps);
	dp[n] = 0;
	mx = ps[n] - dp[n];
	for(int i = n - 1 ; i >= 1 ; i--){
		dp[i] = mx;
		mx = max(mx , ps[i] - dp[i]);
//		cout << i << sep << dp[i] << endl;
	}
	cout << dp[1] << endl;

    return 0;
}
/*

*/