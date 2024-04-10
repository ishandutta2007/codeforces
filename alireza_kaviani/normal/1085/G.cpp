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

const ll MAXN = 2010;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 9;

ll n , ans , D[MAXN][MAXN] , A[MAXN][MAXN] , fen[2][MAXN] , cnt[MAXN];

void add(int ind , int x , int v){
    for( ; x < MAXN ; x += x & -x)  fen[ind][x] += v;
}

int get(int ind , int x){
    int ans = 0;
    for(x--; x ; x -= x & -x)  ans += fen[ind][x];
    return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    D[0][0] = D[1][0] = 1;
    for(int i = 2 ; i < MAXN ; i++){
        for(int j = 1 ; j < i ; j++){
            D[i][j] = (D[i - 1][j] * (i - j) + D[i - 1][j - 1] * j) % MOD;
        }
        D[i][0] = D[i - 1][0] * i % MOD;
        D[i][i] = (i - 1) * (D[i - 1][i - 1] + D[i - 2][i - 2]) % MOD;
    }

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> A[n - i][n - j];
        }
    }
    fill(A[n + 1] , A[n + 1] + MAXN , n + 1);

    ll pwd = 1;
    for(int i = 1 ; i <= n ; i++){
        memset(fen , 0 , sizeof(fen));
        memset(cnt , 0 , sizeof(cnt));
        ll cur = 0 , common = 0;
        for(int j = 1 ; j <= n ; j++){
            add(0 , A[i][j] , 1);
            cnt[A[i][j]]++;
            if(cnt[A[i][j]] == 2){
                add(1 , A[i][j] , 1); common++;
            }
            cnt[A[i + 1][j]]++;
            if(i != n && cnt[A[i + 1][j]] == 2){
                add(1 , A[i + 1][j] , 1); common++;
            }
            int ind = get(0 , A[i][j]) , c = get(1 , A[i][j]) , flag = 0;
            if(A[i + 1][j] < A[i][j] && cnt[A[i + 1][j]] == 2){
                ind--; c--;
            }
            if(i != n && cnt[A[i + 1][j]] == 2){
                flag = 1;
            }
            cur += (ind - c) * D[j - 1][common - flag];
            if(common - flag > 0){
                cur += c * D[j - 1][common - 1 - flag];
            }
            cur %= MOD;
        }
        ans = (ans + cur * pwd) % MOD;
        pwd = pwd * D[n][n] % MOD;
    }
    cout << ans << endl;

    return 0;
}
/*

*/