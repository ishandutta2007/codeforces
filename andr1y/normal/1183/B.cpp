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
#define N 100
#define INF 101111111111111
#define NINF -INF-1
#define F(i, n) for(ll i =0;i<n;i++)
using namespace std;
template<typename T, typename D> ostream& operator<<(ostream& os, const pair<T, D> V){return os << "(" << V.x << ";" << V.y << ")";}
template<typename T> ostream& operator<<(ostream& os, const vector<T> V){os << "array: " << endl; for(auto i:V)os << i << " "; return os << endl;}
template<typename T, size_t S> ostream& operator<<(ostream& os, const array<T, S> V){os << "vector: " << endl; for(auto i:V)os << i << " "; return os << endl;}
ll a[N];
void solve(){
    ll n, k, maxn = 0, minn = INF;
    cin >> n >> k;
    for(ll i =0;i<n;i++){
        cin >> a[i];
        maxn = max(maxn, a[i]);
        minn = min(minn, a[i]);
    }
    if(maxn - minn > 2*k){
        cout << -1 << endl;
    }else{
        cout << minn + k << endl;
    }
}
main(){
    FAST;
    ll q;
    cin >> q;
    for(ll i =0;i<q;i++) solve();
}