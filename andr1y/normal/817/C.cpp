#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200000
#define INF 101111111111111
using namespace std;
ll s;
bool check(ll n){
    ll on = n;
    ll sum = 0;
    while(n){
        sum+=n%10;
        n/=10;
    }
    return on-sum >= s;
}
main(){
    FAST;
    ll n;
    cin >> n >> s;
    ll l = 1, r = n;
    while(r -l > 1){
        ll m = (l+r)>>1;
        if(check(m)) r= m;
        else l = m;
    }
    ll xx = 0;
    if(check(l)) xx = l;
    else if(check(l+1)) xx = l+1;
    else if(check(r)) xx = r;
    else{
        cout << 0;
        exit(0);
    }
    cout << n-xx+1;
}