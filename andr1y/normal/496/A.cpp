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
ll a[N];
main(){
    FAST;
    ll n;
    cin >> n;
    ll last1 = -1, last2 = -1, mr=INF, mrp = 0;
    for(ll i = 0;i<n;i++){
        ll q;
        cin >> q;
        a[i] = q;
        if(i>1){
            if(q-last2 < mr){
                mrp = i;
                mr = q-last2;
            }
        }
        last2 = last1;
        last1 = q;
    }
    ll res = -INF;
    for(ll i = n-1;i>=1;i--){
        if(i == mrp){
            res = max(res, mr);
            i-=2;
        }
        if(i < 1) break;
        res = max(res, a[i]-a[i-1]);
    }
    cout << res;
}