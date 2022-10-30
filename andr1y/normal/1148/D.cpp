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
template<typename T, typename D> ostream& operator<<(ostream& os, const pair<T, D> V){return os << V.y;}
template<typename T> ostream& operator<<(ostream& os, const vector<T> V){for(auto i:V)os << i << " "; return os;}
template<typename T, size_t S> ostream& operator<<(ostream& os, const array<T, S> V){os << "vector: " << endl; for(auto i:V)os << i << " "; return os << endl;}
vector<pll> abb, amb;
bool cmp_abb(pll a, pll b){
    return a.x < b.x;
}
bool cmp_amb(pll a, pll b){
    return a.x > b.x;
}
main(){
    FAST;
    ll n;
    cin >> n;
    for(ll i = 0, a, b;i<n;i++){
        cin >> a >> b;
        if(a > b){
            abb.pb({a, i+1});
        }else{
            amb.pb({b, i+1});
        }
    }
    sort(itr(abb), cmp_abb);
    sort(itr(amb), cmp_amb);
    if(abb.size() > amb.size()){
        cout << abb.size() << endl << abb << endl;
    }else{
        cout << amb.size() << endl << amb << endl;
    }
}