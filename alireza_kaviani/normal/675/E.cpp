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

ll n , ans , A[MAXN] , dp[MAXN];
pii seg[MAXN << 2];

void build(int id = 1 , int l = 0 , int r = n){
    if(r - l == 1){
        seg[id] = {A[l] , l};
        return;
    }
    int mid = l + r >> 1;
    build(lc , l , mid);
    build(rc , mid , r);
    seg[id] = max(seg[lc] , seg[rc]);
}

pii get(int ql , int qr , int id = 1 , int l = 0 , int r = n){
    if(qr <= l || r <= ql)  return {-MOD , -MOD};
    if(ql <= l && r <= qr)  return seg[id];
    int mid = l + r >> 1;
    return max(get(ql , qr , lc , l , mid) , get(ql , qr , rc , mid , r));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i = 0 ; i + 1 < n ; i++){
        cin >> A[i];
    }
    build();
    for(int i = n - 2 ; i >= 0 ; i--){
        int R = get(i + 1 , A[i]).Y;
        dp[i] = dp[R] + n - A[i] + R - i;
        ans += dp[i];
    }
    cout << ans << endl;

    return 0;
}
/*

*/