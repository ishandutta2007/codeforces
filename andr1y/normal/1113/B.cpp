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
#define N 50000
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
vector<ll> factorizate(ll on){
    vector<ll> res;
    ll i = 2, n = on;
    while(i*i<=on){
        if(n%i==0) res.pb(i);
        while(n%i==0){
            n/=i;
        }
        i++;
    }
    if(n>1) res.pb(n);
    return res;
}
vector<ll> factorizate2(ll on){
    vector<ll> res;
    ll i = 2, n = on;
    while(i*i<=on){
        while(n%i==0){
            n/=i;
            res.pb(i);
        }
        i++;
    }
    if(n>1) res.pb(n);
    return res;
}
vector<ll> get(ll m){
    vector<ll> x = factorizate2(m);
    vector<ll> res;
    /*res.pb(1);
    for(ll i = 0;i<20;i++){
        if(x.x[i]==0) break;
        else{
            for(ll k = 0;k<=x.y[i];k++){
                for(auto v : res){
                    if(k>0 && (m/(v*x.x[i]*k)>less_than)) res.pb(v*x.x[i]*k);
                }
            }
        }
    }*/
    /*ll sq = (ll)sqrt((double)m);
    ll s = 1, cc = 0;
    for(auto i : x){
        s*=i;
        cc++;
        if(s<=sq) res.pb(s);
        else break;
    }
    res.pb(res[res.size()-1]*x[cc]);*/
    vector<ll> res2;
    for(ll i = 0;i<(1 << x.size());i++){
        ll xc = 1, c = 0;
        while(c<x.size()){
            if((i>>c)%2==1) xc*=x[c];
            c++;
        }
        res2.pb(xc);
    }
    return res2;
}
ll a[N];
map<ll, ll> maxes_prime;
main(){
    FAST;
    ll n;
    cin >> n;
    ll minn = LLONG_MAX, k, sum = 0;
    for(ll i=0;i<n;i++){
        cin >> k;
        sum += k;
        minn = min(minn, k);
        /*for(auto i : factorizate(k)){
            maxes_prime[i] = max(maxes_prime[i], k);
        }*/
        a[i] = k;
    }
    ll min_add = INF;
    for(ll i = 0;i<n;i++){
        /*if(maxes_prime[i]>0){
            vector<ll> get2 = get(maxes_prime[i], minn);
            for(auto z : get2){
                ll adds = (z*minn + maxes_prime[i]/z - minn - maxes_prime[i]);
                if(z > 1) min_add = min(min_add, adds);
            }
        }*/
        vector<ll> get2 = get(a[i]);
        for(auto z : get2){
            ll adds = (z*minn + a[i]/z - minn - a[i]);
            if(z > 1) min_add = min(min_add, adds);
        }
    }
    if(min_add == INF) cout << sum;
    else cout << min(sum + min_add, sum);
}