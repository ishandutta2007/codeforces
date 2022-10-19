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

const ll MAXN = 1e5 + 10;
const ll SQ = 320;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , m , p , dp[MAXN * SQ];

int getInd(int x , int y , int z){
    return x * (n + 1) * (n + 1) + y * (n + 1) + z;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m >> p;
    if(n > m){
        return cout << 0 << endl , 0;
    }
    dp[getInd(0 , 0 , 0)] = 1;
    for(int i = 1 ; i <= m ; i++){
        for(int j = 0 ; j <= n ; j++){
            for(int k = 0 ; k <= n ; k++){
                for(int x = j + (i == p) ; x <= j + 1 ; x++){
                    for(int y = k ; y <= k + 1 ; y++){
                        if(x > n || y > n || y > x) continue;
                        dp[getInd(i , x , y)] = (dp[getInd(i , x , y)] + dp[getInd(i - 1 , j , k)]) % MOD;
                    }
                }
            }
        }
    }
    ll ans = dp[getInd(m , n , n)];
    for(int i = 1 ; i <= n ; i++){
        ans = ans * i % MOD;
    }
    cout << ans << endl;

	return 0;
}
/*

*/