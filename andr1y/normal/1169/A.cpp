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
#define NINF -INF-1
#define F(i, n) for(ll i =0;i<n;i++)
using namespace std;
template<typename T, typename D> ostream& operator<<(ostream& os, const pair<T, D> V){return os << "(" << V.x << ";" << V.y << ")";}
template<typename T> ostream& operator<<(ostream& os, const vector<T> V){os << "array: " << endl; for(auto i:V)os << i << " "; return os << endl;}
template<typename T, size_t S> ostream& operator<<(ostream& os, const array<T, S> V){os << "vector: " << endl; for(auto i:V)os << i << " "; return os << endl;}
main(){
    FAST;
    ll n, a, x, b, y;
    cin >> n >> a >> x >> b >> y;
    bool ca1 = 1, ca2 = 0, cb1 = 0, cb2 = 1;
    ll a1 = a, a2 = a, b1 = b, b2 = b;
    for(ll i = 1;i<=n;i++){
        a1++;
        if(a1 == n+1) a1 = 1;
        a2--;
        if(a2 == 0) a2 = n;
        b1++;
        if(b1 == n+1) b1 = 1;
        b2--;
        if(b2 == 0) b2 = n;
        if((a1 == b1 && ca1 && cb1) || (a2 == b1 && ca2 && cb1) || (a1 == b2 && ca1 && cb2) || (a2 == b2 && ca2 && cb2)){
            cout << "YES";
            exit(0);
        }
        if(a1 == x) ca1 = 0;
        if(a2 == x) ca2 = 0;
        if(b1 == y) cb1 = 0;
        if(b2 == y) cb2 = 0;
    }
    cout << "NO";
}