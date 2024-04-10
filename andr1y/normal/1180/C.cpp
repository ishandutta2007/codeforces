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
#define N 100000
#define INF 101111111111111
#define NINF -INF-1
#define F(i, n) for(ll i =0;i<n;i++)
using namespace std;
template<typename T, typename D> ostream& operator<<(ostream& os, const pair<T, D> V){return os << "(" << V.x << ";" << V.y << ")";}
template<typename T> ostream& operator<<(ostream& os, const vector<T> V){os << "array: " << endl; for(auto i:V)os << i << " "; return os << endl;}
template<typename T, size_t S> ostream& operator<<(ostream& os, const array<T, S> V){os << "vector: " << endl; for(auto i:V)os << i << " "; return os << endl;}
ll a[2*N];
ll d_s = 0, d_e = 0;
pll bef_stat[N+1];
main(){
    FAST;
    ll n, q;
    cin >> n >> q;
    ll fmaxv = 0, fmaxp = 0;
    for(ll i =0;i<n;i++){
        cin >> a[i]; d_e++;
        if(a[i] > fmaxv){
            fmaxv = a[i];
            fmaxp = i;
        }
    }
    for(ll C = 0;C<fmaxp;C++){
        d_s++;
        bef_stat[C+1] = {a[d_s-1], a[d_s]};
        if(a[d_s-1] > a[d_s]){
            a[d_e++] = a[d_s];
            a[d_s] = a[d_s-1];
        }else{
            a[d_e++] = a[d_s-1];
        }
    }
    for(ll Q = 0;Q<q;Q++){
        ll m;
        cin >> m;
        if(m <= fmaxp){
            cout << bef_stat[m].x << " " << bef_stat[m].y << endl;
        }else{
            cout << fmaxv << " " << a[d_s+1+(m - fmaxp - 1)%(n-1)] << endl;
        }
    }
}