#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 200005;
static ll mins[MAX][20];
static ll maxs [MAX][20];
static ll a[MAX];
static ll b[MAX];
static ll prevr[MAX];
static ll prevl[MAX];
ll rmin(ll l, ll r){
    ll j = floor(log2(r - l+1));
    if(mins[l][j] <= mins[r - (1<<j) + 1][j]){
        return mins[l][j];
    }
    return mins[r - (1<<j) + 1][j];
}
ll rmax(ll l, ll r){
    ll j = floor(log2(r - l+1));
    if(maxs[l][j] >= maxs[r - (1<<j) + 1][j]){
        return maxs[l][j];
    }
    return maxs[r - (1<<j) + 1][j];
}
ll binl(ll l, ll r, ll x, ll d){
    ll r1 = r;
    ll good = r;
    while(l<= r1){
        ll  m = l+ (r1- l)/2;
        if(d == 0){
            if(rmax(m, r) == x){
                r1 = m-1;
                good = min(good, m);
            }
            else{
                l = m + 1;
            }
        }
        else{
            if(rmin(m, r) == x){
                r1 = m-1;
                good = min(good, m);
            }
            else{
                l = m + 1;
            }
        }
    }
    return good;
}
ll rmq(ll l, ll r){
    return rmax(l, r) - rmin(l, r);
}
ll binr(ll l, ll r, ll x, ll d){
    ll l1 = l;
    ll good = l;
    while(l1<= r){
        ll  m = l1+ (r- l1)/2;
        if(d == 0){
            if(rmax(l, m) == x){
                l1 = m+1;
                good = max(good, m);
            }
            else{
                r = m-1;
            }
        }
        else{
            if(rmin(l, m) == x){
                l1 = m+1;
                good = max(good, m);
            }
            else{
                r = m-1;
            }
        }
    }
    return good;
}
int main(){
    ll n;
    cin >> n;
    for(ll i =0 ; i<n; i++){
        cin >> a[i];
    }
    for(ll i =0 ; i<n; i++){
        cin >> b[i];
    }

    for(ll i = 0; i<= log2(n); i++){
        for(ll x = 0; x<=n - (1<< i); x++){
            if(i == 0){
                maxs[x][i] =  a[x];
                continue;
            }
            maxs[x][i] = max(maxs[x][i-1], maxs[x+(1<<(i-1))][i-1]);
        }
    }
    for(ll i = 0; i<= log2(n); i++){
        for(ll x = 0; x<=n - (1<< i); x++){
            if(i == 0){
                mins[x][i] =  b[x];
                continue;
            }
            mins[x][i] = min(mins[x][i-1], mins[x+(1<<(i-1))][i-1]);
        }
    }
    ll ans = 0;
    for(ll i = 0; i<n; i++){
        if(rmq(i, i) > 0){
            continue;
        }
        ll l = i-1;
        ll r = i;
         for (ll p = 1 << (ll) log2(n-i+1); p; p >>= 1) {
            if (p + l < n && rmq(i,l+p) < 0){
                l += p;
            }
            if (p + r < n && rmq(i,r+p) <= 0) {
                r += p;
            }
        }
        ans += r - l;
    }
    cout << ans << endl;
    return 0;
}