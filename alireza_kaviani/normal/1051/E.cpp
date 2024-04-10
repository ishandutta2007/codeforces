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
const ll MOD = 998244353; //1e9 + 9;
const ll mod = 1111211111;
const ll base = 1e6 + 3;

ll n , dp[MAXN] , ps[MAXN] , hs[3][MAXN] , pw[MAXN];
string s , t[2];

ll getSum(int l , int r){
    l = max(l , 0); r = max(r , 0);
    if(l >= r)  return 0;
    return (ps[r - 1] + MOD - (l == 0 ? 0 : ps[l - 1])) % MOD;
}

void build(int ind , string &x){
    for(int i = 0 ; i < SZ(x) ; i++){
        hs[ind][i + 1] = (hs[ind][i] + x[i] * pw[i]) % mod;
        //cout << ind << sep << i << sep << hs[ind][i] << endl;
    }
}

int getHash(int ind , int l , int r){
    //cout << ind << sep << l << sep << r << sep << (hs[ind][r] + mod - hs[ind][l]) % mod << endl;
    return (hs[ind][r] + mod - hs[ind][l]) * pw[n - l] % mod;
}

int getLCP(int pos , int ind , int bound){
    int l = 0 , r = bound + 1;
    while(r - l > 1){
        int mid = l + r >> 1;
        //cout << pos << sep << ind << sep << mid << sep << getHash(0 , pos , pos + mid) << sep << getHash(ind , 0 , mid) << endl;
        if(getHash(2 , pos , pos + mid) == getHash(ind , 0 , mid))  l = mid;
        else    r = mid;
    }
    //cout << "===============" << endl;
    return l;
}

int check(int pos , int ind , int bound){
    int lcp = getLCP(pos , ind , bound);
    if(lcp != bound){
        if(ind == 0 && t[ind][lcp] > s[pos + lcp])  return 0;
        if(ind == 1 && t[ind][lcp] < s[pos + lcp])  return 0;
    }
    return 1;
}

void add(int ind , int i){
    int pos = i - SZ(t[ind]) + 1 , bound = SZ(t[ind]);
    if(pos <= 0) return;
    if(SZ(t[ind]) > 1 && s[pos] == '0') return;
    if(check(pos , ind , bound)){
        dp[i] = (dp[i] + dp[pos - 1]) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    pw[0] = 1;
    for(int i = 1 ; i < MAXN ; i++){
        pw[i] = pw[i - 1] * base % mod;
    }

    cin >> s >> t[0] >> t[1];
    if(SZ(t[1]) < SZ(t[0])){
        return cout << 0 << endl , 0;
    }

    n = SZ(s); s = "." + s;
    build(0 , t[0]); build(1 , t[1]); build(2 , s);

    dp[0] = ps[0] = 1;
    for(int i = 1 ; i <= n ; i++){
        if(i < n && s[i + 1] == '0' && t[0] != "0"){
            ps[i] = ps[i - 1];
            continue;
        }
        dp[i] = getSum(i - SZ(t[1]) + 1 , i - SZ(t[0]));
        if(SZ(t[0]) != SZ(t[1])){
            add(0 , i);
            add(1 , i);
        }
        else{
            int pos = i - SZ(t[0]) + 1 , bound = SZ(t[0]);
            if(pos > 0 && check(pos , 0 , bound) && check(pos , 1 , bound)){
                dp[i] = (dp[i] + dp[pos - 1]) % MOD;
            }
        }
        ps[i] = (ps[i - 1] + dp[i] * (i == n || s[i + 1] != '0')) % MOD;
        //cout << i << sep << dp[i] << sep << ps[i] << endl;
    }
    cout << dp[n] << endl;

    return 0;
}
/*

*/