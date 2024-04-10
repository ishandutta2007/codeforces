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
main(){
    FAST;
    ll n, t;
    cin >> n >> t;
    ll tc = 0, ot = t;
    while(ot){
        tc++;
        ot/=10;
    }
    if(tc > n) cout << -1;
    else{
        cout << t;
        for(ll i = 0;i<n-tc;i++) cout << 0;
    }
}