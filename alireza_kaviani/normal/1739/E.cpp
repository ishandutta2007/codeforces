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
#define lc          id << 1
#define rc          lc | 1

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , ans , dp[MAXN][3][2] , seg[3][2][MAXN << 2];
string s[2];

void modify(int ix , int iy , int pos , int val , int id = 1 , int l = 0 , int r = n){
    if(r - l == 1){
        seg[ix][iy][id] = val;
        return;
    }
    int mid = l + r >> 1;
    if(pos < mid)   modify(ix , iy , pos , val , lc , l , mid);
    else    modify(ix , iy , pos , val , rc , mid , r);
    seg[ix][iy][id] = max(seg[ix][iy][lc] , seg[ix][iy][rc]);
}

int get(int ix , int iy , int ql , int qr , int id = 1 , int l = 0 , int r = n){
    if(qr <= l || r <= ql)  return 0;
    if(ql <= l && r <= qr)  return seg[ix][iy][id];
    int mid = l + r >> 1;
    return max(get(ix , iy , ql , qr , lc , l , mid) , get(ix , iy , ql , qr , rc , mid , r));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> s[0] >> s[1];
    s[0][0] = '1';
    for(int i = n - 1 ; i >= 0 ; i--){
        for(int j = 2 ; j >= 0 ; j--){
            for(int k = 0 ; k <= 1 ; k++){
                if(s[k][i] == '0'){
                    continue;
                }
                dp[i][j][k] = get(2 , 1 - k , i + j , n) + 1;
                for(int l = 1 ; l <= 2 ; l++){
                    dp[i][j][k] = max(dp[i][j][k] , get(max(0 , j - l) , k , i + l , n) + 1);
                }
                modify(j , k , i , dp[i][j][k]);
            }
        }
    }
    cout << dp[0][0][0] - 1 << endl;

    return 0;
}
/*

*/