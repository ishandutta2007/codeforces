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

const ll MAXK = 1010;
const ll MAXN = 35e3 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;
const ll BASE = 1e7 + 19;

int n , k , q , cnt , V[MAXN] , W[MAXN] , L[MAXN] , R[MAXN] , dp[LOG][MAXK];
vector<int> seg[MAXN << 2];

void add(int ql , int qr , int x , int id = 1 , int l = 0 , int r = MAXN){
    if(qr <= l || r <= ql)  return;
    if(ql <= l && r <= qr){
        seg[id].push_back(x);
        return;
    }
    int mid = l + r >> 1;
    add(ql , qr , x , lc , l , mid);
    add(ql , qr , x , rc , mid , r);
}

void Solve(int h = 1 , int id = 1 , int l = 0 , int r = MAXN){
    for(int i = 0 ; i < MAXK ; i++) dp[h][i] = dp[h - 1][i];
    for(int i : seg[id]){
        for(int j = MAXK - 1 ; j >= W[i] ; j--){
            dp[h][j] = max(dp[h][j] , dp[h][j - W[i]] + V[i]);
        }
    }
    if(r - l == 1){
        if(l >= cnt)    return;
        ll res = 0 , p = 1;
        for(int i = 1 ; i <= k ; i++){
            res = (res + dp[h][i] * p) % MOD;
            p = p * BASE % MOD;
        }
        cout << res << endl;
        return;
    }
    int mid = l + r >> 1;
    Solve(h + 1 , lc , l , mid);
    Solve(h + 1 , rc , mid , r);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fill(L , L + MAXN , MAXN);
    fill(R , R + MAXN , MAXN);

    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++){
        cin >> V[i] >> W[i];
        L[i] = 0;
    }
    cin >> q;
    for(int i = 1 ; i <= q ; i++){
        int type , x , v , w;
        cin >> type;
        if(type == 1){
            cin >> v >> w; n++;
            V[n] = v; W[n] = w;
            L[n] = cnt;
        }
        if(type == 2){
            cin >> x;
            R[x] = cnt;
        }
        if(type == 3){
            cnt++;
        }
    }

    for(int i = 1 ; i <= n ; i++){
        add(L[i] , R[i] , i);
    }
    Solve();


    return 0;
}
/*

*/