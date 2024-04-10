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
const ll MAXP = 7;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , p , k , A[MAXN] , S[MAXN][MAXP] , dp[MAXN][(1 << MAXP)];
vector<int> vec = {0};

int cmp(int x , int y){
    return A[x] > A[y];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> p >> k;
    A[0] = MOD;
    for(int i = 1 ; i <= n ; i++){
        cin >> A[i];
        vec.push_back(i);
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j < p ; j++){
            cin >> S[i][j];
        }
    }
    sort(all(vec) , cmp);

    fill(dp[0] + 1 , dp[0] + (1 << p) , -INF);
    for(int i = 1 ; i <= n; i++){
        int v = vec[i];
        for(int j = 0 ; j < (1 << p) ; j++){
            dp[i][j] = (dp[i - 1][j] + (i - __builtin_popcount(j) <= k ? A[v] : 0));
            for(int k = 0 ; k < p ; k++){
                if(j & (1 << k)){
                    dp[i][j] = max(dp[i][j] , dp[i - 1][(j ^ (1 << k))] + S[v][k]);
                }
            }
        }
    }
    cout << dp[n][(1 << p) - 1] << endl;

    return 0;
}
/*

*/