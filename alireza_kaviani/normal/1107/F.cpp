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

const ll MAXN = 510;
const ll LOG = 22;
const ll INF = 4e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , A[MAXN] , B[MAXN] , C[MAXN] , dp[MAXN][MAXN];
vector<int> vec = {0};

int cmp(int x , int y){
    return B[x] > B[y];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    B[0] = MOD;
    for(int i = 1 ; i <= n ; i++){
        cin >> A[i] >> B[i] >> C[i];
        vec.push_back(i);
    }
    sort(all(vec) , cmp);

    dp[0][0] = 0;
    for(int i = 1 ; i <= n; i++){
        int v = vec[i];
        for(int j = 0 ; j <= n ; j++){
            dp[i][j] = dp[i - 1][j] + max(0ll , A[v] - B[v] * C[v]);
            if(j > 0){
                dp[i][j] = max(dp[i][j] , dp[i - 1][j - 1] + A[v] - B[v] * (j - 1));
            }
        }
    }

    ll ans = 0;
    for(int i = 0 ; i <= n ; i++){
        ans = max(ans , dp[n][i]);
    }
    cout << ans << endl;

    return 0;
}
/*

*/