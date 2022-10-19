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

const ll MAXN = 82;
const ll LOG = 8;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , L[MAXN] , R[MAXN];
double A[MAXN] , B[MAXN] , C[MAXN] , ans[MAXN] , dp[LOG][MAXN][MAXN] , sum[MAXN][MAXN][MAXN];
vector<int> compress;

void insert(int ind , int obj){
    for(int i = n ; i >= 0 ; i--){
        for(int j = n - i ; j >= 0 ; j--){
            dp[ind][i][j] *= C[obj];
            if(i > 0){
                dp[ind][i][j] += dp[ind][i - 1][j] * A[obj];
            }
            if(j > 0){
                dp[ind][i][j] += dp[ind][i][j - 1] * B[obj];
            }
        }
    }
}

void solve(int h , int l , int r){
    if(r - l == 1){
        for(int i = 0 ; i <= n ; i++){
            for(int j = 0 ; j <= n - i ; j++){
                sum[l][i][j] += dp[h][i][j] * B[l];
            }
        }
        return;
    }
    int mid = l + r >> 1;
    memcpy(&dp[h + 1] , &dp[h] , sizeof(dp[h]));
    for(int i = mid ; i < r ; i++)  insert(h + 1 , i);
    solve(h + 1 , l , mid);
    memcpy(&dp[h + 1] , &dp[h] , sizeof(dp[h]));
    for(int i = l ; i < mid ; i++)  insert(h + 1 , i);
    solve(h + 1 , mid , r);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> L[i] >> R[i];
        compress.push_back(L[i]);
        compress.push_back(R[i]);
    }
    sort(all(compress));
    compress.resize(unique(all(compress)) - compress.begin());
    dp[0][0][0] = 1;
    for(int i = 0 ; i + 1 < SZ(compress) ; i++){
        int l = compress[i] , r = compress[i + 1];
        for(int j = 0 ; j < n ; j++){
            A[j] = double(max(0 , min(l , R[j]) - L[j])) / double(R[j] - L[j]);
            C[j] = double(max(0 , R[j] - max(r , L[j]))) / double(R[j] - L[j]);
            B[j] = 1 - A[j] - C[j];
        }
        solve(0 , 0 , n);
    }
    for(int i = 0 ; i < n ; i++){
        fill(ans , ans + MAXN , 0);
        for(int j = 0 ; j < n ; j++){
            for(int k = 0 ; k < n ; k++){
                for(int l = j ; l <= min(n , j + k) ; l++){
                    ans[l] += double(1) / double(k + 1) * sum[i][j][k];
                }
            }
        }
        for(int j = 0 ; j < n ; j++){
            printf("%.10f " , ans[j]);
        }
        printf("\n");
    }

    return 0;
}
/*

*/