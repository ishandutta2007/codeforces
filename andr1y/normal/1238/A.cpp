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
    ll t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        ll c = a - b;
        if(c == 1) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}