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

int q , n , dp[MAXN][MAXN][2][2]; // even , odd , turn , sum

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    dp[0][0][0][0] = dp[0][0][1][0] = 1;
    dp[0][0][0][1] = dp[0][0][1][1] = 0;
    for(int i = 0 ; i < MAXN ; i++){
        for(int j = 0 ; j < MAXN ; j++){
            if(i + j == 0)  continue;
            for(int k = 0 ; k < 2 ; k++){
                for(int l = 0 ; l < 2 ; l++){
                    dp[i][j][k][l] = k;
                    if(i > 0 && dp[i - 1][j][1 - k][l] == 1 - k){
                        dp[i][j][k][l] = 1 - k;
                    }
                    if(j > 0 && dp[i][j - 1][1 - k][(k == 0 ? 1 - l : l)] == 1 - k){
                        dp[i][j][k][l] = 1 - k;
                    }
                }
            }
        }
    }

    cin >> q;
    while(q--){
        cin >> n;
        int e = 0 , o = 0;
        for(int i = 0 ; i < n ; i++){
            int A;
            cin >> A;
            if(abs(A) % 2 == 1){
                o++;
            }
            else{
                e++;
            }
        }
        cout << (dp[e][o][0][0] == 1 ? "Alice" : "Bob") << endl;
    }

    return 0;
}
/*

*/