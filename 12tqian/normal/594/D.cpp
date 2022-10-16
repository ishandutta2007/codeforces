#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

const double PI = 4 * atan(1);

#define sz(x) (int)(x).size()
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define vi vector<int>
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define vpi vector<pair<int, int>>
#define vpd vector<pair<double, double>>
#define pd pair<double, double>

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)
#define trav(a, x) for (auto& a : x)

void fast_io(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void io(string taskname){
    string fin = taskname + ".in";
    string fout = taskname + ".out";
    const char* FIN = fin.c_str();
    const char* FOUT = fout.c_str();
    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);
    fast_io();
}
const ll MOD = 1e9 +7;
const int MAX = 2e5 +5;
const int MAXC = 1e6+5;
ll a[MAX];
ll ans[MAX];
vpi queries[MAX];

template<class T, int SZ> struct Seg { // SZ should be power of 2
    T seg[2*SZ], ID = 1;

    Seg() { f0r(i, 2*SZ) seg[i] = 1; }
    T comb(T a, T b) { return (a*b)%MOD; }
    // easily change this to min or max
    // comb(ID,b) must equal b

    void upd(int p, T value, int flip) {  // set value at position p
        if(flip == 0){
            for (seg[p += SZ] *= value; p > 1; p >>= 1)
                seg[p>>1] = comb(seg[(p|1)^1],seg[p|1]);
        }
        else{
            if(value == 0)return;
            for (seg[p += SZ] /= value; p > 1; p >>= 1)
                seg[p>>1] = comb(seg[(p|1)^1],seg[p|1]);
        }
            // make sure non-commutative operations work
    }
    void upd(int p, T value) {  // set value at position p
        for (seg[p += SZ] = value; p > 1; p >>= 1)
            seg[p>>1] = comb(seg[(p|1)^1],seg[p|1]);
            // make sure non-commutative operations work
    }

    T query(int l, int r) {  // sum on interval [l, r]
        T res1 = ID, res2 = ID; r++;
        for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
            if (l&1) res1 = comb(res1,seg[l++]);
            if (r&1) res2 = comb(seg[--r],res2);
        }
        return comb(res1,res2);
    }
};
long long modInverse(long long b){
    long long ex = MOD - 2;
    if (b==1){
        return 1;
    }
    long long r = 1;
    while (ex ){
        if (ex&1){
            r=(r * b)%MOD;
        }
        ex = ex >> 1;
        b = (b * b)%MOD;
    }
    return r;
}


Seg<ll, (1<<18)> seg1;
Seg<ll, (1<<18)> seg2;
Seg<ll, (1<<18)> prod;

int spf[MAXC];

void sieve(){
    spf[1] = 1;
    for (int i=2; i<MAXC; i++)
        spf[i] = i;
    for (int i=4; i<MAXC; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXC; i++){
        if (spf[i] == i){
            for (int j=i*i; j<MAXC; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
vi primes;
unordered_map<int, int> um;
int loc[MAX];

void update(int i, int j, int p){
    if(loc[j] == i) return;
    if(loc[j] == -1){
        loc[j] = i;
      //  cout << p<< " " << i << " updating" << endl;
        seg1.upd(loc[j], p, 0);
        seg2.upd(loc[j], p-1, 0);
    }
    else{
        seg1.upd(loc[j], p, 1);
        seg2.upd(loc[j], p-1, 1);
        loc[j] = i;
        seg1.upd(loc[j], p, 0);
        seg2.upd(loc[j], p-1, 0);
    }
}
void change(int i){
    int x = a[i];
    while (x != 1){
        update(i, um[spf[x]], spf[x]);
        x = x / spf[x];
    }
}
int main(){
    fast_io();
    int n;
    cin >> n;
    f0r(i, n) cin >> a[i];
    f0r(i, n) prod.upd(i, a[i]);
    int q;
    cin >> q;
    f0r(i, q){
        int li, ri;
        cin >> li >> ri;
        li--; ri--;
        queries[li].eb(mp(ri, i));
    }
    sieve();
    f1r(i,2,  MAXC){
        if(spf[i] == i){
            primes.eb(i);
        }
    }
    int sz = sz(primes);
    f0r(i, sz) um[primes[i]] = i;
    f0r(i, sz) loc[i] = -1;
    for(int i = n-1; i>=0; i--){
      //  cout << a[i] << " primes: ";
        change(i);

      //  cout << endl;
        ///updated with left most primes
        for(auto query: queries[i]){
            int l = i;
            int r = query.f;
            ll product = prod.query(l, r);
            //cout << product << endl;
            product *= modInverse(seg1.query(l, r));
            product %= MOD;
            product *= seg2.query(l, r);
            product %= MOD;
            ans[query.s] = product;
        }
    }
    f0r(i, q) cout << ans[i] << endl;
    return 0;
}