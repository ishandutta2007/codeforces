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
#define N 300001
#define INF 101111111111111
#define NINF -INF-1
#define F(i, n) for(ll i =0;i<n;i++)
using namespace std;
template<typename T, typename D> ostream& operator<<(ostream& os, const pair<T, D> V){return os << "" << V.x << " " << V.y << "";}
template<typename T> ostream& operator<<(ostream& os, const vector<T> V){os << "array: " << endl; for(auto i:V)os << i << " "; return os << endl;}
template<typename T, size_t S> ostream& operator<<(ostream& os, const array<T, S> V){os << "vector: " << endl; for(auto i:V)os << i << " "; return os << endl;}
ll a[N], p[N];
ll n;
vector<pll> swaps;
void oneswap(ll x, ll y){
    p[a[x]] = y;
    p[a[y]] = x;
    swap(a[x], a[y]);
    swaps.pb({x, y});
}
void mswap(ll x, ll y){
    if(x > y) swap(x, y);
    if(x <= n/2 && y > n/2){
        if(x!=1 && y!=n){
            oneswap(x, n);
            oneswap(1, y);
            oneswap(1, n);
            oneswap(1, y);
            oneswap(x, n);
        }else{
            oneswap(x, y);
        }

    }
    if(x > n/2 && y > n/2){
        oneswap(1, x);
        oneswap(1, y);
        oneswap(1, x);
    }
    if(x <= n/2 && y <= n/2){
        oneswap(n, x);
        oneswap(n, y);
        oneswap(n, x);
    }
}
main(){
    FAST;
    cin >> n;
    for(ll i =0 ;i<n;i++){
        cin >> a[i+1];
        p[a[i+1]] = i+1;
    }
    for(ll i = 1;i<=n;i++) if(i != p[i]) mswap(i, p[i]);
    cout << swaps.size() << endl;
    for(auto i : swaps) cout << i << endl;
    cout << endl;
    //for(ll i = 1;i<=n;i++) cout << a[i] << " ";
}