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
#define N 200000
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
ll n, k;
map<ll, ll> _count;
main(){
    FAST;
    cin >> n;
    for(ll i=0;i<n*n;i++){
        cin >> k;
        _count[k]++;
    }
    bool _err = false;
    ll center = 0;
    vector<ll> nmb;
    vector<ll> force_pdl;
    for(auto i : _count){
        //cout << i.x << " " << i.y << endl;
        if(i.y%4==1 && n%2 == 1){
            if(center != 0){
                _err = true;
                break;
            }
            center = i.x;
            i.y--;
            for(ll j = 0;j<i.y/4;j++) if(nmb.size() < (n/2)*(n/2)) nmb.pb(i.x); else force_pdl.pb(i.x), force_pdl.pb(i.x);
        }else if(i.y%4==2 && n%2==1){
            force_pdl.pb(i.x);
            i.y-=2;
            for(ll j = 0;j<i.y/4;j++) if(nmb.size() < (n/2)*(n/2)) nmb.pb(i.x); else force_pdl.pb(i.x), force_pdl.pb(i.x);
        }else if(i.y%4==3 && n%2==1){
            if(center != 0){
                _err = true;
                break;
            }
            center = i.x;
            force_pdl.pb(i.x);
            i.y-=3;
            for(ll j = 0;j<i.y/4;j++) if(nmb.size() < (n/2)*(n/2)) nmb.pb(i.x); else force_pdl.pb(i.x), force_pdl.pb(i.x);
        }else if(i.y%4!=0){
            _err = true;
            break;
        }else if(i.y%4==0){
            for(ll j = 0;j<i.y/4;j++) if(nmb.size() < (n/2)*(n/2)) nmb.pb(i.x); else force_pdl.pb(i.x), force_pdl.pb(i.x);
        }
    }
    if(!_err && ((n%2 == 1 && center!=0) || n%2 == 0) && ((n%2==0 && nmb.size() == (n/2)*(n/2) && force_pdl.size() == 0) || (n%2==1 && nmb.size() == (n/2)*(n/2) && force_pdl.size() == n-1))) cout << "YES" << endl;
    else{
        cout << "NO" << endl;
        exit(0);
    }
    if(n%2==0){
        for(ll i = 1;i<=n;i++){
            for(ll j = 1;j<=n;j++){
                ll offset = (i-1)*(n/2);
                if(i > n/2) offset = (n/2)*(n/2 - (i-1)%(n/2) - 1);
                if(j <= n/2) cout << nmb[offset+j-1];
                else cout << nmb[offset+(n/2-(j-n/2))];
                cout << " ";
            }
            cout << endl;
        }
    }else{
        for(ll i = 1;i<=n;i++){
            for(ll j = 1;j<=n;j++){
                ll offset = (i-1)*(n/2);
                if(i == (n/2 + 1)){
                    if(j == (n/2 + 1)) cout << center;
                    else{
                        if(j <= n/2) cout << force_pdl[(n/2)+j-1];
                        else if(j > n/2+1) cout << force_pdl[(n/2)+(n/2+1 - (j-n/2-1))-1];
                    }
                    cout << " ";
                    continue;
                }else if(j == (n/2 + 1)){
                    if(i <= n/2) cout << force_pdl[i-1];
                    else if(i > n/2+1) cout << force_pdl[(n/2+1 - (i-n/2-1))-1];
                    cout << " ";
                    continue;
                }
                if(i > n/2+1) offset = (n/2)*(n/2+1 - (i)%(n/2+1) - 1);
                if(j <= n/2) cout << nmb[offset+j-1];
                else if(j > n/2+1)cout << nmb[offset+(n/2+1-(j-n/2-1))-1];
                cout << " ";
            }
            cout << endl;
        }
    }
}