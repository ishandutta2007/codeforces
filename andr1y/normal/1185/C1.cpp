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
multiset<ll, greater<ll>> qq;
main(){
    FAST;
    ll n, m, asum = 0, t;
    cin >> n >> m;
    for(ll i =0;i<n;i++){
        cin >> t;
        asum += t;
        if(i > 0){
            ll cc = 0, cn = 0;
            if(asum <= m) cout << "0 ";
            else{
                for(auto j : qq){
                    cn += j;
                    cc++;
                    if(asum - cn <= m) break;
                }
                cout << cc << " ";
            }
        }else{
            cout << "0 ";
        }

        qq.insert(t);
    }
}