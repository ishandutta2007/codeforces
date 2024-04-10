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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , k , l , S[MAXN] , A[MAXN] , dp[MAXN] , par[MAXN];
string s;

pll check(ll x){
    for(int i = 1 ; i <= n ; i++){
        dp[i] = dp[i - 1] + A[i]; par[i] = 0;
        if(dp[max(0 , i - l)] + x < dp[i]){
            dp[i] = dp[max(0 , i - l)] + x;
            par[i] = 1;
        }
    }
    int cur = n , cnt = 0;
    while(cur != 0){
        cnt += par[cur];
        if(par[cur] == 0){
            cur--;
        }
        else{
            cur = max(0 , cur - l);
        }
    }
    return {dp[n] , cnt};
}

ll solve(ll x){
    fill(dp , dp + MAXN , 0);
    fill(par , par + MAXN , 0);
    ll sum = 0;
    for(int i = 1 ; i <= n ; i++){
        A[i] = (S[i] ^ x);
        sum += A[i];
    }
    if(sum <= k)    return 0;
    ll l = 0 , r = MOD;
    while(r - l > 1){
        ll mid = l + r >> 1;
        if(check(mid).Y > k)   l = mid;
        else    r = mid;
    }
    pll res = check(r);
    return res.X - k * r;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> k >> l >> s;
    if(l * k >= n)  return cout << 0 << endl , 0;
    for(int i = 0 ; i < n ; i++){
        if('a' <= s[i]){
            S[i + 1] = 1;
        }
        else{
            S[i + 1] = 0;
        }
    }

    cout << min(solve(0) , solve(1));

    return 0;
}
/*

*/