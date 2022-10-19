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

const ll MAXN = 61;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 9;

ll q , n , C[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    for(int i = 0 ; i < MAXN ; i++){
        C[i][0] = 1;
        for(int j = 1 ; j <= i ; j++){
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }

    cin >> q;
    while(q--){
        cin >> n;
        ll A = 0 , B = 0 , cntA = 0 , cntB = 0;
        for(int i = 0 ; i < n ; i++){
            if(i % 4 == 0 || i % 4 == 3){
                A += C[n - i - 1][n / 2 - cntA - 1];
                cntB++;
            }
            else{
                B += C[n - i - 1][n / 2 - cntB - 1];
                cntA++;
            }
        }
        cout << A % MOD << sep << B % MOD << sep << 1 << endl;
    }

    return 0;
}
/*

*/