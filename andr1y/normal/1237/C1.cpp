#include <bits/stdc++.h>
#define ld long double
#define ll unsigned long long
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
#define N 2005
#define INF ULLONG_MAX
#define NINF -INF-1
#define F(i, n) for(ll i =0;i<n;i++)
using namespace std;
template<typename T, typename D> ostream& operator<<(ostream& os, const pair<T, D> V){return os << "(" << V.x << ";" << V.y << ")";}
template<typename T> ostream& operator<<(ostream& os, const vector<T> V){os << "array: " << endl; for(auto i:V)os << i << " "; return os << endl;}
template<typename T, size_t S> ostream& operator<<(ostream& os, const array<T, S> V){os << "vector: " << endl; for(auto i:V)os << i << " "; return os << endl;}
ll a[N], b[N], c[N];
ll n;
bool avia[N];
main(){
    FAST;
    ll n;
    cin >> n;
    for(ll i = 0;i<n;i++){
        cin >> a[i] >> b[i] >> c[i];
        avia[i] = true;
    }
    for(ll io  =0;io<n/2;io++){
        ll minv = INF;
        ll minp = 0;
        ll i = 0;
        while(!avia[i]) i++;
        if(i >= n) break;
        avia[i] = false;
        for(ll off = i;off<n;off++){
            while(!avia[off]) off++;
            if(off >= n) break;
            ll vp = (a[i]-a[off])*(a[i]-a[off])+(c[i]-c[off])*(c[i]-c[off])+(b[i]-b[off])*(b[i]-b[off]);
            if(vp < minv){
                minv = vp;
                minp = off;
            }
        }
        avia[minp] = false;
        cout << i+1 << " " << minp+1 << endl;
    }
}