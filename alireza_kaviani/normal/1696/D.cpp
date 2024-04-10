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

const ll MAXN = 2.5e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , A[MAXN] , L[MAXN][2] , dp[MAXN] , seg[2][MAXN << 2];
vector<int> stk[2];

int check(int x , int y , int ind){
    if(ind == 0){
        return A[x] < A[y];
    }
    else{
        return A[y] < A[x];
    }
}

void modify(int ind , int pos , int val , int id = 1 , int l = 1 , int r = n + 1){
    if(r - l == 1){
        seg[ind][id] = val;
        return;
    }
    int mid = l + r >> 1;
    if(pos < mid)   modify(ind , pos , val , lc , l , mid);
    else    modify(ind , pos , val , rc , mid , r);
    seg[ind][id] = min(seg[ind][lc] , seg[ind][rc]);
}

int get(int ind , int ql , int qr , int id = 1 , int l = 1 , int r = n + 1){
    if(qr <= l || r <= ql)  return MOD;
    if(ql <= l && r <= qr)  return seg[ind][id];
    int mid = l + r >> 1;
    return min(get(ind , ql , qr , lc , l , mid) , get(ind , ql , qr , rc , mid , r));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n;
        stk[0].clear(); stk[1].clear();
        fill(seg[0] , seg[0] + (n + 10) * 4 , MOD);
        fill(seg[1] , seg[1] + (n + 10) * 4 , MOD);
        for(int i = 1 ; i <= n ; i++){
            cin >> A[i];
            L[i][0] = L[i][1] = dp[i] = 0;
        }
        for(int i = 1 ; i <= n ; i++){
            for(int j = 0 ; j < 2 ; j++){
                while(SZ(stk[j]) && check(stk[j].back() , i , j)){
                    modify(j , stk[j].back() , MOD);
                    stk[j].pop_back();
                }
                if(SZ(stk[j])){
                    L[i][j] = stk[j].back();
                }
                stk[j].push_back(i);
            }
            if(i != 1){
                dp[i] = min(get(0 , L[i][1] , i) , get(1 , L[i][0] , i)) + 1;
            }
            modify(0 , i , dp[i]);
            modify(1 , i , dp[i]);
            //cout << i << sep << dp[i] << endl;
        }
        cout << dp[n] << endl;
    }

    return 0;
}
/*

*/