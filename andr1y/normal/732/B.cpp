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
#define N 505
#define INF 101111111111111
using namespace std;
ll a[N], b[N], w[N];
main(){
    FAST;
    ll n, k;
    cin >> n >> k;
    for(ll i =0;i<n;i++){
        cin >> a[i];
        if(i>0) b[i] = b[i-1];
        b[i] += a[i];
    }
    ll add = 0;
    for(ll i = 1;i<n;i++){
        ll tb = b[i] - (i > 1 ? b[i-2] : 0) + w[i-1] - (i > 1 ? w[i-2] : 0);
        w[i] = w[i-1];
        if(tb < k){
            add += k-tb;
            w[i] += k-tb;
        }
    }
    cout << add << endl;
    for(ll i = 0;i<n;i++){
        cout << b[i] - (i > 0 ? b[i-1] : 0) + w[i] - (i > 0 ? w[i-1] : 0) << " ";
    }
}