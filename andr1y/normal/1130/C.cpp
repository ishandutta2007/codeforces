#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define pp(a, b) pb(mp(a, b))
#define get_bit(n, k) n&(1<<k)
#define endl '\n'
#define vl vector<ll>
#define PI 3.1415926535897932384626433832795
#define rad(deg) deg*PI/180
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 50
#define INF LLONG_MAX
#define NINF -INF-1
#define PAIR_OUT_PRE "("
#define PAIR_OUT_BTW ";"
#define PAIR_OUT_PST "), "
#define ARRAY_OUT_PRE "data: "
#define ARRAY_OUT_BTW ", "
#define ARRAY_OUT_PST endl
using namespace std;
template<typename T, typename D> ostream& operator<<(ostream& os, const pair<T, D> V){return os << PAIR_OUT_PRE << V.x << PAIR_OUT_BTW << V.y << PAIR_OUT_PST;}
template<typename T> ostream& operator<<(ostream& os, const vector<T> V){os << ARRAY_OUT_PRE; for(auto i:V)os << i << ARRAY_OUT_BTW; return os << ARRAY_OUT_PST;}
template<typename T, size_t S> ostream& operator<<(ostream& os, const array<T, S> V){os << ARRAY_OUT_PRE; for(auto i:V)os << i << ARRAY_OUT_BTW; return os << ARRAY_OUT_PST;}
/*--func--*/
template<typename T> ull fast_log(T a){ull c = 0;while((a>>(++c)) > 0);return c-1;}
ll P[N*N];
ll colors[N][N];
ll snm_find(ll n){
    if(n == P[n]) return n;
    else return P[n] = snm_find(P[n]);
}
void snm_union(ll a, ll b){
    a = snm_find(a);
    b = snm_find(b);
    if(a==b) return;
    P[a] = b;
}
ll col_c = 1;
ll orig[N][N];
vector<pll> d;
main(){
    FAST;
    ll n;
    cin >> n;
    pll c1, c2;
    cin >> c1.x >> c1.y >> c2.x >> c2.y;
    for(ll i =0;i<n;i++){
        for(ll j=0;j<n;j++){
            char c;
            cin >> c;
            ll cc = c-'0';
            orig[i][j] = cc;
            if(cc == 0){
                d.pp(i, j);
                bool unioned = false;
                if(i>0 && orig[i-1][j] == 0){
                    colors[i][j] = colors[i-1][j];
                    unioned = true;
                }
                if(j>0 && orig[i][j-1]==0){
                    if(unioned)snm_union(colors[i-1][j], colors[i][j-1]);
                    colors[i][j] = colors[i][j-1];
                    unioned = true;
                }
                if(!unioned) colors[i][j] = col_c, P[col_c] = col_c++;
            }
        }
    }
    ll col1 = snm_find(colors[c1.x-1][c1.y-1]);
    ll col2 = snm_find(colors[c2.x-1][c2.y-1]);
    ll minn = INF;
    if(col1 == col2){
        cout << 0 << endl;
    }else{
        for(auto i : d){
            for(auto j : d){
                ll cl1 = snm_find(colors[i.x][i.y]);
                ll cl2 = snm_find(colors[j.x][j.y]);
                if(cl1 == col1 && cl2 == col2){
                    minn = min(minn, (i.x-j.x)*(i.x-j.x) + (i.y-j.y)*(i.y-j.y));
                }
            }
        }
        cout << minn;
    }
}