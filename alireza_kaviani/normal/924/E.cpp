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

const ll MAXN = 1e4 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , l , r , ans , W[MAXN] , T[MAXN] , ps[MAXN] , dp[MAXN];
vector<int> A , B = {0};

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fill(dp + 1 , dp + MAXN , MOD);

    cin >> n >> l >> r;
    for(int i = 0 ; i < n ; i++){
        cin >> W[i];
    }
    for(int i = 0 ; i < n ; i++){
        cin >> T[i];
        if(T[i] == 0){
            A.push_back(W[i]);
        }
        else{
            B.push_back(W[i]);
        }
    }
    sort(all(B));
    partial_sum(all(B) , ps);

    dp[0] = 0;
    for(int i : A){
        for(int j = MAXN - 1 ; j >= i ; j--){
            dp[j] = min(dp[j] , dp[j - i]);
        }
    }
    for(int i = SZ(B) - 1 ; i >= 0 ; i--){
        for(int j = l ; j <= r ; j++){
            if(dp[j] < MOD && j + ps[i] <= r){
                ans = max(ans , i + (i + dp[j] < SZ(B) - 1));
            }
        }
        for(int j = MAXN - 1 ; j >= B[i] ; j--){
            dp[j] = min(dp[j] , dp[j - B[i]] + 1);
        }
    }
    cout << ans << endl;

    return 0;
}
/*

*/