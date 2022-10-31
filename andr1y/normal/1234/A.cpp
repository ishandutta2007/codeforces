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
#define N 1001
#define INF 101111111111111
using namespace std;
ll a[N];
main(){
    FAST;
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        ll s = 0;
        for(ll x, i = 0;i<n;i++){
            cin >> x;
            s+=x;
        }
        cout << s/n+(s%n == 0 ? 0 : 1) << endl;
    }
}