//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define fout(x) {cout << x; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 3e6;
const int M = 1e7;
const ll inf = 1e18;
const long long mod = 1e9 + 7;
const long long N = 3e5;


template <typename T> void vout(T s){cout << s << endl;exit(0);}

long long fact[N];

long long mul(long long a, long long b){
    return (a * b) % mod;
}

long long sum(long long a, long long b){
    if(a + b >= mod){
        return a + b - mod;
    }else{
        return a + b;
    }
}

long long bp(long long a, long long n){
    long long res = 1;
    while(n){
        if((n & 1)){
            res = mul(res, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}

long long _div(long long a, long long b){
    return mul(a, bp(b, mod - 2));
}

long long c(long long n, long long k){
    if(k > n)return 0;
    return _div(fact[n], mul(fact[k], fact[n - k]));
}


void solve(){
    int n, k;
    cin >> n >> k;
    if(k == 1){
        cout << n << "\n";
        return;
    }
    
    long long ans = 1;

    for(int i = 1; i <= n && (k * i <= n + k - 1); i++){
        ll a = c(n + k - 1 - k * i + i, i), b = c(n, i);
        ans = sum(ans, _div(a, b));
    }

    cout << ans << "\n";
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = 1;
    for(int i = 1; i <= 3e5; i++){
        fact[i] = mul(fact[i - 1], i);
    }

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}