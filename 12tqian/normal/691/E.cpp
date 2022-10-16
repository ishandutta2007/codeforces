#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const int MAXN = 105;
static ll n = 1;
static ll adj[MAXN][MAXN];
void mult(ll a [MAXN][MAXN],ll b[MAXN][MAXN]){
    static ll c[MAXN][MAXN];
    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<n; j++){
            c[i][j] = 0;
            for(ll k = 0; k<n; k++){
                ll res = ((a[i][k])*(b[k][j]))%MOD;
                c[i][j] = (c[i][j] + res)%MOD;
            }
        }
    }
    for(ll i = 0; i<MAXN; i++){
        for(ll j = 0; j<MAXN; j++){
            a[i][j] = c[i][j];
        }
    }
}
bool xor3(ll a, ll b){
    ll x = a^b;
    ll n = __builtin_popcount (x);
    if(n%3 == 0){
        return true;
    }
    return false;

}
void binpow(ll a[MAXN][MAXN], ll k){
    static ll res [MAXN][MAXN];
    for(int i= 0; i<MAXN; i++){
        for(int j = 0; j<MAXN; j++){
            if(i == j){
                res[i][j] = 1;
            }
            else{
                res[i][j] = 0;
            }
        }
    }
    while(k>0){
        if(k%2 == 1){
            mult(res, a);
        }
        mult(a, a);
        k>>=1;
    }
    for(int i = 0; i<MAXN; i++){
        for(int j = 0; j<MAXN; j++){
            a[i][j] = res[i][j];
        }
    }
}

int main(){
    vector<ll> a;
    ll k;
    cin >> n;
    cin >> k;
    for(ll i = 0; i<n; i++){
        ll d;
        cin >> d;
        a.emplace_back(d);
    }
    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<n; j++){
            if(__builtin_popcountll(a[i]^a[j])%3 == 0){
                adj[i][j] = 1;
            }
        }
    }
    binpow(adj, k-1);
    ll ans = 0;
    for(ll i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            ans = ans%MOD+ adj[i][j]%MOD;
        //cout<< adj[i][j] << endl;
            ans = ans%MOD;

        }
    }
    cout << ans << endl;
    return 0;
}